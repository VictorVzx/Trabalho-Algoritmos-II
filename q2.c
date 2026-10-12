#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDANTES 100
#define MAX_FUNCIONARIOS 100

typedef struct {
    char primeiroNome[50];
    char ultimoNome[50];
    float rendimentoAcademico;
} Estudante;

typedef struct {
    char primeiroNome[50];
    char ultimoNome[50];
    double salario;
} Funcionario;

void menuInterface(){
    system("clear");
    printf("+---------------------------------------------+\n");
    printf("|      CADASTRO DE ALUNOS E FUNCIONARIOS      |\n");
    printf("+---------------------------------------------+\n");
    printf("|  1. Cadastrar Estudante                     |\n");
    printf("|  2. Cadastrar Funcionario                   |\n");
    printf("|  3. Ver todos os Estudantes                 |\n");
    printf("|  4. Ver todos os Funcionarios               |\n");
    printf("|  5. Ver dados de um Funcionario             |\n");
    printf("|  6. Ver dados de um Estudante               |\n");
    printf("+---------------------------------------------+\n");
    printf("Opcao: ");
}

void cadastrarEstudante(Estudante *vetor, int *qtd){
    int contEstudantes = *qtd;

    for(int i = 0; i < contEstudantes; i++){
        for(int j=i+1; j < contEstudantes; j++){
            do{
                printf("Digite o primeiro nome do estudante: ");
                scanf("%s", vetor[contEstudantes].primeiroNome);

                printf("Digite o ultimo nome do estudante: ");
                scanf("%s", vetor[contEstudantes].ultimoNome);

                printf("Digite o rendimento academico do estudante: ");
                scanf("%f", &vetor[contEstudantes].rendimentoAcademico);

                (*qtd)++;

                if(strcmp(vetor[i].primeiroNome, vetor[j].primeiroNome) == 0 && strcmp(vetor[i].ultimoNome, vetor[j].ultimoNome) == 0){
                    printf("Este estudante já existe, tente novamente.");
                }
                
            }while(strcmp(vetor[i].primeiroNome, vetor[j].primeiroNome) != 0 && strcmp(vetor[i].ultimoNome, vetor[j].ultimoNome)!= 0);
        }
    }
}

void cadastrarFuncionario(Funcionario *vetor, int *qtd){
    int contFuncionarios = *qtd;

    for(int i = 0; i < contFuncionarios; i++){
        for(int j = i+1; j < contFuncionarios; j++){
            do{
                printf("Digite o primeiro nome do funcionario: ");
                scanf("%s", vetor[contFuncionarios].primeiroNome);

                printf("Digite o ultimo nome do funcionario: ");
                scanf("%s", vetor[contFuncionarios].ultimoNome);

                printf("Digite o salario do funcionario: ");
                scanf("%lf", &vetor[contFuncionarios].salario);

                (*qtd)++;

                if(strcmp(vetor[i].primeiroNome, vetor[j].primeiroNome) == 0 && strcmp(vetor[i].ultimoNome, vetor[j].ultimoNome)== 0){
                    printf("Este funcionário já existe, tente novamente.");
                }

            }while(strcmp(vetor[i].primeiroNome, vetor[j].primeiroNome) != 0 && strcmp(vetor[i].ultimoNome, vetor[j].ultimoNome)!= 0);
        }
    }
}

void mostrarTodosEstudantes(Estudante *estudantes, int *qtdEstudantes){
    for(int i = 0; i < *qtdEstudantes; i++){
        printf("Primeiro nome: %s", estudantes[i].primeiroNome);
        printf("Ultimo nome: %s", estudantes[i].ultimoNome);
        printf("Rendimento academico: %.1f", estudantes[i].rendimentoAcademico);
    }
}

void mostrarTodosFuncinarios(Funcionario *funcionarios, int *qtdFuncionarios){
    for(int i = 0; i < *qtdFuncionarios; i++){
        printf("Primeiro nome: %s", funcionarios[i].primeiroNome);
        printf("Ultimo nome: %s", funcionarios[i].ultimoNome);
        printf("Salario: %.2lf", funcionarios[i].salario);
    }
}

int main(){
    Estudante estudantes[MAX_ESTUDANTES];

    int qtdEstudantes = 0;
    int qtdFuncionarios = 0;


    cadastrarEstudante(estudantes, &qtdEstudantes);

    printf("%d", qtdEstudantes);

    return 0;
}