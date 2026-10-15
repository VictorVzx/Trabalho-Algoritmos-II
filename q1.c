#include <stdio.h>
#include <string.h>

void limpaBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}

// funcao para subsituir a palavra alvo
void substituir(char *frase, char *palavraAlvo, char *novaPalavra) {
    char res[500];
    int i = 0, k = 0, j, m;
    int tam_alvo = 0;

    while (palavraAlvo[tam_alvo] != '\0') {
        tam_alvo++;
    }

    while (frase[i] != '\0') {
        if ((frase[i] >= 'a' && frase[i] <= 'z') || (frase[i] >= 'A' && frase[i] <= 'Z')) {
            int inicio = i;

            // anda até o fim da palavra
            while ((frase[i] >= 'a' && frase[i] <= 'z') || (frase[i] >= 'A' && frase[i] <= 'Z')) {
                i++;
            }
            int tam = i - inicio;

            // compara com o alvo
            int igual = 1;
            if (tam != tam_alvo) {
                igual = 0;
            } else {
                for (j = 0; j < tam; j++) {
                    if (frase[inicio + j] != palavraAlvo[j]) {
                        igual = 0;
                    }
                }
            }

            if (igual == 1) {
                for (m = 0; novaPalavra[m] != '\0'; m++) {
                    res[k] = novaPalavra[m];
                    k++;
                }
            } else {
                for (m = inicio; m < i; m++) {
                    res[k] = frase[m];
                    k++;
                }
            }
        } else {
            res[k] = frase[i];
            k++;
            i++;
        }
    }
    res[k] = '\0';

    // copia o resultado de volta para a frase
    i = 0;
    while (res[i] != '\0') {
        frase[i] = res[i];
        i++;
    }
    frase[i] = '\0';
}

void removerNewline(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

int main(){
    char frase[100], palavraAlvo[30], novaPalavra[30];
    
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Digite uma palavra alvo: ");
    fgets(palavraAlvo, sizeof(palavraAlvo), stdin);
    removerNewline(palavraAlvo);

    printf("Digite uma nova palavra: ");
    fgets(novaPalavra, sizeof(novaPalavra), stdin);
    removerNewline(novaPalavra);

    printf("[Antes]: %s", frase);

    substituir(frase, palavraAlvo, novaPalavra);

    printf("[Depois]: %s", frase);

    return 0;
    
}