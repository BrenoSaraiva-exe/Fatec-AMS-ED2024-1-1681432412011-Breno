/* 
* ---------------------------------------------------------------------- *
* FATEC-São Caetano do Sul Estrutura de Dados                            *
*                                                Avaliação N1 - Parte II *
* Objetivo: Manutenção de pacote                                         *
*                                                                        *
* Autores: <Breno Saraiva e Enzo Dorta>                                  *
*                                                     Data:08/04/2024    *
* ---------------------------------------------------------------------- *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "addPacote.h"
#include "alterPacote.h"
#include "buscaPacote.h"

int main(void) 
{

  ListaPacote * Pacote;

  Pacote = listaCria();
  
  int opcao, saida = 1;
  
  printf("Escolha sua opção:\n");
  printf("1 - Sair do programa\n");
  printf("2 - Incluir pacote\n");
  printf("3 - Alterar status pacote\n");
  printf("4 - Buscar pacote\n");

  while(saida != 0){

  printf("\nOpção: "); scanf("%d", &opcao);

  switch(opcao)
  {
  case 1:
    saida = 0;
  break;

  case 2:
    Pacote = addPacote(&Pacote);
  break;

  case 3:
    alterPacote(&Pacote);
  break;

  case 4:
    buscaPacote(&Pacote);
  break;
  }    
  }
}
