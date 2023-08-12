//
// Created by eliaz on 12/08/2023.
//

#include "exercicio_6.h"
#include <stdio.h>

int sexto_ex() {
    int matriz[10][10]; // Declarando a matriz 10x10


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = 0;
        }
    }


    for (int i = 0; i < 10; i++) {
        matriz[i][i] = 1;
    }


    printf("Matriz Identidade 10x10:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
