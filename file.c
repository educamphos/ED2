#include "file.h"

int contarElementos(FILE *arq) {
    int numero, count = 0;
    while (fscanf(arq, "%d", &numero) == 1) {
        count++;
    }
    rewind(arq);
    return count;
}