#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estoque{
  int ID;
  char Nome[50];
  int Quantidade;
  double Valor;
struct Estoque * prox;
}Lista;

Lista * ListaCria(void){
  return NULL;
}

int Inserir(Lista * l, int ID, char Nome[], int Quantidade, double Valor)
{

  Lista * NovoVal = (Lista *) malloc(sizeof(Lista));
  NovoVal -> ID = ID;
  strcpy(NovoVal -> Nome, Nome);
  NovoVal -> Quantidade = Quantidade;
  NovoVal -> Valor = Valor;
  NovoVal -> prox = l;

  return NovoVal;
  
}

int addEstoque(){

  Lista * Lista;
  Lista = ListaCria();
  
  int ID = 3, L;
  char arrayNome[50] = {'j','o','a','o'};
  int Quantidade = 5;
  double Valor = 10;

  L = Inserir(Lista, ID, arrayNome, Quantidade, Valor);
  
}
#endif