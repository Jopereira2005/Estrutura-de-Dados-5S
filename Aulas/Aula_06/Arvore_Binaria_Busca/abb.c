#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

void cria_arvore(Arvore *p) {
  *p = NULL; // A árvore inicia vazia [cite: 388]
}

/* --- Percursos e Buscas --- */
void inorder(Arvore p) {
  if (p != NULL) {
    inorder(p->esq);
    printf("[%d] ", p->info);
    inorder(p->dir);
  }
}

void preorder(Arvore p) {
  if (p != NULL) {
    printf("[%d] ", p->info);
    preorder(p->esq);
    preorder(p->dir);
  }
}

void postorder(Arvore p) {
  if (p != NULL) {
    postorder(p->esq);
    postorder(p->dir);
    printf("[%d] ", p->info);
  }
}

int busca(Arvore p, int chave) {
  if (p == NULL) return 0;
  if (p->info == chave) return 1;
  return (chave < p->info) ? busca(p->esq, chave) : busca(p->dir, chave);
}

int n_rec_busca(Arvore p, int chave) {
  while (p != NULL) {
    if (chave == p->info) return 1;
    p = (chave < p->info) ? p->esq : p->dir;
  }
  return 0;
}

/* --- Inserções e Remoções --- */
int insere(Arvore *p, int chave) {
  if (*p == NULL) {
    *p = (No*) malloc(sizeof(No)); // Alocação dinâmica [cite: 26, 748]
    if (*p == NULL) return 0;

    (*p)->info = chave;
    (*p)->esq = (*p)->dir = NULL;
    return 1;
  }

  if (chave == (*p)->info) return 0;
  return (chave < (*p)->info) ? insere(&((*p)->esq), chave) : insere(&((*p)->dir), chave);
}

int n_rec_insere(Arvore *p, int chave) {
  No *novo, *atual, *pai;

  if (n_rec_busca(*p, chave)) 
    return 0;

  if ((novo = (No*) malloc(sizeof(No))) == NULL) 
    return 0;

  novo->info = chave;
  novo->esq = novo->dir = NULL;

  if (*p == NULL) { 
    *p = novo; 
    return 1; 
  }

  atual = *p;
  while (atual != NULL) {
    pai = atual;
    atual = (chave < atual->info) ? atual->esq : atual->dir;
  }

  if (chave < pai->info) 
    pai->esq = novo;
  else 
  pai->dir = novo;
    return 1;
}

No *encontrar_minimo(No *raiz) {
  while (raiz != NULL && raiz->esq != NULL) 
    raiz = raiz->esq;

  return raiz;
}

int remove_arv(Arvore *p, int chave) {
  if (*p == NULL) 
    return 0;

  if (chave < (*p)->info) 
    return remove_arv(&((*p)->esq), chave);
  if (chave > (*p)->info) 
    return remove_arv(&((*p)->dir), chave);
  
  No *aux = *p;
  if ((*p)->esq == NULL) { 
    *p = (*p)->dir; 
    free(aux); 
  } else if ((*p)->dir == NULL) { 
    *p = (*p)->esq; 
    free(aux); 
  } else {
    No *temp = encontrar_minimo((*p)->dir);
    (*p)->info = temp->info;
    remove_arv(&((*p)->dir), temp->info);
  }
  return 1;
}

/* --- VISUALIZAÇÃO COMPATÍVEL (ASCII) --- */
void exibe_ascii(No *p, char *prefixo, int eh_esquerdo) {
  if (p == NULL) return;

  printf("%s", prefixo);
  printf("%s", (eh_esquerdo ? "|-- " : "L-- "));
  printf("[%d]\n", p->info);

  char novo_prefixo[200];
  // Usa "|" apenas se houver mais ramos abaixo para conectar visualmente
  sprintf(novo_prefixo, "%s%s", prefixo, (eh_esquerdo ? "|   " : "    "));

  if (p->esq || p->dir) {
    if (p->esq) exibe_ascii(p->esq, novo_prefixo, 1);
    else printf("%s|-- [NULL]\n", novo_prefixo);
    
    if (p->dir) exibe_ascii(p->dir, novo_prefixo, 0);
    else printf("%sL-- [NULL]\n", novo_prefixo);
  }
}

void exibe_arvore_top(Arvore p) {
  printf("\nESTRUTURA DA ARVORE (L=Dir, |--=Esq):\n");
  if (p == NULL) {
    printf("[Vazia]\n");
  } else {
    printf("[%d] (RAIZ)\n", p->info);
    if (p->esq) exibe_ascii(p->esq, "", 1);
    else if (p->dir) printf("|-- [NULL]\n"); // Se só tem filho na direita, indica o vazio na esquerda

    if (p->dir) exibe_ascii(p->dir, "", 0);
    else if (p->esq) printf("L-- [NULL]\n"); // Se só tem filho na esquerda, indica o vazio na direita
  }
  printf("\n");
}

/* --- Verificação de ABB --- */
int auxiliar_verifica(No *p, No **anterior) {
  if (p == NULL) return 1;
  if (!auxiliar_verifica(p->esq, anterior)) return 0;
  if (*anterior != NULL && p->info <= (*anterior)->info) return 0;
  *anterior = p;
  return auxiliar_verifica(p->dir, anterior);
}

int verifica_busca(Arvore p) {
  No *anterior = NULL;
  return auxiliar_verifica(p, &anterior);
}