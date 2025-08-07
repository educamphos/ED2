#include "bolha.h"
#include "menu.h"
#include "file.h"



int main(void) {
    

    // Abre arquivos
    FILE *fd = fopen("d", "r");
    FILE *fc = fopen("c", "r");
    FILE *fr = fopen("r", "r");

    if (!fd || !fc || !fr) {
        perror("Erro ao abrir arquivos");
        return 1;
    }

    // Conta elementos
    int tamd = contarElementos(fd);
    int tamc = contarElementos(fc);
    int tamr = contarElementos(fr);

    // Verifica se todos têm dados
    if (tamd <= 0 || tamc <= 0 || tamr <= 0) {
        fprintf(stderr, "Erro: um dos arquivos está vazio ou inválido.\n");
        fclose(fd);
        fclose(fc);
        fclose(fr);
        return 1;
    }

    // Aloca vetores dinamicamente
    int *listaD = malloc(tamd * sizeof(int));
    int *listaC = malloc(tamc * sizeof(int));
    int *listaR = malloc(tamr * sizeof(int));
 

    if (!listaD || !listaC || !listaR) {
        perror("Erro ao alocar memória");
        fclose(fd);
        fclose(fc);
        fclose(fr);
        free(listaD);
        free(listaC);
        free(listaR);
        return 1;
    }

    // Lê dados para os vetores
    for (int i = 0; i < tamd; i++) fscanf(fd, "%d", &listaD[i]);
    for (int i = 0; i < tamc; i++) fscanf(fc, "%d", &listaC[i]);
    for (int i = 0; i < tamr; i++) fscanf(fr, "%d", &listaR[i]);

    
    int *vetorAux1 = listaR;
    int tam = tamr;
    int *vetorAux2 = malloc(tam * sizeof(int));


    copiaVetor(vetorAux1, vetorAux2, tam);
    printf("copiado\n");
    ordenamentoBolhaCriterioParada(vetorAux2, tam);
    printf("trocas: %" PRIu64 "\n", trocas);
    //mostrarVetor(vetorAux2, tam);
    
    return 0;
}