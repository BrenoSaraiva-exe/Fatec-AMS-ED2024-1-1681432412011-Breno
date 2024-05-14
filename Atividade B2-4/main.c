/* 
* ---------------------------------------------------------------------- *
* FATEC-São Caetano do Sul Estrutura de Dados                            *
*                                                    Atividade B2 - IV   *
* Objetivo: Simular fila de hospital                                     *
*                                                                        *
* Autores: <Breno Saraiva>                                               *
*                                                     Data:13/05/2024    *
* ---------------------------------------------------------------------- *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARR_SIZE 50

int idPaciente;
int senha;
time_t t1;
time_t t2;

typedef struct{
  int idPaciente;
  int tipoAtendimento;
  char nomePaciente[ARR_SIZE];
  int idadePaciente;
  char especialidade[ARR_SIZE];
  int senha;
}Paciente;

typedef struct listaEspera{
  Paciente paciente;
  struct listaEspera * prox;
}Espera;

typedef struct Filas{
  Espera * inicio;
  Espera * fim;
}Fila;

Fila * filaCria(){
  
  Fila * fila = (Fila*) malloc(sizeof(Fila));

  if(fila == NULL){
    printf("Erro ao alocar memoria");
    return NULL;
  }
  else{
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
  }
}

typedef struct Medicos{
  int idMedico;
  char nomeMedico[ARR_SIZE];
  char especialidade[ARR_SIZE];
  int atendendo;
  struct Medicos * prox;
}Medico;

  Medico Medico1 = {1, "Jason", "Cardiologista", 0};
  Medico Medico2 = {2, "Rafael", "Psiquiatra", 0};
  Medico Medico3 = {3, "Edleide", "Dentista", 0};
  Medico Medico4 = {4, "Laís Pitica", "Pediatra", 0};
  Medico Medico5 = {5, "Fernando", "Urologista", 0};

int Vazia(Fila * fila)
{
  if(fila->inicio == NULL)
    return 1;
  else
    return 0; 
}

Paciente lerPaciente(){

  Paciente paciente;

  int especialidade;
  
  printf("\nAtendimento urgente? (1 - Sim | 0 - Não): ");
  printf("\nR: "); scanf("%d", &paciente.tipoAtendimento);

  printf("Digite o nome do paciente: ");
  printf("\nR: "); scanf("%s", paciente.nomePaciente);
  
  printf("Digite a idade do paciente:");
  printf("\nR: "); scanf("%d", &paciente.idadePaciente);
  
  printf("Que especialidade deve ser chamada? ");
  printf("\n1 - Cardiologista");
  printf("\n2 - Psiquiatra");
  printf("\n3 - Dentista");
  printf("\n4 - Pediatra");
  printf("\n5 - Urologista");
  printf("\nR: "); scanf("%d", &especialidade);

  switch(especialidade){
    case 1:
      strcpy(paciente.especialidade, "Cardiologista");
    break;
    case 2:
      strcpy(paciente.especialidade, "Psiquiatra");
    break;
    case 3:
      strcpy(paciente.especialidade, "Dentista");
    break;
    case 4:
      strcpy(paciente.especialidade, "Pediatra");
    break;
    case 5:
      strcpy(paciente.especialidade, "Urologista");
    break;
  }
  
  return paciente;
  
}

void addPaciente(Fila * fila, Paciente * paciente){
  
  Espera * novoPaciente = (Espera*) malloc(sizeof(Espera));

  paciente -> senha = senha;
  paciente -> idPaciente = senha;
  
  novoPaciente -> paciente = *paciente;
  novoPaciente -> prox = NULL;
  
  if(fila->fim != NULL) // Se o mais recente da fila não estiver fazio, então o proximo do mais recente da fila será o novo paciente
    fila->fim->prox = novoPaciente;
  else // Se o mais recente da fila estiver vazio, então o inicio da fila será o novo
    fila->inicio = novoPaciente;
  
  fila->fim = novoPaciente;
  
}

void listarFila(Fila * fila){
  
  Espera * temp = fila->inicio;
  while(temp != NULL)
    { 
      printf("Nome: %s | Idade: %d | Especialidade: %s | Senha: %d | ID: %d\n", temp->paciente.nomePaciente, temp->paciente.idadePaciente, temp->paciente.especialidade, temp->paciente.senha, temp->paciente.idPaciente);
      temp = temp->prox;
    }

}

int atenderPaciente(Fila * fila, Fila * historico){

  if(Vazia(fila) == 1)
    printf("\nNenhum paciente nas filas\n");
  else{
  
  Espera * temp = fila->inicio;
  // Painel
  printf("Senha: %d | O paciente %s será atendido ", temp->paciente.senha, temp->paciente.nomePaciente);
  printf("\nProcurando médico especialista...");

  Medico * medico;
  
  if(strcmp(temp->paciente.especialidade, "Cardiologista") == 0)
    medico = &Medico1;
  else if(strcmp(temp->paciente.especialidade, "Psiquiatra") == 0)
    medico = &Medico2;
  else if(strcmp(temp->paciente.especialidade, "Dentista") == 0)
    medico = &Medico3;
  else if(strcmp(temp->paciente.especialidade, "Pediatra") == 0)
    medico = &Medico4;
  else if(strcmp(temp->paciente.especialidade, "Urologista") == 0)
    medico = &Medico5;

  if(medico -> atendendo == 1){
    printf("\nO doutor está em atendimento");
  return 0;
  }
  else{

    printf("\nO(a) doutor(a) %s cuidará do paciente", medico -> nomeMedico);
    
    // Apagando paciente da fila e guardando no histórico do painel
    if(fila->inicio->prox == NULL){
      fila->inicio = NULL;
      fila->fim = NULL;
    } else {
      fila->inicio = fila->inicio->prox;
    }
    addPaciente(historico, &temp->paciente); // Adicionando paciente ao histórico
    medico -> atendendo = 1;
    t1 = time(NULL);
    free(temp);
    return 1;
  }
  }
  return 0;
}

void finalizarAtendimento(int * idMedico){
  
    Medico * medico;
  
    switch(*idMedico){
      case 1:
        medico = &Medico1;
      break;
      case 2:
        medico = &Medico2;
      break;
      case 3:
        medico = &Medico3;
      break;
      case 4:
        medico = &Medico4;
      break;
      case 5:
        medico = &Medico5;
      break;
    }
  
  if(medico -> atendendo == 0)
    {
      printf("O doutor não está em atendimento\n");
    }
  
  medico -> atendendo = 0;
  
    t2 = time(NULL);
    double duracao = difftime(t2, t1);
    printf("\nDuração da consulta em segundos: %.2f\n", duracao);
    duracao = 0;
  
}

int main(void) {

  Fila filaUrgente = *filaCria();
  Fila filaPreferencial = *filaCria();
  Fila filaNormal = *filaCria();
  Fila historicoFila = *filaCria();
  
  int opcao, saida = 0;
  int prioridade = 5;

  int tipoAtendimento;
  char nomePaciente[ARR_SIZE];
  int idadePaciente;
  char especialidade[ARR_SIZE];

  printf("O que deseja executar? \n");

  printf("1 - Atender paciente \n");
  printf("2 - Adicionar paciente \n");
  printf("3 - Listar pacientes na fila \n");
  printf("4 - Mostrar histórico \n");
  printf("5 - Finalizar atendimento \n");
  printf("0 - Sair \n");

  while(saida == 0){

    printf("\nR: "); scanf("%d", &opcao);
    
    switch(opcao){

      case 1:
        if(!Vazia(&filaUrgente)){
          atenderPaciente(&filaUrgente, &historicoFila);
          break;
        }
        else{
          if(prioridade == 3){
            atenderPaciente(&filaPreferencial, &historicoFila);
            prioridade = 0;
            break;
          }
          else{
            atenderPaciente(&filaPreferencial, &historicoFila);
            prioridade += 1;
            break;
          }
        }
        if(!Vazia(&filaUrgente) && !Vazia(&filaPreferencial) && !Vazia(&filaNormal)){
          printf("\nNenhum paciente nas filas");
          break;
        }
      break;

      case 2:{

        Paciente paciente = lerPaciente();

        senha += 1;
        
        if(paciente.tipoAtendimento == 1){
          addPaciente(&filaUrgente, &paciente);
          printf("\nPaciente adicionado a fila urgente\n");
        }
        else{
          if(paciente.idadePaciente >= 60){
              addPaciente(&filaPreferencial, &paciente);
              printf("\nPaciente adicionado a fila preferencial\n");
          }
          else{
            addPaciente(&filaNormal, &paciente);
            printf("\nPaciente adicionado a fila normal\n");
          }
          }
        
        }
      break;

      case 3:
        if(!Vazia(&filaNormal)){
        printf("\nFila Convencional:\n");
          listarFila(&filaNormal);
          printf("\n-----------------------------------------------------------------------");
        }
        else printf("\nFila Convencional VAZIA\n");
        if(!Vazia(&filaPreferencial)){
        printf("\nFila Preferencial:\n");
          listarFila(&filaPreferencial);
          printf("\n-----------------------------------------------------------------------");
        }
        else printf("\nFila Preferencial VAZIA\n");
        if(!Vazia(&filaUrgente)){
        printf("\nFila Urgente:\n");
          listarFila(&filaUrgente);
          printf("\n-----------------------------------------------------------------------\n");
        }
        else printf("\nFila Urgente VAZIA\n");
      break;

      case 4:
        if(!Vazia(&historicoFila)){
          printf("\nHistórico de atendimentos:\n");
          listarFila(&historicoFila);
          printf("\n-------------------------------------------------------------------------");
        }
      break;

      case 5:{
        int idMedico;
        
        printf("\nPara qual médico deseja registrar o fim do atendimento?\n");
        
        printf("1 - Jason\n");
        printf("2 - Rafael \n");
        printf("3 - Edleide \n");
        printf("4 - Laís Pitica \n");
        printf("5 - Fernando \n");

        scanf("%d", &idMedico);

        finalizarAtendimento(&idMedico);
      }
      break;

      case 0:
        saida = 1;
      break;
    }
    
  }
  
}
