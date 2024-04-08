/* 
* ---------------------------------------------------------------------- *
* FATEC-São Caetano do Sul Estrutura de Dados                            *
*                                                Avaliação N1 - Parte I  *
* Objetivo: Controlar Estoque de produtos                                *
*                                                                        *
* Autores: <Breno Saraiva e Enzo Dorta>                                  *
*                                                     Data:02/04/2024    *
* ---------------------------------------------------------------------- *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "addEstoque.h"
#include "buscaEstoque.h"
#include "baixaEstoque.h"
#include "listarEstoque.h"

int main(void) 
{
  Lista * Lista;

  Lista = listaCria();
  
  int opcao, saida = 1;
  
  int id;
  char nome[30];
  int quant;
  float valor;
  
  printf("Escolha sua opção:\n");
  printf("0 - Sair do programa\n");
  printf("1 - Adicionar um produto\n");
  printf("2 - Buscar produto\n");
  printf("3 - Baixa em produto\n");
  printf("4 - Listar todos\n");

  while(saida != 0)
  { 
  printf("\nOpção: "); scanf("%d", &opcao);
    
  switch(opcao)
  {
  case 0:
    saida = 0;
  break;

  case 1:
    printf("\nDigite cada dado para ser inserido:\n");

    printf("ID: ");
    scanf("%d", &id);
    
    printf("Nome: ");
    scanf("%s", nome);
    
    printf("Quantidade: ");
    scanf("%d", &quant);
    
    printf("Valor(ponto para representar decimal): ");
    scanf("%f", &valor);
    
    Lista = addEstoque(&Lista, id,nome,quant,valor);
  break;

  case 2:

    printf("Digite o ID do produto desejado: ");
    scanf("%d", &id);
    
    buscaEstoque(&Lista,&id);
  break;
    
  case 3:
    printf("Digite o ID do produto desejado: ");
    scanf("%d", &id);

    printf("Digite a quantidade a ser reduzida: ");
    scanf("%d", &quant);
    
    baixaEstoque(&Lista, &id, &quant);
  break;

  case 4:
    listarEstoque(&Lista);
  break;
  }    
  }
}
