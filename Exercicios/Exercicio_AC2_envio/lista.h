#ifndef LISTA_H
#define LISTA_H

// A mochila guarda valores financeiros (os tesouros encontrados)
typedef struct no_lista {
  int info;
  struct no_lista *prox;
} No_lista;

typedef No_lista* Lista;

// Protótipos das funções
void cria_lista(Lista *p_l);
int lista_vazia(Lista *p_l);
void insere_ordenado(Lista *p_l, int valor);
int remove_primeiro(Lista *p_l, int *valor_removido);
void exibe_lista(Lista *p_l);
void libera_lista(Lista *p_l);

#endif