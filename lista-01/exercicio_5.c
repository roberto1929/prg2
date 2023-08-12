//
// Created by eliaz on 12/08/2023.
//

#include "exercicio_5.h"
#include <stdio.h>

int encontrarElementoFaltando(int vetor[], int n) {
    int total = (n * (n + 1)) / 2;

    for (int i = 0; i < n - 1; i++) {
        total -= vetor[i];
    }

    return total;
}

int quinto_ex() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int vetor[n - 1];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &vetor[i]);
    }

    int elementoFaltando = encontrarElementoFaltando(vetor, n);
    printf("O elemento faltando é: %d\n", elementoFaltando);

    return 0;
}
