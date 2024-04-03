/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof Veríssimo                                 */
/*             Objetivo: Desafios Ponteiros                               */
/*             Paradigama: Programação Modular                            */
/*                                                                        */
/*                                                         Data:12/03/2024*/
/*------------------------------------------------------------------------*/ 

#include <stdio.h>

float descontar(float* ptr_preco, float* ptr_desconto){

  float valor_desc = *ptr_preco * (*ptr_desconto/100);
  float preco_final = *ptr_preco - valor_desc;
  
  printf("O valor incial do produto era: %f\n", *ptr_preco);
  printf("O valor do desconto foi: %f\n", valor_desc);
  printf("O valor final do produto é: %f\n", preco_final);

  return 0;
}

int main() {

  float preco, desconto;

  printf("Digite o valor do produto:\n");
  scanf("%f", &preco);

  printf("Digite a porcentagem do desconto:\n");
  scanf("%f", &desconto);

  while(desconto > 50){
    printf("O desconto não pode ser maior que 50%%\n");
    printf("Digite a porcentagem do desconto novamente:\n");
    scanf("%f", &desconto);
  }
  if (desconto <= 50)
  descontar(&preco, &desconto);
  
  return 0;
}
