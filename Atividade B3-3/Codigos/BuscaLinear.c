#include <stdio.h>

int main() {

    int A[] = {40, 80, 10, 20, 30, 50, 70, 60};
    int x = 90;
    int i = 0;

    while (i <= sizeof(A)){

        if(x == A[i]){
            printf("Valor encontrado: %d", A[i]);
          return i;
        }

        i = i + 1;
    }
        printf("Valor não encontrado!");
        return -1;

}