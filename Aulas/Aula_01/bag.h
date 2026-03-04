/*
* bag.h - definicao das operacoes realizadas na sacola
* Autora: Tiemi C. Sakata
*/

#define BAGSIZE 50

typedef struct b {
  int item[BAGSIZE];
} Bag;

// Inicializa a Bag vazia
void init(Bag *b);

// Retorna o numero de itens na Bag
int size(Bag *b);

// Insere um elemento na Bag. Retorna 1 para insercao com sucesso ou 0 para Bag cheia.
int insert(Bag *b, int elem);

// Verifica quantas vezes o elemento elem esta na Bag
int check(Bag *b, int elem);

// Remove o elemento elem da Bag. Retorna 1 se a remocao ocorreu com sucesso ou 0 se o elemento nao foi encontrado na Bag.
int delete(Bag *b, int elem);

// Imprime todos os elementos da Bag
void printall(Bag b);
