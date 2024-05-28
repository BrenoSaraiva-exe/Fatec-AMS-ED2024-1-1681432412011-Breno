/* 
* ---------------------------------------------------------------------- *
* FATEC-São Caetano do Sul Estrutura de Dados                            *
*                                                    Atividade B2 - VI   *
* Objetivo: Inserir dentro de Array                                      *
*                                                                        *
* Autores: <Breno Saraiva>                                               *
*                                                     Data:28/05/2024    *
* ---------------------------------------------------------------------- *
*/

#include <stdio.h>
#include <time.h>

#define ARR_SIZE 5 // Tamanho do array aumentado para acomodar o novo elemento

int arr[ARR_SIZE] = {10, 25, 40, 80};

void addNumArr(int num) {
    int i = ARR_SIZE - 2;
  
    while (i >= 0 && arr[i] > num) {
      
        arr[i + 1] = arr[i];
        i--;
      
    }
    arr[i + 1] = num;
}

int main(void) {

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    printf("Array ANTES:\n");
  
    printf("[ ");
    for (int i = 0; i < ARR_SIZE - 1; i++)
        printf("%d ", arr[i]);
    printf("]\n");

    int num;

    printf("\nDigite o número que deseja inserir: ");
    scanf("%d", &num);

    addNumArr(num);

    printf("\nArray DEPOIS:\n");

    printf("[ ");
    for (int i = 0; i < ARR_SIZE; i++)
        printf("%d ", arr[i]);
    printf("]\n");

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nO tempo de execução foi de %f segundos.\n", cpu_time_used);
  
}
