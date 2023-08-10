//
// Created by eliaz on 10/08/2023.
//

#include "exercicio_2.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int segundo_ex(void) {
    int numeroSorteado, numeroUsuario;

    /* Iniciando a semente pseudo aleatória */
    srand((unsigned)time(NULL));
    numeroSorteado = rand() % 10 + 1; /* Fazendo o sorteio entre 1 e 10 */

    printf("Digite um número entre 1 e 10: ");
    scanf("%d", &numeroUsuario);

    if (numeroUsuario == numeroSorteado) {
        printf("Parabéns, você acertou!\n");
    } else {
        printf("Tente outra vez.\n");
    }

    return 0;
}