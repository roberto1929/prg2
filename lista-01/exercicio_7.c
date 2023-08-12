//
// Created by eliaz on 12/08/2023.
//

#include "exercicio_7.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int setimo_ex() {
    char palavra[100];
    int i, j;
    int ehPalindromo = 1;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for (i = 0; i < strlen(palavra); i++) {
        palavra[i] = tolower(palavra[i]);
    }

    i = 0;
    j = strlen(palavra) - 1;

    while (i < j) {
        if (palavra[i] != palavra[j]) {
            ehPalindromo = 0;
            break;
        }
        i++;
        j--;
    }

    if (ehPalindromo) {
        printf("A palavra é um palíndromo.\n");
    } else {
        printf("A palavra não é um palíndromo.\n");
    }

    return 0;
}
