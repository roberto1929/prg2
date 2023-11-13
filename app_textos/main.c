#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(void) {
    FILE *file = fopen("texto.txt", "w");

    if(file == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    for (int i = 0; i < INTMAX_MAX; i++) {
        fprintf(file, "%d\n", i);
    }

    fclose(file);

    printf("Arquivo gerado com sucesso, texto.txt");


    return 0;
}
