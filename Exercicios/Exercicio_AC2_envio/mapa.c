#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

// Retorna 1 se sucesso, 0 se falha
int carrega_mapa(Mapa *m, const char *caminho_arquivo) {
  // Abre o arquivo no modo leitura ("r" - read)
  FILE *arquivo = fopen(caminho_arquivo, "r");
  
  if (arquivo == NULL) {
    printf("Erro crítico: Nao foi possivel abrir o arquivo %s!\n", caminho_arquivo);
    return 0;
  }

  // Le as dimensoes na primeira linha (ex: 10x10 ou 10X10)
  // fscanf lê a primeira linha do código
  // O %*[xX] é um truque que diz ao C para ler a letra 'x' (seja maiúscula ou minúscula).
  if (fscanf(arquivo, "%i%*[xX]%i", &m->colunas, &m->linhas) != 2) {
    printf("Erro: Formato de dimensao invalido no txt.\n");
    fclose(arquivo);
    return 0;
  }

  // Consome a quebra de linha (\n) que ficou sobrando apos o fscanf
  fgetc(arquivo); 

  // Varre o arquivo lendo os caracteres do labirinto
  for (int i = 0; i < m->linhas; i++) {
    for (int j = 0; j < m->colunas; j++) {
      char c = fgetc(arquivo);
      
      // Ignora quebras de linha no meio da leitura
      if (c == '\n') {
        c = fgetc(arquivo);
      }
      
      m->local[i][j] = c;
    }
  }

  fclose(arquivo);
  return 1;
}

// Imprime a matriz no console
void imprime_mapa(Mapa *m) {
  printf("\n--- Mapa do Labirinto ---\n");
  for (int i = 0; i < m->linhas; i++) {
    for (int j = 0; j < m->colunas; j++) {
      printf("%c", m->local[i][j]);
    }
    printf("\n");
  }
  printf("-------------------------\n");
}