//
// Created by eliaz on 12/08/2023.
//

#include "exercicio_8.h"
#include <stdio.h>


int oitavo_ex() {
    char frase[1000];
    int vogais[5] = {0};

    printf("Digite uma frase: ");
    scanf("%[^\n]", frase);

    int i = 0;
    while (frase[i] != '\0') {
        char c = frase[i];

        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }

        switch (c) {
            case 'a':
                vogais[0]++;
                break;
            case 'e':
                vogais[1]++;
                break;
            case 'i':
                vogais[2]++;
                break;
            case 'o':
                vogais[3]++;
                break;
            case 'u':
                vogais[4]++;
                break;
        }

        i++;
    }

    printf("Quantidade de vezes que cada vogal aparece na frase:\n");
    printf("a: %d\n", vogais[0]);
    printf("e: %d\n", vogais[1]);
    printf("i: %d\n", vogais[2]);
    printf("o: %d\n", vogais[3]);
    printf("u: %d\n", vogais[4]);

    return 0;
}
