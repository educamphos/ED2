#include "bolha.h"
#include "menu.h"

int main(void) {
    
    //abre arquivos
    FILE *fd = fopen("d", "r");
    FILE *fc = fopen("c", "r");
    FILE *fr = fopen("r", "r");


    //pega o tamanho do vetor
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


    //reseta os ponteiros
    fclose(fd);
    fd = fopen("d", "r");

    fclose(fc);
    fc = fopen("c", "r");

    fclose(fr);
    fr = fopen("r", "r");

    //le os arquivos
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

    int vetorAux1[tamc];

    copiaVetor(listaC, vetorAux1, tamc);
    ordenarmentoBolha(vetorAux1, tamc);
    mostrarVetor(vetorAux1, tamc);
    //ordenarmentoBolha(vetorAux1, tamr);
    //mostrarVetor(vetorAux1, tamr);

    //mostrarVetor(listaR, tamr);
    //ordenarmentoBolha(listaR, tamr);
    //mostrarVetor(listaR, tamr);

    return 0;
}