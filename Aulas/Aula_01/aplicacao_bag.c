#include <stdio.h>
#include "bag.h"    

int main() {
  Bag sacola;
  int op = 0, elem = 0, resp = 0;

  init(&sacola);

  do {
    printf("\n\n[1] - Inserir elemento\n");
    printf("[2] - Quantidade de elementos\n");
    printf("[3] - Verificar elemento\n");
    printf("[4] - Remover elemento\n");
    printf("[5] - Imprimir todos os elementos\n");
    printf("[6] - Sair\n");
    printf("Opcao: ");
    scanf("%i", &op);
    printf("\n");

    switch(op) {
      case 1: {
        printf("Digite o elemento a ser inserido: ");
        scanf("%i", &elem);
        
        if((resp = insert(&sacola, elem)) == 1) {
          printf("Elemento inserido com sucesso");
        } else {
          printf("Erro ao inserir elemento");
        }

        break;
      }

      case 2: {
        printf("A sacola possui %i elementos", size(&sacola));
        break;
      }

      case 3: {
        printf("Digite o elemento a ser contado: ");
        scanf("%i", &elem);

        printf("O elemento %i possui %i aparicoes na sacola", elem, check(&sacola, elem));
        break;
      }

      case 4: {
        printf("Digite o elemento a ser removido: ");
        scanf("%i", &elem);

        if((resp = delete(&sacola, elem)) == 1) {
          printf("Elemento removido com sucesso");
        } else {
          printf("Erro ao remover elemento");
        }

        break;
      }

      case 5: {
        printf("Elementos: ");
        printall(sacola);
        break;
      } 
      default: {
        printf("Opcao invalida");
      }
    }

  } while (op != 6);
  printf("Teste da TAD bag\n");
}
