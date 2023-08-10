//
// Created by eliaz on 10/08/2023.
//

#include "exercicio_4.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quarto_ex() {
    srand(time(NULL));

    int numeroSorteado = rand() % 100 + 1;
    int tentativas = 0;
    int ultimoPalpite = 0;
    int palpite;

    printf("Bem-vindo ao Jogo de Azar!\n");
    printf("Tente adivinhar o número sorteado entre 1 e 100.\n");

    do {
        printf("Digite o seu palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite == numeroSorteado) {
            printf("Parabéns, você acertou o número %d em %d tentativas!\n", numeroSorteado, tentativas);
            break;
        } else {
            if (palpite == ultimoPalpite) {
                printf("Você já escolheu %d vezes o número %d, tente outro número.\n", tentativas, palpite);
            } else if (palpite < numeroSorteado) {
                printf("Tente outra vez. O número sorteado é maior que %d.\n", palpite);
            } else {
                printf("Tente outra vez. O número sorteado é menor que %d.\n", palpite);
            }
            ultimoPalpite = palpite;
        }
    } while (1);
    return 0;
}
