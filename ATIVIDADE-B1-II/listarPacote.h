#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addPacote.h"

void listarPacote(ListaPacote * *head){
  
  ListaPacote * Pacote = *head;

  for(ListaPacote * Temp = Pacote; Temp != NULL; Temp = Temp -> prox)
  {
    printf("---------------------------------\n");
    printf("Id: %d\n", Temp -> id);
    printf("Status: %d\n", Temp -> status);
    printf("Conteúdo: %s\n", Temp -> conteudo);
    printf("---------------------------------\n");
    
    if(Temp == NULL)
    {
    printf("O pacote não foi encontrado!\n");
    return;
    }
  }
  return;
}