#include <stdio.h>
#include "./bag.h"

// Inicializa a Bag vazia
void init(Bag *b) {
  for (int i = 0; i < BAGSIZE; i++) {
    b->item[i] = -1;
  }
}

// Retorna o numero de itens na Bag
int size(Bag *b){
  int count = 0;
  for (int i = 0; i < BAGSIZE; i++) {
    if (b->item[i] != -1) {
      count++;
    }
  }
  return count;
}

// Insere um elemento na Bag. Retorna 1 para insercao com sucesso ou 0 para Bag cheia.
int insert(Bag *b, int elem) {
  int size_bag = size(b);
  
  if (size_bag < BAGSIZE) {
    for(int i = 0; i < BAGSIZE; i++) {
      if(b->item[i] == -1) {
        b->item[i] = elem;
        return 1;
      }
    }
  }

  return 0;
}

// Verifica quantas vezes o elemento elem esta na Bag
int check(Bag *b, int elem) {
  int size_bag = size(b), count = 0;

  for(int i = 0; i < size_bag; i++) {
    if(elem >= 0) {
      if(elem == b->item[i]) {
        count++;
      }
    }
  }

  return count;
}

// Remove o elemento elem da Bag. Retorna 1 se a remocao ocorreu com sucesso ou 0 se o elemento nao foi encontrado na Bag.
int delete(Bag *b, int elem) {
  int size_bag = size(b), count = 0;

  for(int i = 0; i < size_bag; i++) {
    if(elem >= 0) {
      if(elem == b->item[i]) {
        b->item[i] = -1;

        return 1;
      }
    }
  }

  return 0;
}

// Imprime todos os elementos da Bag
void printall(Bag b) {
  int size_bag = size(&b), count = 0;

  for(int i = 0; i < size_bag; i++) {
    if(b.item[i] != -1) {
      printf("[%i] ", b.item[i]);
    }
  }
}
