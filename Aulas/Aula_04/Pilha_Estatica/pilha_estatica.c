#include<stdio.h>
#include<stdlib.h>
#include "pilha_estatica.h"

/***********************************************************
Definicao das funcoes sobre pilhas
************************************************************/

/*Inicializa a pilha*/
void cria_pilha(Pilha *ps) {
  ps->topo = -1;
}

/*Verifica se a pilha esta' vazia*/
int pilha_vazia(Pilha *ps) {
 if (ps->topo == -1)
   return 1;
 else
   return 0;
}

/*Verifica se a pilha esta' cheia*/
int pilha_cheia(Pilha *ps) {
  if (ps->topo == MAXPILHA - 1)
    return 1;
  else
    return 0;
}

/*Adiciona um item na pilha*/
int insere_pilha(Pilha *ps, elem_t x) {
	if (pilha_cheia(ps) == 1) {
    return -1;
 	} else {
		return (ps->item[++(ps->topo)] = x);
	}
}

/*Remove um item da pilha e retorna-o*/
elem_t remove_pilha(Pilha *ps) {
	if (pilha_vazia(ps)==1) {
		return -1;
 	} else {
		return ps->item[ps->topo--];
 	}
}

/*Remove todos os elementos da Pilha*/
void libera_pilha(Pilha *ps){
  ps->topo = -1;
}

/*Retorna o ultimo item da pilha*/
elem_t elem_topo(Pilha *ps) {
	if (pilha_vazia(ps)==1) {
		return -1;
	} else {
		return ps->item[ps->topo];
	}
}

void exibe_pilha(Pilha *ps) {
	if (pilha_vazia(ps)) {
		printf("Pilha Vazia");
	} else {
		printf("Pilha: ");
		for (int i = ps->topo; i >= 0; i--) {
			printf("[%i] ", ps->item[i]);
		}
	}
}