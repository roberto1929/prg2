//
// Created by eliaz on 10/08/2023.
//

#include "exercicio_3.h"

#include <stdio.h>

int terceiro_ex() {
    int numeros[10];
    int pares = 0, impares = 0, positivos = 0, negativos = 0;

    printf("Digite 10 números inteiros:\n");

    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);

        if (numeros[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }

        if (numeros[i] > 0) {
            positivos++;
        } else if (numeros[i] < 0) {
            negativos++;
        }
    }

    printf("\nQuantidade de números pares: %d\n", pares);
    printf("Quantidade de números ímpares: %d\n", impares);
    printf("Quantidade de números positivos: %d\n", positivos);
    printf("Quantidade de números negativos: %d\n", negativos);

    return 0;
}
