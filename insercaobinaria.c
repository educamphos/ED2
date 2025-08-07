#include "template.h"

// Função auxiliar: busca binária para encontrar posição de inserção
int buscaBinaria(int *v, int item, int low, int high) {
    if (high <= low)
        return (item > v[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == v[mid])
        return mid + 1;

    if (item > v[mid])
        return buscaBinaria(v, item, mid + 1, high);
    return buscaBinaria(v, item, low, mid - 1);
}

void insercaoBinaria(int *v, int n) {
    int i, loc, j, key;

    for (i = 1; i < n; i++) {
        key = v[i];
        // Busca posição para inserir key
        loc = buscaBinaria(v, key, 0, i - 1);

        // Move os elementos para a direita para abrir espaço
        j = i - 1;
        while (j >= loc) {
            v[j + 1] = v[j];
            j--;
        }

        v[loc] = key;
    }
}
