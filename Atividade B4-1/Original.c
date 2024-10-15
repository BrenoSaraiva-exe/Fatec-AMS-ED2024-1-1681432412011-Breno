#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    /* Array pre-definido para testes
    int arr[50] = {10, 50, 12, 32, 45, 78, 56, 23, 89, 67, 
                   14, 8, 92, 41, 36, 27, 73, 21, 34, 91,
                   5, 15, 76, 64, 82, 33, 6, 95, 48, 29,
                   53, 71, 18, 24, 66, 39, 83, 2, 87, 9,
                   54, 99, 100, 31, 26, 74, 22, 77, 38, 4};
    int n = 50;
    */
    
    int n;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    int *arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite %d valores para o array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Array original: \n");
    printArray(arr, n);

    clock_t start = clock();

    bubbleSort(arr, n);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("Array ordenado: \n");
    printArray(arr, n);
    printf("\nTempo de execução do Bubble Sort: %.20f ms\n", time_taken);

    return 0;
}
