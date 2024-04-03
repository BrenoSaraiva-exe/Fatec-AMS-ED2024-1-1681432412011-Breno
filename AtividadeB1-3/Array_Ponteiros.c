/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Prof Veríssimo                                 */
/*             Objetivo: Desafios de Array & Ponteiros                    */
/*             Paradigama: Programação Modular                            */
/*                                                                        */
/*                                                         Data:12/03/2024*/
/*------------------------------------------------------------------------*/ 

#include <stdio.h>

int n = 5; // Quantidade de elementos/notas no array

int i, z, temp, TotalNotas; // Declarar Variáveis globais

// Maior elemento do Array

void MaiorNota(int * ptrNotas, int n){
  
  printf("\nA maior nota é: %d \n", ptrNotas[n-1]);
  
}

// Soma dos elementos do Array

void SomaNotas(int * ptrNotas, int n){

  for (i = 0; i < n; ++i) TotalNotas = TotalNotas + ptrNotas[i];

  printf( "A soma das notas é: %d \n", TotalNotas);
  
}

// Imprimir todos os elementos do Array

void ImprimirNotas(int * ptrNotas, int n){

    printf("Todas as Notas:");
    for (i = 0; i < n; ++i) 
    printf(" %d", ptrNotas[i]);

}

// Multiplicar elementos do Array

void MultiplicarNotas(int * ptrNotas, int n){

  int multiplicador = 5;
  
  printf("\nNotas multiplicadas: ");
  
  for (i = 0; i < n; ++i){

    ptrNotas[i] = ptrNotas[i] * multiplicador;

    printf(" %d", ptrNotas[i]);

    multiplicador++;

  }
    
  }

  // Os elementos são multiplicados por numeros num loop a partir de 5 onde a cada passagem +1 é adicionado ao multiplicador

  /* Outra forma de fazer, porém com números específicos, não necessariamente consecutivos:

      for (i = 0; i < n; ++i){

        if(i == 0) ptrNotas[i] = ptrNotas[i] * 3;
        if(i == 1) ptrNotas[i] = ptrNotas[i] * 7;
        if(i == 2) ptrNotas[i] = ptrNotas[i] * 2;
        if(i == 3) ptrNotas[i] = ptrNotas[i] * 9;
        if(i == 4) ptrNotas[i] = ptrNotas[i] * 8;

        printf(" %d", ptrNotas[i]);

      }
  
  */

int main(void) {

  printf("Digite suas %d Notas! \n", n);

  int Notas[n]; // Declarar Array

  // Definir valores do array

  for (i = 0; i < n; ++i) {

    scanf("%d", &Notas[i]);

    printf("%d º Nota = ", i + 1);
    printf("%d\n", Notas[i]);

    }

  // Ordenar em ordem crescente
  
  for (i = 0; i < n; ++i){

      for (z = i + 1; z < n; ++z){

        if (Notas[i] > Notas[z]){

          temp = Notas[i];
          Notas[i] = Notas[z];
          Notas[z] = temp;

        }
      }
  }

  printf("\n----- Resultados do Desafio -----\n");

  // Chamar funções do desafio

  MaiorNota(Notas,n);

  SomaNotas(Notas,n);

  ImprimirNotas(Notas,n);

  MultiplicarNotas(Notas,n);
  
}