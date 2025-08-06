#include "bolha.h"
#include "menu.h"

int main(void) {
    
    FILE *fd = fopen("d", "r");
    FILE *fc = fopen("c", "r");
    FILE *fr = fopen("r", "r");
    int tamd=0, tamc=0, tamr=0;
    int numero;
    while (fscanf(fd, "%d", &numero) == 1) {
        tamd++;
    }
    while (fscanf(fc, "%d", &numero) == 1) {
        tamc++;
    }
    while (fscanf(fr, "%d", &numero) == 1) {
        tamr++;
    }
    
    int *listaR = malloc(tamr * sizeof(int));
    int *listaC = malloc(tamc * sizeof(int));
    int *listaD = malloc(tamd * sizeof(int));

    fclose(fd);
    fd = fopen("d", "r");

    fclose(fc);
    fc = fopen("c", "r");

    fclose(fr);
    fr = fopen("r", "r");


    for(int i = 0; i < tamr; i++) {
        fscanf(fr, "%d", &listaR[i]);
    }
    for(int i = 0; i < tamc; i++) {
        fscanf(fc, "%d", &listaC[i]);
    }
    for(int i = 0; i < tamd; i++) {
        fscanf(fd, "%d", &listaD[i]);
    }

    fclose(fd);
    fclose(fc);
    fclose(fr);

    //mostrarVetor(listaR, tamr);
    ordenarmentoBolha(listaR, tamr);
    mostrarVetor(listaR, tamr);

    return 0;
}