/* 
* ---------------------------------------------------------------------- *
* FATEC-São Caetano do Sul Estrutura de Dados                            *
*                                                    Atividade B2 - VI   *
* Objetivo: Inserir dentro de Lista Ligada                               *
*                                                                        *
* Autores: <Breno Saraiva>                                               *
*                                                     Data:28/05/2024    *
* ---------------------------------------------------------------------- *
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lista {
    int data;
    struct Lista *prox;
} Lista;

Lista *listaCria(Lista *l, int v) {
    Lista *NovoVal = (Lista *)malloc(sizeof(Lista));
    NovoVal->data = v;
    NovoVal->prox = l;
    return NovoVal;
}

void listar(Lista *l) {
    Lista *Temp;
    printf("[ ");
    for (Temp = l; Temp != NULL; Temp = Temp->prox) {
        printf("%d ", Temp->data);
    }
    printf("]\n");
}

Lista *addNumArr(int num, Lista *l) {
    
    Lista *Temp = l;
    Lista *NovoVal = (Lista *)malloc(sizeof(Lista));
    NovoVal->data = num;
    NovoVal->prox = NULL;

    if (l == NULL || num < l->data) {
        NovoVal->prox = l;
        return NovoVal;
    } // Se a lista estiver vazia

    while (Temp->prox != NULL && Temp->prox->data < num) {
        Temp = Temp->prox;
    } // Salva um nó até que ele não seja mais menor que o novo valor

    NovoVal->prox = Temp->prox;
    Temp->prox = NovoVal;

    return l;
    
}

int main(void) {

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    Lista * Lista = NULL; 
    Lista = listaCria(Lista, 80);
    Lista = listaCria(Lista, 40);
    Lista = listaCria(Lista, 25);
    Lista = listaCria(Lista, 10);

    int num;

    printf("Lista ANTES:\n");
    listar(Lista);

    printf("\nDigite o número que deseja inserir: ");
    scanf("%d", &num);

    Lista = addNumArr(num, Lista);

    printf("\nLista DEPOIS:\n");
    listar(Lista);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nO tempo de execução foi de %f segundos.\n", cpu_time_used);
    
}
