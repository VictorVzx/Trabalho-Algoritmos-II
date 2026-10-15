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
    printf("|  5. Ver dados de um Estudante               |\n");
    printf("|  6. Ver dados de um Funcionario             |\n");
    printf("+---------------------------------------------+\n");
    printf("Opcao: ");
}

void cadastrarEstudante(Estudante *vetor, int *qtd){
    int contEstudantes = *qtd;
    int exists = 0;

    char nomeAux[50], segundoNomeAux[50];
    float rendimentoAux;

    do{
        printf("Digite o nome do aluno: ");
        scanf("%s", nomeAux);
        printf("Digite o ultimo nome do aluno: ");
        scanf("%s", segundoNomeAux);
        printf("Digite o rendimento academico do aluno: ");
        scanf("%f", &rendimentoAux);
    
        if(contEstudantes > 0){
            for(int i = 0; i < contEstudantes; i++){
                if(strcmp(vetor[i].primeiroNome, nomeAux) == 0 && strcmp(vetor[i].ultimoNome, segundoNomeAux) == 0){
                    exists = 1;
                }
            }
        }

        if(exists == 1){
            printf("Este estudante já está cadastrado, tente novamente.\n");
        }else{
            strcpy(vetor[contEstudantes].primeiroNome, nomeAux);
            strcpy(vetor[contEstudantes].ultimoNome, segundoNomeAux);
            vetor[contEstudantes].rendimentoAcademico = rendimentoAux;
        }

    }while(exists == 1);
}

void cadastrarFuncionario(Funcionario *vetor, int *qtd){
    int contFuncionarios = *qtd;
    int exists = 0;

    char nomeAux[50], segundoNomeAux[50];
    double salarioAux;
   
    do{
        printf("Digite o nome do funcionario: ");
        scanf("%s", nomeAux);
        printf("Digite o ultimo nome do funcionario: ");
        scanf("%s", segundoNomeAux);
        printf("Digite o salario do funcionario: ");
        scanf("%lf", &salarioAux);
    
        if(contFuncionarios > 0){
            for(int i = 0; i < contFuncionarios; i++){
                if(strcmp(vetor[i].primeiroNome, nomeAux) == 0 && strcmp(vetor[i].ultimoNome, segundoNomeAux) == 0){
                    exists = 1;
                }
            }
        }

        if(exists == 1){
            system("clear");
            printf("Este funcionario já está cadastrado, tente novamente.\n");
        }else{
            strcpy(vetor[contFuncionarios].primeiroNome, nomeAux);
            strcpy(vetor[contFuncionarios].ultimoNome, segundoNomeAux);
            vetor[contFuncionarios].salario = salarioAux;
        }

    }while(exists == 1);
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

void mostrarUmEstudante(Estudante *vetor, int *qtd){
    int exists = 0;

    char nome[50], ultimoNome[50];

    do{
        printf("Digite o primeiro nome do estudante que deseja buscar: ");
        scanf("%s", nome);
        pritnf("Digite o ultimo nome do estudante que deseja buscar: ");
        scanf("%s", ultimoNome);

        for(int i = 0; i < *qtd; i++){
            if(strcmp(vetor[i].primeiroNome, nome) == 0 && strcmp(vetor[i].ultimoNome, ultimoNome) == 0){
                exists = 1;
                printf("Primeiro nome: %s\n", vetor[i].primeiroNome);
                printf("Ultimo nome: %s", vetor[i].ultimoNome);
                printf("Rendimento academico: %.1f", vetor[i].rendimentoAcademico);
            }
        }
    
        if(exists == 0){
            system("clear");
            printf("Estudante não encontrado, tente novamente\n");
        }

    }while(exists == 0);
}

void mostrarUmFuncionario(Funcionario *vetor, int *qtd){
    int exists = 0;

    char nome[50], ultimoNome[50];

    do{
        printf("Digite o primeiro nome do funcionario que deseja buscar: ");
        scanf("%s", nome);
        pritnf("Digite o ultimo nome do funcionario que deseja buscar: ");
        scanf("%s", ultimoNome);

        for(int i = 0; i < *qtd; i++){
            if(strcmp(vetor[i].primeiroNome, nome) == 0 && strcmp(vetor[i].ultimoNome, ultimoNome) == 0){
                exists = 1;
                printf("Primeiro nome: %s\n", vetor[i].primeiroNome);
                printf("Ultimo nome: %s", vetor[i].ultimoNome);
                printf("Rendimento academico: %.2lf", vetor[i].salario);
            }
        }
    
        if(exists == 0){
            system("clear");
            printf("Funcionario não encontrado, tente novamente\n");
        }

    }while(exists == 0);
}

int main(){
    Estudante estudantes[MAX_ESTUDANTES];

    int qtdEstudantes = 0;
    int qtdFuncionarios = 0;


    cadastrarEstudante(estudantes, &qtdEstudantes);

    printf("%d", qtdEstudantes);

    return 0;
}