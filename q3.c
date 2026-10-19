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
            if (rand() % 100 < 39){ // rand retorna números "aleatórios" juntamento o % 100 retringe em 100 possíveis resultados (0 à 99), apenas 39 números(contando com 0) são menores que 39, isso gera uma proporção de 39/100, gerando uma restrição de possibilidade de 39%.
                campoMinado[i][j] = -1; // 39% da matriz valerá 
            }
            else {
                campoMinado[i][j] = 0; // Os 61% restante valerá 0.
            }
        }
    }

    // CHAMADA DA FUNÇÃO:
    preencherDicas(m, n, campoMinado);

    // Impressão do resultado final com alinhamento.
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
        for (int j = 0; j < C; j++) { //

            // Verifica se a célula atual é livre
            if (matriz[i][j] == 0) {
                int bombas = 0; // Cada linha faz o somatório das bombas vinzinhas

                // Loops de vizinhança (usando vi e vj para não conflitar com m e n)
                for (int vi = i - 1; vi <= i + 1; vi++) {
                    for (int vj = j - 1; vj <= j + 1; vj++) {

                        // Validação de bordas (garante que o vizinho existe)
                        if (vi >= 0 && vi < L && vj >= 0 && vj < C) {
                            
                            // Ignora a própria célula central, evitando processamento e checagem desnecessária da própria célula que também. está necessariamente zerada (aepnas uma boa prática).
                            if (vi == i && vj == j) continue; 

                            // Faz a contagem das bombas vizinhas.
                            if (matriz[vi][vj] == -1) { 
                                bombas++;
                            }
                        }
                    }
                }
                
                // Atualiza o valor apenas das células 0 para a quantidade de bombas vizinhas.
                matriz[i][j] = bombas;
            }
        }
    }
}