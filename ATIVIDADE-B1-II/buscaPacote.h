#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addPacote.h"
#include "listarPacote.h"

void buscaPacote(ListaPacote * *head)
{
  ListaPacote * Pacote = *head;

  int id;
  printf("Qual o id do pacote que deseja buscar? \n");
  printf("Digite 1 para buscar todos\n");
  scanf("%d", &id);

  if (id == 1)
  {
    listarPacote(&Pacote);
  }
  else
  {
  for(ListaPacote * Temp = Pacote; Temp != NULL; Temp = Temp -> prox)
  {
    if(id == Temp -> id)
    {
      printf("O pacote de id %d foi encontrado!\n", id);
      printf("Status: %d\n", Temp->status);
      printf("conteudo do Pacote: %s\n", Temp->conteudo);
      return;
    }
    else{
      printf("O pacote não foi encontrado!\n");
    }
    return;
  }
  }
  return;
}