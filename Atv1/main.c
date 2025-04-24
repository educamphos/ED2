#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30000

// Funcao para gerar vetor aleatorio com valores entre 0 e TAM
void gerar_vetor(int v[]) {
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % (TAM);
    }
}

// Busca sequencial simples
int busca_sequencial(int v[], int chave, int *comparacoes) {
    for (int i = 0; i < TAM; i++) {
        (*comparacoes)++;
        if (v[i] == chave) {
            return i;
        }
    }
    return -1;
}

// Busca sequencial com deslocamento do encontrado para o inicio (move-to-front)
int busca_move_to_front(int v[], int chave, int *comparacoes) {
    for (int i = 0; i < TAM; i++) {
        (*comparacoes)++;
        if (v[i] == chave) {
            // Move para o inicio
            int temp = v[i];
            for (int j = i; j > 0; j--) {
                v[j] = v[j - 1];
            }
            v[0] = temp;
            return 0;
        }
    }
    return -1;
}

// Executa multiplas buscas e imprime a media de comparacoes
void testar_buscas(int v_original[], int num_buscas) {
    int *v1 = malloc(sizeof(int) * TAM);
    int *v2 = malloc(sizeof(int) * TAM);
    int comparacoes1 = 0, comparacoes2 = 0;

    for (int i = 0; i < num_buscas; i++) {
        for (int j = 0; j < TAM; j++) {
            v1[j] = v_original[j];
            v2[j] = v_original[j];
        }

        int chave = rand() % (TAM * 2);

        busca_sequencial(v1, chave, &comparacoes1);
        busca_move_to_front(v2, chave, &comparacoes2);
    }

    printf("Buscas: %d\n", num_buscas);
    printf("Busca sequencial - media de comparacoes: %.2f\n", (float)comparacoes1 / num_buscas);
    printf("Move-to-front     - media de comparacoes: %.2f\n\n", (float)comparacoes2 / num_buscas);

    free(v1);
    free(v2);
}

int main() {
    srand(time(NULL));

    int vetor[TAM];
    gerar_vetor(vetor);

    testar_buscas(vetor, 10);
    testar_buscas(vetor, 100);
    testar_buscas(vetor, 1000);

    return 0;
}
