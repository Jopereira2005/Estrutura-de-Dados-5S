#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Inicializa a lista vazia
void cria_lista(Lista *p_l) {
  *p_l = NULL;
}

// Verifica se a lista está vazia
int lista_vazia(Lista *p_l) {
  return *p_l == NULL;
}

// Insere um elemento de forma ordenada (crescente)
void insere_ordenado(Lista *p_l, int valor) {
  No_lista *novo = (No_lista*) malloc(sizeof(No_lista));
  if (novo == NULL) {
    printf("Erro ao alocar memoria na lista!\n");
    return;
  }

  novo->info = valor;

  // Verifica se a lista está vazia ou se o novo valor é o menor de todos
  if(lista_vazia(p_l) || (*p_l)->info >= valor) {
    novo->prox = *p_l;
    *p_l = novo;
    return;
  }

  // Procura a posicao correta no meio ou fim
  No_lista *aux = *p_l;
  // Avanca enquanto o proximo existir e for menor que o novo valor
  while (aux->prox != NULL && aux->prox->info < valor) {
    aux = aux->prox;
  }

  novo->prox = aux->prox; // O novo aponta para o maior que ele
  aux->prox = novo; // O atual aponta para o novo
}

// Remove o primeiro elemento
int remove_primeiro(Lista *p_l, int *valor_removido) {
  if (lista_vazia(p_l)) {
    return 0;
  }

  No_lista *aux = *p_l;
  // Salva o valor para avisar o jogador
  *valor_removido = aux->info; 
  
  // O inicio da lista passa a ser o segundo elemento
  *p_l = aux->prox; 
  free(aux); // Libera o no da memoria
  return 1;
}

// Imprime a lista no console
void exibe_lista(Lista *p_l) {
  if (lista_vazia(p_l)) {
    printf("Lista vazia.\n");
    return;
  }

  No_lista *aux = *p_l;
  printf("Mochila: ");
  while (aux != NULL) {
    printf("[%i] ", aux->info);
    aux = aux->prox;
  }
  printf("\n");
}

// Esvazia a lista e limpa a memoria no fim do jogo
void libera_lista(Lista *p_l) {
  No_lista *aux = *p_l;
  No_lista *prox_no;
  while (aux != NULL) {
    prox_no = aux->prox; // Salva o endereco do proximo
    free(aux);           // Destroi o atual
    aux = prox_no;       // Avanca
  }
  *p_l = NULL;
}