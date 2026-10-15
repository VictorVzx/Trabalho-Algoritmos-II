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
    printf("|  7. SAIR                                    |\n");
    printf("+---------------------------------------------+\n");
    printf("Opcao: ");
}

void aguardarEnter(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
    printf("\nPressione Enter para voltar ao menu...");
    getchar();
}

void cadastrarEstudante(Estudante *vetor, int *qtd){

    if(*qtd == MAX_ESTUDANTES){
        system("clear");
        printf("Número máximo de estudantes cadastrados, não é possível cadastrar mais estudantes.\n");
        aguardarEnter();
        return;
    }

    int contEstudantes = *qtd;
    int exists = 0;

    char nomeAux[50], segundoNomeAux[50];
    float rendimentoAux;

    do{
        exists = 0;
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
            (*qtd)++;
        }

    }while(exists == 1);
}

void cadastrarFuncionario(Funcionario *vetor, int *qtd){
    if(*qtd == MAX_FUNCIONARIOS){
        system("clear");
        printf("Número máximo de funcionarios cadastrados, não é possivel cadastrar mais funcionarios.\n");
        aguardarEnter();
        return;
    }

    // logica de contar funcionarios e estudantes para inserir na ultima posicao do vetor
    int contFuncionarios = *qtd;
    int exists = 0;

    char nomeAux[50], segundoNomeAux[50];
    double salarioAux;
   
    do{
        exists = 0;
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
            (*qtd)++;
        }

    }while(exists == 1);
}

void mostrarTodosEstudantes(Estudante *estudantes, int *qtdEstudantes){
    if(*qtdEstudantes == 0){
        printf("Nenhum estudante cadastrado.\n");
        return;
    }

    for(int i = 0; i < *qtdEstudantes; i++){
        printf("Estudante %d\n", i+1);
        printf("Primeiro nome: %s\n", estudantes[i].primeiroNome);
        printf("Ultimo nome: %s\n", estudantes[i].ultimoNome);
        printf("Rendimento academico: %.1f\n", estudantes[i].rendimentoAcademico);
    }
}


void mostrarTodosFuncionarios(Funcionario *funcionarios, int *qtdFuncionarios){
    if(*qtdFuncionarios == 0){
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    for(int i = 0; i < *qtdFuncionarios; i++){
        printf("Funcionario %d\n", i+1);
        printf("Primeiro nome: %s\n", funcionarios[i].primeiroNome);
        printf("Ultimo nome: %s\n", funcionarios[i].ultimoNome);
        printf("Salario: %.2lf\n", funcionarios[i].salario);
    }
}

void mostrarUmEstudante(Estudante *vetor, int *qtd){
    int exists = 0;

    char nome[50], ultimoNome[50];

    do{
        exists = 0;
        printf("\n--- Buscar estudante (SAIR para sair)---\n");
        printf("Primeiro nome: ");
        scanf("%s", nome);
        printf("Ultimo nome: ");
        scanf("%s", ultimoNome);

        if(strcmp(nome, "SAIR") == 0 || strcmp(ultimoNome, "SAIR") == 0){
            return;
        }

        for(int i = 0; i < *qtd; i++){
            if(strcmp(vetor[i].primeiroNome, nome) == 0 && strcmp(vetor[i].ultimoNome, ultimoNome) == 0){
                exists = 1;
                printf("\n+----------------------------------+\n");
                printf("|       DADOS DO ESTUDANTE         |\n");
                printf("+----------------------------------+\n");
                printf("| Primeiro nome: %s                |\n", vetor[i].primeiroNome);
                printf("| Ultimo nome:   %s                |\n", vetor[i].ultimoNome);
                printf("| Rendimento:    %.1f              |\n", vetor[i].rendimentoAcademico);
                printf("+----------------------------------+\n");
            }
        }
    
        if(exists == 0){
            system("clear");
            printf("\nEstudante não encontrado, tente novamente\n");
        }
        

    }while(exists == 0);
}

void mostrarUmFuncionario(Funcionario *vetor, int *qtd){
    int exists = 0;

    char nome[50], ultimoNome[50];

    do{
        printf("\n--- Buscar funcionario (SAIR para sair)---\n");
        printf("Primeiro nome: ");
        scanf("%s", nome);
        printf("Ultimo nome: ");
        scanf("%s", ultimoNome);

        // sai da funcao (retorna o vazio)
        if(strcmp(nome, "SAIR") == 0 || strcmp(ultimoNome, "SAIR") == 0){
            return;
        }

        for(int i = 0; i < *qtd; i++){
            if(strcmp(vetor[i].primeiroNome, nome) == 0 && strcmp(vetor[i].ultimoNome, ultimoNome) == 0){
                exists = 1;
                printf("\n+----------------------------------+\n");
                printf("|      DADOS DO FUNCIONARIO        |\n");
                printf("+----------------------------------+\n");
                printf("| Primeiro nome: %s                |\n", vetor[i].primeiroNome);
                printf("| Ultimo nome:   %s                |\n", vetor[i].ultimoNome);
                printf("| Salario:       R$ %.2lf          |\n", vetor[i].salario);
                printf("+----------------------------------+\n");
            }
        }
    
        if(exists == 0){
            system("clear");
            printf("Funcionario não encontrado, tente novamente\n");
        }

    }while(exists == 0);
}

int main(){
    // vetores de funcionarios e estudantes
    Estudante estudantes[MAX_ESTUDANTES];
    Funcionario funcionarios[MAX_FUNCIONARIOS];

    int qtdEstudantes = 0;
    int qtdFuncionarios = 0;

    int option;

    do{
        do{
            menuInterface();
            scanf("%d", &option);
    
            if(option < 1 || option > 7){
                system("clear");
                printf("Entrada inválida, tente novamente\n");
                aguardarEnter();
            }
    
        }while(option < 1 || option > 7);

        switch(option){
            case 1: 
                cadastrarEstudante(estudantes, &qtdEstudantes);
                break;
            case 2: 
                cadastrarFuncionario(funcionarios, &qtdFuncionarios); 
                break;
            case 3:
                mostrarTodosEstudantes(estudantes, &qtdEstudantes);
                aguardarEnter();
                break;
            case 4: 
                mostrarTodosFuncionarios(funcionarios, &qtdFuncionarios); 
                aguardarEnter();
                break;
            case 5: 
                mostrarUmEstudante(estudantes, &qtdEstudantes);
                aguardarEnter();
                break;
            case 6: 
                mostrarUmFuncionario(funcionarios, &qtdFuncionarios);
                aguardarEnter();
                break;
            case 7: 
                system("clear"); 
                printf("Programa encerrado.\n"); 
                break;
            default: 
                printf("Invalido\n");
                break;
        }
    }while(option != 7);

    return 0;
}
