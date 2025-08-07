#include "menu.h"

void mostrarVetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
        printf("\n");
    }
    printf("\nfim");
}

void copiaVetor(int *origem, int *destino, int tam) {
    for (int i = 0; i < tam; i++) {
        destino[i] = origem[i];
        
    }
}