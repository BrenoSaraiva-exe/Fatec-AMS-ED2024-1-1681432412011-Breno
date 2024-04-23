/* 
* ---------------------------------------------------------------------- *
* FATEC-São Caetano do Sul Estrutura de Dados                            *
*                                                  Atividade-B2-Parte-1  *
* Objetivo: Simular calculadora financeira                               *
*                                                                        *
* Autor: <Breno Saraiva>                                                 *
*                                                     Data:08/04/2024    *
* ---------------------------------------------------------------------- *
*/

//Obs: Isso foi um dos programas mais complexas em lógica e sintaxe que tive que fazer
//Ass. Breno Saraiva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 1500

typedef struct{
  float data[ARR_SIZE];
  char arit[ARR_SIZE];
  int topo;
}Pilha;

Pilha * pilhaCria(){
  Pilha * pilha = (Pilha *) malloc(sizeof(Pilha));
  pilha -> topo = -1;
  return pilha;
}

int vazia(Pilha * pilha){
  return pilha -> topo == -1;
}

int lotada(Pilha * pilha){
  return pilha -> topo == ARR_SIZE -1;
}

// ---------------------------------------------

int isNum(char *element){
    if (*element >= '0' && *element <= '9') return 1;
    else return 0;
}

void push(Pilha * pilha, float * valor){

  if(lotada(pilha)){ 
    printf("Lista lotada!");
  }
  else{
      pilha->topo++;
      pilha->data[pilha->topo] = *valor;
  }
}

void pushArit(Pilha * pilha, char strCalculo[]){

  if(lotada(pilha)) printf("Lista lotada!");
  else{
    pilha->topo++;
    strcpy(&pilha->arit[pilha->topo], strCalculo);
  }
}

float pop(Pilha * pilha){

  if(vazia(pilha)){
    printf("Lista vazia!");
    return -1;
  }
  else{

    float valor = pilha->data[pilha->topo];
    pilha -> topo--;
    return valor;
  }
}

void calcAritmetica(float * a, float * b, char * operador){

  char strCalculo[50];
  sprintf(strCalculo, "%.2f %c %.2f", *b, *operador, *a);

  printf("\nPasso à passo operação aritmética: %s\n", strCalculo);

}

void funcUnica(Pilha * pilha, float * a, float * b, char * operador, char strCalculo[]){
  
  static int chamada = 0;
  
  if(chamada == 0){
  sprintf(strCalculo, "%.2f %c %.2f", *b, *operador, *a);
  pushArit(pilha,strCalculo);
  chamada = 1;
  return;
  }
  else return;
  
}

void opAritmetica(Pilha * pilha, float * a, float * b, char * operador, int * count){
  
  char strCalculo[ARR_SIZE];
  char opNaLista[ARR_SIZE];
  char novoCalc[ARR_SIZE];

  funcUnica(pilha, a, b, operador, strCalculo);

  if(*count > 0){
      strcpy(opNaLista, &pilha->arit[pilha->topo]);
      sprintf(novoCalc, "%c %.2f", *operador, *a);
    
      sprintf(strCalculo, "(%s) %s", opNaLista, novoCalc);
      pushArit(pilha,strCalculo);
  }
}

float calcular(float * operando1, float * operando2, char * operador) {

  calcAritmetica(operando1,operando2,operador);
  
    switch (*operador) {
        case '+':
            return *operando1 + *operando2;
        case '-':
            return -*operando1 + *operando2;
        case '*':
            return *operando1 * *operando2;
        case '/':
            return *operando1 / *operando2;

        default:
            printf("Operador inválido\n");
          return 0;
    }

}

void separar(Pilha * pilha, char RPN[]) {

  float operando1;
  float operando2;
  char operador;

  int count = 0;
  
  char * token = strtok(RPN, " ");

  while (token != NULL){
    if(isNum(&token[0])){
      float operando = atof(token);
      push(pilha, &operando);
    }
    else{
      operando1 = pop(pilha);
      operando2 = pop(pilha);
      operador = token[0];

      float resulto = calcular(&operando1, &operando2, &token[0]);
      opAritmetica(pilha, &operando1,&operando2,&operador, &count);
      push(pilha, &resulto);
      
      count++;
    }
    token = strtok(NULL, " ");
  }
  float resultadoFinal = pop(pilha);

  printf("\nOperação aritmética: %s\n", &pilha->arit[pilha->topo]);
  
  printf("\nResultado Final: %.2f\n",resultadoFinal);

}

int main(void){

  Pilha * pilha;

  pilha = pilhaCria();

  char RPN[ARR_SIZE];

  printf("Digite sua operação(separe os elementos por caracteres):\n");

  printf("\nR: "); scanf("%[^\n]s",RPN);

  separar(pilha,RPN);

}
