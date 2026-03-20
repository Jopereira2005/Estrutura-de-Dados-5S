#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

int main(){
  int num, opcao = 0;
  Pilha p;
  cria_pilha(&p);

  do {
    printf("\n\n [1] - Insere um elemento no topo da pilha");
    printf("\n [2] - Remove o elemento do topo da pilha");
    printf("\n [3] - Exibe o elemento do topo da pilha");
    printf("\n [4] - Verifica se a pilha esta vazia");
    printf("\n [5] - Verifica se a pilha esta cheia");
    printf("\n [6] - Esvaziar a pilha");
    printf("\n [7] - Exibe a pilha");
    printf("\n [8] - Sair");
    printf("\n\nEntre com uma das opcoes acima: ");
    scanf("%i", &opcao);

    switch (opcao) {
      case 1: {
        printf("Insira o elemento a ser adicionado no topo da pilha: ");
        scanf("%i", &num);

        if(insere_pilha(&p, num) == -1) 
          printf("Ocorreu overflow na pilha!\n");
        else
          printf("Elemento %i inserido com sucesso", num);
      }; break;
      case 2: {
        int removido = remove_pilha(&p);
        if(removido == -1) 
          printf("Ocorreu underflow na pilha!\n");
        else 
          printf("Elemento %i removido com sucesso", removido);
      }; break;
      case 3: {
        int topo = elem_topo(&p);
        if(topo == -1) 
          printf("Ocorreu underflow na pilha!\n");
        else 
          printf("O elemento do topo da pilha e: %i", topo);
      }; break;
      case 4: {
        if(pilha_vazia(&p)) {
          printf("A pilha esta vazia");
        } else {
          printf("A pilha nao esta vazia");
        }
      }; break;
      case 5: {
        if(pilha_cheia(&p)) {
          printf("A pilha esta cheia");
        } else {
          printf("A pilha nao esta cheia");
        }
      }; break;
      case 6: {
        libera_pilha(&p);

        printf("Pilha esvaziada com sucesso");
      }; break;
      case 7: {
        exibe_pilha(&p);
      }; break;
      case 8: {
        printf("Ate mais ;-;");  
      }; break;
      default: {
        printf("Opcao invalida");
        break;
      }
    }} while (opcao != 8);
}
