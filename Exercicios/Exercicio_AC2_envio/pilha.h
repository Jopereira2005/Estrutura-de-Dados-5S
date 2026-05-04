#ifndef PILHA_H
#define PILHA_H

// Estrutura para guardar as coordenadas da matriz
typedef struct posicao {
  int x; // Linha
  int y; // Coluna
} Posicao;

// Estrutura do nó da pilha, que guarda a posição e o ponteiro para o próximo nó
typedef struct no_pilha {
  Posicao pos;
  struct no_pilha *prox;
} No_pilha;

// Ponteiro para o topo da pilha
typedef No_pilha* Pilha;

// Protótipos das funções
void cria_pilha(Pilha *p_p);
int pilha_vazia(Pilha *p_p);
void empilha(Pilha *p_p, Posicao p);
int desempilha(Pilha *p_p, Posicao *p_removida);
void libera_pilha(Pilha *p_p);

#endif