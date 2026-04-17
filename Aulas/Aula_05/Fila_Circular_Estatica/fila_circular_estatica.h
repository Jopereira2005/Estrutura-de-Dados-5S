// Fila Circular Estática

#define MAX 50

typedef int elem_t;
typedef struct f {
  elem_t vet[MAX];
  int ini, fim, tam;
} Fila;

void inicializa(Fila *p_f);

int vazia(Fila *p_f);

int cheia(Fila *p_f);

int enfileira(Fila *p_f, elem_t e);

int desenfileira(Fila *p_f, elem_t *saida);

int primeiro_posicao(Fila *p_f, elem_t *saida);

int tamanho(Fila *p_f);

void libera(Fila *p_f);



