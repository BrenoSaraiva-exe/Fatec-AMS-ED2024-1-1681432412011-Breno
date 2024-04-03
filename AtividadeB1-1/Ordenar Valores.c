/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof Veríssimo                                 */
/*             Objetivo: Desafios de Ordenar Valores                      */
/*             Paradigama: Programação Modular                            */
/*                                                                        */
/*                                                         Data:12/03/2024*/
/*------------------------------------------------------------------------*/ 

#include <stdio.h>

int main(void) {

  printf("Digite suas 5 notas! \n");

  int i, j, x;

  int notas[5];

  for (i = 0; i < 5; ++i) {
    
    scanf("%d", &notas[i]);

    printf("%d º Nota = ", i + 1);
    printf("%d\n", notas[i]);
      
    }

  // Checar todos os valores dentro das notas
  for (i = 0; i < 5; ++i){

      for (j = i + 1; j < 5; ++j){
        
        // Se o valor da posição i for maior que o valor da posição j, troca os valores
        if (notas[i] > notas[j]){
          
          x = notas[i];
          notas[i] = notas[j];
          notas[j] = x;
          
        }
      }
    
  }

  // Imprimir as notas em ordem crescente
  printf("Notas: ");
  for (int i = 0; i < 5; ++i) 
    printf("%d ", notas[i]);
  
}