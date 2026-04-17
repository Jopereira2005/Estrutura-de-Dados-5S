#include <stdio.h>
#include "./fila_circular_estatica.h"

void inicializa(Fila *p_f) {
  p_f->ini = 0;
  p_f->fim = -1;
  p_f->tam = 0;
}

int vazia(Fila *p_f) {
  if(p_f->tam == 0)
    return 1;

  return 0;
}

int cheia(Fila *p_f) {
  if(p_f->tam == MAX)
    return 1;

  return 0;
}

int enfileira(Fila *p_f, elem_t e) {
  if(cheia(p_f))
    return 0;

  // caso chegue no fim do vetor, retorna para o indice inicial
  p_f->fim = (p_f->fim + 1) % MAX;

  p_f->vet[p_f->fim] = e;
  p_f->tam++;
  return 1;
}

int desenfileira(Fila *p_f, elem_t *saida) {
  if(vazia(p_f)) 
    return 0;

  *saida = p_f->vet[p_f->ini];

  p_f->ini = (p_f->ini + 1) % MAX;
  p_f->tam--;
  return 1;
}

int primeiro_posicao(Fila *p_f, elem_t *saida) {
  if(vazia(p_f))
    return 0;
  
  *saida = p_f->vet[p_f->ini];
  return 1;
}

int tamanho(Fila *p_f) {
  return p_f->tam;
}

void libera(Fila *p_f) {
  inicializa(p_f);
}



