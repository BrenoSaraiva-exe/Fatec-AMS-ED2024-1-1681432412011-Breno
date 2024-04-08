#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct Estoque{
  int id;
  char nome[30];
  int quantidade;
  double valor;
struct Estoque * prox;
}Lista;

Lista * listaCria(void){
  return NULL;
}

Lista * addEstoque(Lista * *head, int id, char nome[], int quantidade, double valor)
{
  Lista * novoProd = (Lista *) malloc(sizeof(Lista));

  novoProd -> id = id;
  strcpy(novoProd -> nome, nome);
  novoProd -> quantidade = quantidade;
  novoProd -> valor = valor;
  novoProd -> prox = *head;

  *head = novoProd;

  return *head;
}

#endif