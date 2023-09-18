//
// Created by aluno on 29/08/23.
//
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include <stdio.h>

int matriz_adicao(void){

    int linha = 3, coluna = 4;

    srand(time(NULL));

    int** mat = (int**) calloc(linha, sizeof(int*));
    for (int i = 0; i < linha; ++i) {
        mat[i] =  (int*) calloc(coluna, sizeof(int *));
    }
    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            mat[i][j] = (rand() % 10);
        }
    }

    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            printf("a[%d][%d]: %d ", i, j, mat[i][j]);
        }
    }
    return 0;
}