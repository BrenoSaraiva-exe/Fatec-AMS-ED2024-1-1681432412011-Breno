#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addEstoque.h"

void buscaEstoque(Lista * *busca, int * id){

  Lista * p;
  
  for(p = *busca; p != NULL; p = p -> prox)
  {
    if(p -> id == *id)
    {
      printf("ID: %d \nNome: %s \nQuantidade: %d \nValor: %.2f\n",
        p->id, p->nome, p->quantidade, p->valor);
    }
    else
    {
      printf("Produto não encontrado!");
    }
  }
}