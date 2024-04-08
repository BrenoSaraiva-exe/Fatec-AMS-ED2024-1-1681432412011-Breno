#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addEstoque.h"

int baixaEstoque(Lista * *busca, int * id, int * quant){

  Lista * p;
  Lista * Anterior;
  
  for(p = *busca; p != NULL; p = p -> prox){

    if(p -> id == *id)
    {
      p->quantidade = p->quantidade - *quant;
      
      if(p->quantidade < 1)
      {
        *busca = p -> prox;
        free(p);
        return 0;

        while(p -> valor != *id)
        {
          Anterior = p;
          p = p -> prox;
        }

        Anterior -> prox = p -> prox;
        free(p);
        return 0;
      }
    }
    else
    {
      printf("Produto não encontrado!");    
    }
  }
  return 0;
}
