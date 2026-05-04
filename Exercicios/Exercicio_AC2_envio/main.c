#include <stdio.h>
#include <stdlib.h>

// Para o rand() e srand()
#include <time.h>

// Para o Sleep(), system("cls") e system("pause")
#include <windows.h> 

#include "lista.h"
#include "pilha.h"
#include "mapa.h"

void salva_caminho(Pilha *caminho_final, Mapa *labirinto) {
  FILE *arquivo = fopen("saida.txt", "w");
  if (arquivo == NULL) {
    printf("Erro ao criar o arquivo de saida!\n");
    return;
  }

  // Pilha auxiliar para inverter a ordem (de LIFO para FIFO)
  Pilha pilha_invertida;
  cria_pilha(&pilha_invertida);
  Posicao p;

  while (!pilha_vazia(caminho_final)) {
    // Desempilha da pilha original e empilha na pilha auxiliar usando a variável 'p' para guardar a posição removida
    desempilha(caminho_final, &p);
    empilha(&pilha_invertida, p);
  }

  fprintf(arquivo, "--- Caminho Correto para a Saida ---\n");
  int passo = 1;
  
  // Variáveis para guardar as pontas do caminho
  Posicao inicio_caminho;
  Posicao fim_caminho;
  int primeiro_passo = 1;
  
  while (!pilha_vazia(&pilha_invertida)) {
    desempilha(&pilha_invertida, &p);
    fprintf(arquivo, "Passo %i: [%i, %i]\n", passo++, p.x, p.y);
    
    // Identifica quem é o 'P' e quem é o 'S'
    if (primeiro_passo) {
      inicio_caminho = p;
      primeiro_passo = 0;
    }
    fim_caminho = p; // Vai atualizando até o loop terminar no último passo (A Saída)

    // Preenche TODO o caminho com '*'
    labirinto->local[p.x][p.y] = '*';
  }
  fprintf(arquivo, "------------------------------------\n\n");

  // Força o Início e a Saída a aparecerem nas pontas do caminho!
  labirinto->local[inicio_caminho.x][inicio_caminho.y] = 'P';
  labirinto->local[fim_caminho.x][fim_caminho.y] = 'S';

  // Grava o desenho do mapa no arquivo!
  fprintf(arquivo, "--- Desenho do Labirinto ---\n");
  for (int i = 0; i < labirinto->linhas; i++) {
    for (int j = 0; j < labirinto->colunas; j++) {
      char c = labirinto->local[i][j];
      
      // Imprime APENAS a parede, o início, o caminho e a SAÍDA.
      if (c == '#' || c == 'P' || c == '*' || c == 'S') {
        fprintf(arquivo, "%c", c);
      } else {
        fprintf(arquivo, " "); // O resto vira espaço vazio
      }
    }
    fprintf(arquivo, "\n");
  }
  fprintf(arquivo, "----------------------------\n");

  fclose(arquivo);
  printf("\nCaminho e mapa salvos com sucesso em 'saida.txt'!\n");
}

