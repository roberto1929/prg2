//
// Created by eliaz on 09/08/2023.
//

#include "exercicio_1.h"
#include <stdio.h>
#include <locale.h>

int primeiro_ex(void){
    setlocale(LC_ALL, "Portuguese");

    int numero, maior =0;

    printf("Digite uma sequência de números (0 pra sair)");
    do {
        printf("Digite um número: ");
        scanf("%d", &numero);
        if (numero > maior){
            maior = numero;
        }
    } while (numero !=0);

    if(maior != 0){
        printf("O maior número digitado é: %d\n", maior);
    } else {
        printf("Nenhum número válido foi digitado.\n");
    }

    return 0;
}
