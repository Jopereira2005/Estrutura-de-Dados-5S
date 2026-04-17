#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

// Protótipo da nova função visual que está no abb.c
void exibe_arvore_top(Arvore p);

int main() {
  Arvore minha_arv;
  cria_arvore(&minha_arv);
  int opcao, valor;

  do {
    printf("\n--- MENU ABB FACENS ---");
    printf("\n1 - Inserir");
    printf("\n2 - Remover");
    printf("\n3 - Buscar");
    printf("\n4 - Percursos (In/Pre/Pos)");
    printf("\n5 - MOSTRAR ARVORE (VISUAL)");
    printf("\n6 - Verificar se eh ABB");
    printf("\n0 - Sair");
    printf("\nEscolha: ");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        printf("Valor: "); scanf("%d", &valor);
        if (insere(&minha_arv, valor)) printf("Sucesso!\n");
        else printf("Erro: Chave ja existe.\n");
        break;
      case 2:
        printf("Remover: "); scanf("%d", &valor);
        if (remove_arv(&minha_arv, valor)) printf("Removido!\n");
        else printf("Nao encontrado.\n");
        break;
      case 3:
        printf("Busca: "); scanf("%d", &valor);
        if (busca(minha_arv, valor)) printf("Achou!\n");
        else printf("Nao achou.\n");
        break;
      case 4:
        printf("\nIn: "); inorder(minha_arv);
        printf("\nPre: "); preorder(minha_arv);
        printf("\nPos: "); postorder(minha_arv);
        printf("\n");
        break;
      case 5:
        exibe_arvore_top(minha_arv);
        break;
      case 6:
        if (verifica_busca(minha_arv)) printf("ABB Valida!\n");
        else printf("Invalida!\n");
        break;
    }
  } while (opcao != 0);

  return 0;
}