#include <stdio.h>

void somaLinha (int X, int array3[X][X][X]);
void lerMatriz(int X, int array3[X][X][X]);
int somaAbsoluta (int X, int array3[X][X][X]); 
void filtroValores (int somaAbs, int X, int array3[X][X][X]);
void exibirMatriz(int N, int matriz[N][N][N]); 

int main () {
    int N;
    printf("Digite a dimensão N da matriz (NxNxN): ");
    scanf("%d", &N);
    int matriz[N][N][N];

    lerMatriz (N, matriz);
    somaLinha (N, matriz);
    somaAbsoluta (N, matriz);
    int somatorioAbsoluto;
    filtroValores (somatorioAbsoluto, N, matriz);
    exibirMatriz(N, matriz);

    return 0;
}

//\Função ler matriz
void lerMatriz(int X, int array3[X][X][X]) {
    printf("\nDigite os elementos da matriz %dx%dx%d:\n", X, X, X);
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++) {
            for (int k = 0; k < X; k++) {
                printf("Matriz[%d][%d][%d]: ", i, j, k);
                scanf("%d", &array3[i][j][k]);
            }
        }
    }

}

//Somatorio de cada linha.
void somaLinha (int X, int array3[X][X][X]) {
    int somatorioLinha = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++) {
            for (int k = 0; k < X; k++) {
                somatorioLinha += array3[i][j][k];
            }
            printf ("\nSoma da linha %d: %d", j + 1, somatorioLinha);
        }
    }
}    
// Função que faz a soma absoluta de todos os elementos da matriz.
int somaAbsoluta (int X, int array3[X][X][X]) {
    int somatorioAbsoluto = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++) {
            for (int k = 0; k < X; k++) {
                somatorioAbsoluto += array3[i][j][k];
            }
        }
    }
    printf ("\nSoma absoluta da matriz tridimensional: %d", somatorioAbsoluto);
    return somatorioAbsoluto;
}
// Função que imprime a quantidade de número positivos da matriz.
void positivosQntd (int X, int array3[X][X][X]) {
    int somatorioPositivos = 0;
      for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++) {
            for (int k = 0; k < X; k++) {
                if (array3[i][j][k] > 0) {
                    somatorioPositivos += array3[i][j][k];
                }    
            }
        }
    }
    printf ("\nQuantidade de positivos da matriz tridimensional: %d", somatorioPositivos);
}

// Função filtro de valores.
void filtroValores (int somaAbs, int X, int array3[X][X][X]) {
      for (int i = 0; i < X; i++) {
        for (int j = 0; j < X; j++) {
            for (int k = 0; k < X; k++) {
                if (array3[i][j][k] < somaAbs) {
                    array3[i][j][k] = 0;
                }    
            }
        }
    }
}

void exibirMatriz(int N, int matriz[N][N][N]) {
    printf("\n=== EXIBIÇÃO DA MATRIZ TRIDIMENSIONAL (%dx%dx%d) ===\n", N, N, N);
    
    for (int i = 0; i < N; i++) {
        printf("\n--- CAMADA %d ---\n", i + 1); // Exibe a camada atual (1 a N)
        
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                // Formatação com %4d para manter as colunas alinhadas
                printf("%4d ", matriz[i][j][k]);
            }
            printf("\n"); // Quebra de linha ao final de cada linha da camada
        }
    }
    printf("\n==================================================\n");
}