int main() {
  srand(time(NULL));

  Mapa labirinto;
  Lista mochila;
  Pilha navegador;

  cria_lista(&mochila);
  cria_pilha(&navegador);

  // Carrega o Mapa
  if (!carrega_mapa(&labirinto, "layout.txt")) {
    return 1;
  }

  Posicao atual; // Váriável para guardar a posição atual do explorador
  Posicao inicio; // Variável nova para guardar onde o 'P' deve ficar
  int achou_inicio = 0;
  
  for (int i = 0; i < labirinto.linhas; i++) {
    for (int j = 0; j < labirinto.colunas; j++) {
      if (labirinto.local[i][j] == 'P') {
        atual.x = i;
        atual.y = j;
        inicio = atual; // Salva a coordenada de 'P'
        achou_inicio = 1;
        break;
      }
    }
  }

  if (!achou_inicio) {
    printf("Erro: Origem 'P' nao encontrada no mapa!\n");
    return 1;
  }

  // O Menu de Controle
  int modo_jogo = 1;
  printf("\n--- O LABIRINTO DE DADOS ---\n");
  printf("Escolha o modo de visualizacao:\n");
  printf("[1] Jogo Corrido (Animacao Automatica)\n");
  printf("[2] Passo a Passo (Pressione qualquer tecla para andar)\n");
  printf("Opcao: ");
  scanf("%i", &modo_jogo);

  // Inicia o navegador com a posição inicial do 'P'
  empilha(&navegador, atual);

  int achou_saida = 0;
  int tesouro_perdido;
  // Valores para serem somados a posição atual
  // Soma para observar os 4 lados (cima, baixo, esquerda, direita)
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  //  Loop Principal - Motor de Backtracking
  while (!pilha_vazia(&navegador) && !achou_saida) {
    
    // Lê o chão antes de desenhar o "avatar" do explorador
    char no_chao = labirinto.local[atual.x][atual.y];
    
    // O avatar do explorador agora é o '0'
    labirinto.local[atual.x][atual.y] = '0'; 

    system("cls");
    imprime_mapa(&labirinto);
    exibe_lista(&mochila);

    // Processa os eventos baseados no que lemos do chão
    if (no_chao == 'S') {
      achou_saida = 1;
      printf("\nParabens! Voce encontrou a saida!\n");
      break; 
    } 
    else if (no_chao == 'T') {
      int valor = (rand() % 100) + 1; 
      printf("Voce encontrou um tesouro que contem %i moedas!\n", valor);
      insere_ordenado(&mochila, valor);
    } 
    else if (no_chao == 'A') {
      printf("CUIDADO! ARMADILHA!\n");
      if (remove_primeiro(&mochila, &tesouro_perdido)) {
        printf("Voce perdeu o tesouro de menor valor: -%i moedas.\n", tesouro_perdido);
      } else {
        printf("A armadilha te pegou, mas sua mochila ja estava vazia!\n");
      }
    }

    // Menu: Pausado ou Corrido
    if (modo_jogo == 2) {
      printf("\n");
      system("pause"); 
    } else {
      Sleep(500); 
    }

    // Para o P ficar estático no labirinto. Ao sair da casa, decide se devolve o 'P' ou marca como visitado '.'
    if (atual.x == inicio.x && atual.y == inicio.y) {
      labirinto.local[atual.x][atual.y] = 'P'; // Restaura o P na base
    } else {
      labirinto.local[atual.x][atual.y] = '.'; // Marca caminho visitado
    }

    // Tenta andar para uma nova encruzilhada 
    int andou = 0;
    int maior_prioridade = 0;
    int melhor_nx = -1, melhor_ny = -1; // começa com -1 porque coordenadas válidas são >= 0

    // O explorador olha para os 4 lados primeiro
    for (int i = 0; i < 4; i++) {
      int nx = atual.x + dx[i];
      int ny = atual.y + dy[i];

      // Verifica se está dentro do mapa
      if (nx >= 0 && nx < labirinto.linhas && ny >= 0 && ny < labirinto.colunas) {
        char destino = labirinto.local[nx][ny];
        
        int prioridade_atual = 0; // Nota da casa avaliada

        // Avalia o que tem no chão e dá a nota
        if (destino == 'S') prioridade_atual = 4; // Fim de jogo!
        else if (destino == 'T') prioridade_atual = 3; // Tesouro!
        else if (destino == ' ') prioridade_atual = 2; // Seguro
        else if (destino == 'A') prioridade_atual = 1; // Perigo, mas andável se for a única opção
        
        // Se a casa atual for melhor do que a melhor que ele já tinha visto, ele muda de ideia!
        if (prioridade_atual > maior_prioridade) {
          // Salva o meelhor caminho encontrado até agora
          maior_prioridade = prioridade_atual;
          melhor_nx = nx;
          melhor_ny = ny;
        }
      }
    }

    // Se ele achou pelo menos um caminho válido (maior_prioridade > 0), ele vai pra lá
    if (maior_prioridade != 0) {
      atual.x = melhor_nx;
      atual.y = melhor_ny;
      empilha(&navegador, atual);
      andou = 1; 
    }

    // Backtracking, se ele não andou para lugar nenhum, ele volta um passo e tenta de novo
    if (!andou) {
      Posicao p_removida;
      desempilha(&navegador, &p_removida); 
      
      if (!pilha_vazia(&navegador)) {
        // Volta o navegador para a posição o toppo da pilha
        Pilha topo = navegador;
        // Define a posição atual para o topo da pilha
        atual = topo->pos;
      }
    }
  }

  // Finalização e Pontuação
  if (achou_saida) {
    salva_caminho(&navegador, &labirinto);
    
    int pontuacao = 0;
    No_lista *aux = mochila;
    while (aux != NULL) {
      pontuacao += aux->info;
      aux = aux->prox;
    }
    printf("Pontuacao Final: %i moedas!\n", pontuacao);
  } else {
    printf("\nFim de jogo: O explorador ficou preso no labirinto!\n");
  }

  // Libera a memória alocada para a mochila e o navegador
  libera_lista(&mochila);
  libera_pilha(&navegador);

  return 0;
}