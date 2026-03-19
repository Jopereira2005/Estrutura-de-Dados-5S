#include <stdio.h>
#include <stdlib.h>
#include "./lista_dupla_dinamica.h"

/* Inicializa uma lista */
void cria(Lista *p_l) {
  *p_l = NULL;
}

/* Verifica se a lista está vazia ou não */
int vazia(Lista *p_l) {
  return *p_l == NULL;
}

/* Insere um elemento no início da lista */
void insere_inicio(Lista *p_l, elem_t e) {
  No_lista *novo;

  novo = (No_lista*) malloc(sizeof(No_lista));
  if (novo == NULL) return; // Proteção essencial da apostila [cite: 1187, 1189]
  
  novo->info = e;
  novo->ant = NULL;
  novo->prox = *p_l; // Aponta para o início da lista

  if(!vazia(p_l)) {
    (*p_l)->ant = novo;
  }
  *p_l = novo;
}

/* Insere um elemento no final da lista */
void insere_fim(Lista *p_l, elem_t e) {
  No_lista *novo, *aux;

  novo = (No_lista*) malloc(sizeof(No_lista));
  novo->info = e;
  novo->prox = NULL;

  if(vazia(p_l)) {
    novo->ant = NULL;
    *p_l = novo;
  } else {
    aux = *p_l;
    while(aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux; 
  }
}

/* Insere um elemento na lista de maneira ordenada.
  Retorna 0 caso o elemento já exista na lista. 
  Assume que a lista está ordenada */
int insere_ordenado(Lista *p_l, elem_t e) {
  No_lista *aux, *novo;
  aux = *p_l;

  // 1. Caso: Lista vazia ou inserir no extremo início
  if(vazia(p_l) || e < (*p_l)->info) {
    insere_inicio(p_l, e);
    return 1;
  }

  // 2. Busca a posição correta (para no último ou no maior que 'e')
  while(aux->prox != NULL && aux->info < e) {
    aux = aux->prox;
  }

  // 3. Verifica se o valor já existe (evita duplicatas)
  if(aux->info == e) {
    return 0;
  }

  // 4. Caso: Inserir no extremo FINAL
  if(aux->prox == NULL && aux->info < e) {
    insere_fim(p_l, e);
    return 1;
  }

  // 5. Caso: Inserir "No Meio" (entre dois nós existentes)
  novo = (No_lista*) malloc(sizeof(No_lista));
  if (novo == NULL) return 0; // Teste de segurança da apostila [cite: 1158, 1187]

  novo->info = e;
  novo->prox = aux;         // Novo aponta para o maior [cite: 996, 1032]
  novo->ant = aux->ant;     // Novo aponta para o menor anterior [cite: 981, 988]
  
  // Como tratamos o início no primeiro 'if', aux->ant nunca será NULL aqui
  aux->ant->prox = novo;    // O nó anterior agora aponta para o novo
  aux->ant = novo;          // O nó atual (maior) aponta para trás para o novo

  return 1;
}

/* Verifica se a lista está ordenada */
int ordenada(Lista *p_l) {
  No_lista *aux;
  aux = *p_l;

  if(vazia(p_l))
    return 0;

  while(aux->prox != NULL && aux->info <= aux->prox->info)
    aux = aux->prox;

  if(aux->prox == NULL) {
    return 1;
  } else {
    return 0;
  }
}

/* Ordena a lista */
void ordena(Lista *p_l) {
  No_lista *aux, *lim = NULL;
  int int_aux, troca;

  if(vazia(p_l)) {
    printf("\nA lista esta vazia");
    return;
  }

  if(ordenada(p_l)) {
    printf("\nA lista ja esta ordenada");
    return;
  }

  do {
    troca = 0;
    aux = *p_l;

    while(aux->prox != lim) {
      if(aux->info > aux->prox->info) {
        int_aux = aux->info;
        aux->info = aux->prox->info;
        aux->prox->info = int_aux; 
        troca = 1;
      }
      aux = aux->prox;
    }
    lim = aux; //limite para casas ja ordenadas
  } while(troca);
  printf("\nA lista foi ordenada!");
}

/* Remove o elemento que está no início da lista.
  Retorna 0 caso a lista esteja vazia */
int remove_inicio(Lista *p_l) {
  No_lista *aux;

  if(vazia(p_l))
    return 0;
  
  aux = *p_l;
  *p_l = (*p_l)->prox;
  free(aux);
  return 1;
}

/* Remove o elemento que está no final da lista.
  Retorna 0 caso a lista esteja vazia */
int remove_fim(Lista *p_l) {
  No_lista *aux;
  
  if(vazia(p_l))
    return 0;

  aux = *p_l;

  if(aux->prox == NULL) {
    free(aux);
    *p_l = NULL;
    return 1;
  }

  while(aux->prox != NULL)
    aux = aux->prox;

  aux->ant->prox = NULL;
  free(aux);
  return 1;
}

/* Remove o nó de valor e.
  Retorna 0 caso este nó não tenha sido encontrado */
int remove_valor(Lista *p_l, elem_t e) {
  No_lista *aux;
  
  if(vazia(p_l))
    return 0;

  aux = *p_l;
  while(aux != NULL && aux->info != e)
    aux = aux->prox;

  if(aux == NULL)
    return 0;

  if(aux->ant != NULL) {
    aux->ant->prox = aux->prox;
  } else {
    *p_l = aux->prox;

    if(*p_l != NULL)
      (*p_l)->ant = NULL;
  }

  if(aux->prox != NULL)
    aux->prox->ant = aux->ant;

  free(aux);
  return 1;
}

void inverte(Lista *p_l) {
  No_lista *esq, *dir;
  int valor_aux;

  if (vazia(p_l)) {
    printf("\nLista vazia");
    return;
  }

  esq = *p_l;
  dir = *p_l;

  while (dir->prox != NULL)
    dir = dir->prox;

  while (esq != dir && esq->ant != dir) {
    valor_aux = esq->info;
    esq->info = dir->info;
    dir->info = valor_aux;

    esq = esq->prox;
    dir = dir->ant;
  }
  printf("\nA lista foi invertida!");
}

/* Remove todos os nós da lista */
void libera(Lista *p_l) {
  if(vazia(p_l)) {
    printf("\nA lista ja esta vazia");
    return;
  }

  No_lista *aux, *prox;
  aux = *p_l;

  while (aux != NULL) {
    prox = aux->prox;
    free(aux);
    aux = prox;
  }
  *p_l = NULL; 
}

/* Exibe o conteúdo da lista */
void exibe(Lista *p_l) {
  No_lista *aux;
  aux = *p_l;
  if(vazia(p_l)) {
    printf("\nLista Vazia");
    return;
  }

  printf("Elementos da lista: ");
  while(aux != NULL) {
    printf("[%i] ", aux->info);
    aux = aux->prox;
  } 
}
