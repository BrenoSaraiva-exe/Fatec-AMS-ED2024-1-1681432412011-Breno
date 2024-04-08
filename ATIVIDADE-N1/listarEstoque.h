#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addEstoque.h"

void listarEstoque(Lista * *busca){

  Lista * p;

  for(p = *busca; p != NULL; p = p -> prox){

      printf("ID: %d \nNome: %s \nQuantidade: %d \nValor: %.2f\n",
        p->id, p->nome, p->quantidade, p->valor);
      printf("---------------------------------\n");
    
  if(p == NULL) printf("Lista Vazia!");
  }
}
