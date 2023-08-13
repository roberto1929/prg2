//
// Created by eliaz on 12/08/2023.
//

#include "exercicio_8.h"
#include <stdio.h>
#include <ctype.h>

int oitavo_ex() {
    char frase[100];
    int contaVogais = 0;

    scanf("%[^\n]s", frase);

    for (int i = 0; frase[i] != '\0'; i++) {
        char c = tolower(frase[i]);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contaVogais++;
        }
    }

    printf("O número de vogais na frase é: %d\n", contaVogais);

    return 0;
}
