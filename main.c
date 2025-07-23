#include <stdio.h>

int main(void) {
    
    FILE *fd = fopen("d.txt", "r");
    FILE *fc = fopen("d.txt", "r");
    FILE *fr = fopen("d.txt", "r");
    int tamd, tamc, tamr;
    
    fclose(fd);
    fclose(fc);
    fclose(fr);


    return 0;
}