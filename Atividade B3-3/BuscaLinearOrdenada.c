#include <stdio.h>

int main() {

    int A[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int x = 50;

    int i = 0;

    while (i <= sizeof(A) && x >= A[i]){

        if(x == A[i]){
            printf("Valor encontrado: %d", A[i]);
          return i;
        }

        i = i + 1;
    }
        printf("Valor não encontrado!");
        return -1;

}