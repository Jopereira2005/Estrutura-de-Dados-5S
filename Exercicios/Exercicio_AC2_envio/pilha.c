#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Inicializa a pilha vazia
void cria_pilha(Pilha *p_p) {
  *p_p = NULL;
}

// Verifica se a pilha está vazia
int pilha_vazia(Pilha *p_p) {
  return *p_p == NULL;
}

// Empilha(Push) - Insere sempre no topo da pilha
void empilha(Pilha *p_p, Posicao p) {
  No_pilha *novo = (No_pilha*) malloc(sizeof(No_pilha));
  if (novo == NULL) {
    printf("Erro ao alocar memoria na pilha!\n");
    return;
  }
  
  novo->pos = p;
  novo->prox = *p_p; // O novo no aponta para o antigo topo
  *p_p = novo;       // O novo no se torna o novo topo da pilha
}

// Desempilha(Pop) - Remove sempre do topo da pilha
int desempilha(Pilha *p_p, Posicao *p_removida) {
  if (pilha_vazia(p_p)) {
    return 0; // Pilha vazia
  }

  No_pilha *aux = *p_p;
  // Salva o endereço que esta sendo desfeito para o backtracking
  *p_removida = aux->pos; 
  
  *p_p = aux->prox; // O topo desce para o elemento debaixo
  free(aux);        // Libera a memoria do passo desfeito
  return 1;
}

// Limpa todos os passos salvos
void libera_pilha(Pilha *p_p) {
  No_pilha *aux = *p_p;
  No_pilha *prox_no;
  while (aux != NULL) {
    prox_no = aux->prox;
    free(aux);
    aux = prox_no;
  }
  *p_p = NULL;
}