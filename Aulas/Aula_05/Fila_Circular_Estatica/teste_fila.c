#include <stdio.h>
#include "./fila_circular_estatica.h"

int main() {
  Fila fila;
  int aux, count = 0;

  inicializa(&fila);

  enfileira(&fila, 10);
  enfileira(&fila, -20);
  enfileira(&fila, 30);
  enfileira(&fila, -40);
  enfileira(&fila, 50);
  enfileira(&fila, -60);
  enfileira(&fila, -70);
  enfileira(&fila, 80);

  for(int i = 0; i < count; i++) {
    desenfileira(&fila, &aux);

    if(aux >= 0) 
      enfileira(&fila, aux);
  }

  printf("Fila sem os valores negativos: ");

  while(!vazia(&fila)) {
    desenfileira(&fila, &aux);
    printf("[%i] ", aux);
  }
}