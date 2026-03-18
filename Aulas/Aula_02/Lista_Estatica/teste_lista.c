

#include<stdio.h>
#include "lista_estatica.h"

int main(){
  int num, opcao = 0;
  Lista l;
  cria(&l);

  do {
    printf("\n\n [1] - Insere um numero no inicio da lista");
    printf("\n [2] - Insere um numero no fim da lista");
    printf("\n [3] - Insere um numero de maneira ordenada");
    printf("\n [4] - Verifica se a lista esta ordenada");
    printf("\n [5] - Ordena a lista");
    printf("\n [6] - Remove o elemento que esta no inicio da lista");
    printf("\n [7] - Remove o elemento que esta no fim da lista");
    printf("\n [8] - Remove um elemento determinado");
    printf("\n [9] - Inverte");
    printf("\n [10] - Esvaziar a lista");
    printf("\n [11] - Exibe a lista");
    printf("\n [12] - Sair");
    printf("\n\nEntre com uma das opcoes acima: ");
    scanf("%i", &opcao);

    switch (opcao) {
      case 1: {
        printf("Insira o elemento a ser adicionado no inicio da lista: ");
        scanf("%i", &num);

        insere_inicio(&l, num);
      }; break;
      case 2: {
        printf("Insira o elemento a ser adicionado no fim da lista: ");
        scanf("%i", &num);
        
        insere_fim(&l, num);
      }; break;
      case 3: {
        printf("Insira o elemento a ser adicionado de forma ordenada na lista: ");
        scanf("%i", &num);

        if(!insere_ordenado(&l, num)) {
          printf("O elemento já existente ou lista cheia");
        }
      }; break;
      case 4: {
        if(ordenada(&l)) {
          printf("A lista esta ordenada");
        } else {
          printf("A lista não esta ordenada");
        }
      }; break;
      case 5: {
        ordena(&l);
      }; break;
      case 6: {
        if(remove_inicio(&l)) {
          printf("Elemento removido com sucesso");
        } else {
          printf("Lista Vazia");
        }
      }; break;
      case 7: {
        if(remove_fim(&l)) {
          printf("Elemento removido com sucesso");
        } else {
          printf("Lista Vazia");
        }
      }; break;
      case 8: {
        printf("Insira o elemento a ser removido da lista: ");
        scanf("%i", &num);

        if(remove_valor(&l, num)) {
          printf("\nElemento removido com sucesso");
        } else {
          printf("\nLista vazia ou elemento nao encontrado");
        }
      }; break;
      case 9: {
        inverte(&l);
        break;
      }; break;
      case 10: {
        libera(&l);
        break;
      }; break;
      case 11: {
        exibe(&l);  
      }; break;
      case 12: {
        printf("Ate mais ;-;");  
      }; break;
      default: {
        printf("Opcao invalida");
        break;
      }
    }
  } while(opcao != 12);
}
