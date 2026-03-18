#include <stdio.h>
#include "./lista_estatica.h"


/* Inicializa uma lista */
void cria(Lista *p_l) {
  p_l->tam = 0;
  for(int i = 0; i < MAX; i++) {
    p_l->vet[i] = -1;
  }
}

/* Verifica se a lista est� vazia ou nao */
int vazia(Lista *p_l) {
  if(p_l->tam == 0) 
    return 1;
  
  return 0; 
}

/* Insere um elemento no inicio da lista */
void insere_inicio(Lista *p_l, elem_t e) {
  if(p_l->tam == MAX) {
    printf("Lista cheia");
    return;
  }
  
  if(vazia(p_l)) {
    p_l->vet[0] = e;
    p_l->tam++;
  } else {
    for(int i = (p_l->tam - 1); i >= 0; i--) {
     p_l->vet[i + 1] = p_l->vet[i];  
    }
 
    p_l->vet[0] = e;
    p_l->tam++;
  }
}

/* Insere um elemento no final da lista */
void insere_fim(Lista *p_l, elem_t e) {
  if(p_l->tam == MAX) {
    printf("Lista cheia");
    return;
  }

  p_l->tam++;
  p_l->vet[p_l->tam - 1] = e;
}

/* Insere um elemento na lista de maneira ordenada.
  Retorna 0 caso o elemento ja exista na lista. 
  Assume que a lista esta ordenada */
int insere_ordenado(Lista *p_l, elem_t e) {
  int i;
  if(p_l->tam == MAX)
    return 0;
  
  for(i = 0; i < p_l->tam; i++) {
    if(p_l->vet[i] == e) {
      return 0;
    }

    if(p_l->vet[i] > e) {
      break;
    }
  }

  for(int j = p_l->tam; j > i; j--) {
    p_l->vet[j] = p_l->vet[j - 1];
  }

  p_l->vet[i] = e;
  p_l->tam++;
  return 1;
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l) {
  for(int i = 0; i < p_l->tam - 1; i++) {
    if(p_l->vet[i] > p_l->vet[i + 1]) {
    	return 0;
    }
  }
  return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l) {
  int aux, troca;

  if(p_l->tam == 0) {
    printf("\nLista vazia");
    return;
  }

  if(ordenada(p_l)) {
    printf("\nA lista esta ordenada");
    return;
  }

  for(int i = 0; i < p_l->tam - 1; i++) {
    troca = 0;
    for(int j = 0; j < p_l->tam - 1 - i; j++) {
      if(p_l->vet[j] > p_l->vet[j + 1]) {
        aux = p_l->vet[j];
        p_l->vet[j] = p_l->vet[j + 1];
        p_l->vet[j + 1] = aux;
        troca = 1;
      }
    }
    if(!troca) {
      break;
    }
  }
  printf("\nA lista foi ordenada!");
}

/* Remove o elemento que esta no inicio da lista.
  Retorna 0 caso a lista esteja vazia */
int remove_inicio(Lista *p_l) {
  if(p_l->tam == 0)
    return 0;
  
  p_l->tam--;
  for(int i = 0; i < p_l->tam; i++) {
    p_l->vet[i] = p_l->vet[i + 1];  
    p_l->vet[i + 1] = -1;
  }
  
  return 1;
}

/* Remove o elemento que esta no final da lista.
  Retorna 0 caso a lista esteja vazia */
int remove_fim(Lista *p_l) {
  if(p_l->tam == 0)
    return 0;

  p_l->tam--;
  p_l->vet[p_l->tam] = -1;
  return 1;
}

/* Remove o numero de valor e.
  Retorna 0 caso este numero n�o tenha sido encontrado */
int remove_valor(Lista *p_l, elem_t e) {
  if(p_l->tam == 0)
    return 0;

  for(int i = 0; i < p_l->tam; i++) {
    if(p_l->vet[i] == e) {
      for(int j = i; j < p_l->tam - 1; j++) {
        p_l->vet[j] = p_l->vet[j + 1];
      }

      p_l->vet[p_l->tam - 1] = -1;
      p_l->tam--;
      return 1;
    }
  }

  return 0;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l) {
  int aux;
  int tam_div = p_l->tam/2;

  if(p_l->tam == 0) {
    printf("Lista vazia");
    return;
  }

  for(int i = 0; i < tam_div; i++) {
    aux = p_l->vet[i];
    p_l->vet[i] = p_l->vet[p_l->tam - 1 - i];
    p_l->vet[p_l->tam - 1 - i] = aux;
  }
}

/* Remove todos os numeros da lista */
void libera(Lista *p_l) {

  for(int i = 0; i < p_l->tam - 1; i++) {
    p_l->vet[i] = -1;
  }
  p_l->tam = 0;
}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l) {
  if(vazia(p_l)) {
    printf("Lista vazia");
    return;
  }

  printf("Elementos da lista: ");
  for(int i = 0; i < p_l->tam; i++) {
    printf("[%i] ", p_l->vet[i]);
  }
  printf("\nTamanho da lista: %i", p_l->tam);
}
