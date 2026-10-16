#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipo da função (declarada fora do main)
void preencherDicas(int L, int C, int matriz[L][C]);

int main () {

    int i, j, n, m; // Alterado para int para bater com %d

    printf ("Escolha o tamanho M de um campo minado MxN: ");
    scanf ("%d", &m);
    printf ("Escolha o tamanho N de um campo minado MxN: ");
    scanf ("%d", &n);

    int campoMinado[m][n];
    srand (time(NULL));

    // Preenche as bombas
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (rand() % 100 < 35){ 
                campoMinado[i][j] = -1;
            }
            else {
                campoMinado[i][j] = 0;
            }
        }
    }

    // CHAMADA DA FUNÇÃO
    preencherDicas(m, n, campoMinado);

    // Impressão do resultado final com alinhamento
    printf ("\n--- CAMPO MINADO RESULTANTE ---\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf ("%3d", campoMinado[i][j]);
        }
        printf ("\n");
    }

    return 0;
}

// IMPLEMENTAÇÃO DA SUA FUNÇÃO (Fora do main)
void preencherDicas(int L, int C, int matriz[L][C]) {

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) { // Corrigido: j = 0

            // Verifica se a célula atual é livre
            if (matriz[i][j] == 0) { // Corrigido: matriz[i][j]
                int bombas = 0;

                // Loops de vizinhança (usando vi e vj para não conflitar com m e n)
                for (int vi = i - 1; vi <= i + 1; vi++) {
                    for (int vj = j - 1; vj <= j + 1; vj++) {

                        // Validação de bordas (garante que o vizinho existe)
                        if (vi >= 0 && vi < L && vj >= 0 && vj < C) {
                            
                            // Ignora a própria célula central
                            if (vi == i && vj == j) continue;

                            // Compara com == em vez de =
                            if (matriz[vi][vj] == -1) { 
                                bombas++;
                            }
                        }
                    }
                }
                
                // Atualiza o valor apenas das células 0
                matriz[i][j] = bombas;
            }
        }
    }
}