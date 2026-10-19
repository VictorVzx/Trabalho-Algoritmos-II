#include <stdio.h>

typedef struct {
    char tipo;        // 'L' para linha ou 'C' para coluna
    int indice;       // Indice da linha ou coluna (iniciando em 0)
    int totalColhido; // Quantidade total de minhocas
} MelhorPassada;

MelhorPassada encontrarMelhorPassada(int L, int C, int campo[L][C]); // Chama a função.

int main() {
    int L, C;

    // Leitura das dimensões do campo
    printf ("Digite o tamanho L do campo LxC: ");
    scanf("%d", &L);
    printf ("\nDigite o tamanho C do campo LxC: ");
    scanf("%d", &C);
    
    while (L > 20 || C > 20 || L <= 0 || C <= 0) {// Verifica se as condições de existÊncia do campo.
        printf ("O L e C deve ser menor ou igual a 20 e maiores que 0.\n");
        printf ("Digite o tamanho L do campo LxC: ");
        scanf("%d", &L);
        printf ("\nDigite o tamanho C do campo LxC: ");
        scanf("%d", &C);
    }

    int campoMinhoca[L][C]; // Cria a matriz do campo

    // Preenchemento da matriz com as minhocas sem aceitar valores negativos.
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf ("\nQuantidade de minhocas na posição %dx%d do campo:", i + 1, j + 1);
            scanf("%d", &campoMinhoca[i][j]);
            while (campoMinhoca[i][j] < 0){
                printf ("\nERRO!: O valor digitado não pode ser negativo, digite outro número novamente.");
                printf ("\nQuantidade de minhocas na posição %dx%d do campo:", i + 1, j + 1);
                scanf("%d", &campoMinhoca[i][j]);
            }
        }
    }

    // Processamento
    MelhorPassada resultado = encontrarMelhorPassada(L, C, campoMinhoca);

    // Impressão do resultado
    printf("Tipo: %c\n", resultado.tipo);
    printf("Indice: %d\n", resultado.indice);
    printf("Total colhido: %d\n", resultado.totalColhido);

    return 0;
}

MelhorPassada encontrarMelhorPassada(int L, int C, int campo[L][C]) {
    MelhorPassada melhor;
    melhor.tipo = 'L';
    melhor.indice = 0;
    melhor.totalColhido = 0; // Começa com um valor menor que qualquer soma

    // 1. Verifica todas as linhas
    for (int i = 0; i < L; i++) {
        int somaLinha = 0; // A cada contagem de soma da linha o contador é zerado.
        for (int j = 0; j < C; j++) {
            somaLinha += campo[i][j]; // Faz o somatório da linha.
        }

        // Estritamente maior para garantir que o menor índice (o primeiro a ser emcontrado como sendo o maior) tenha prioridade em caso de empate.
        if (somaLinha > melhor.totalColhido) { // Se fosse >= iria pegar a melhor colheita de maior índice. 
            melhor.totalColhido = somaLinha;
            melhor.tipo = 'L';
            melhor.indice = i; // Armazena o índice da iteração atual.
        }
    }

    // 2. Verifica todas as colunas
    for (int j = 0; j < C; j++) {
        int somaColuna = 0;
        for (int i = 0; i < L; i++) {
            somaColuna += campo[i][j];
        }

        // Estritamente maior garante que:
        // - 'L' tenha prioridade sobre 'C' em caso de empate (pois somaColuna não supera a somaLinha se for igual), então o tipo da melhor colheita continua sendo L.
        // - O menor índice da coluna tenha prioridade em caso de empate
        if (somaColuna > melhor.totalColhido) {
            melhor.totalColhido = somaColuna;
            melhor.tipo = 'C';
            melhor.indice = j;
        }
    }

    return melhor;
}