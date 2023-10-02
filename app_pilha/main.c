#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: RPNCalculator <equacao em RPN>\n");
        return 1;
    }

    Pilha pilha;
    inicializar(&pilha);

    char *equacao = argv[1];

    for (int i = 0; equacao[i] != '\0'; i++) {
        char token = equacao[i];
        if (token >= '0' && token <= '9') {
            push(&pilha, token - '0'); // Converte o caractere numérico para int
        } else if (token == '+') {
            int operand2 = pop(&pilha);
            int operand1 = pop(&pilha);
            push(&pilha, operand1 + operand2);
        } else if (token == '-') {
            int operand2 = pop(&pilha);
            int operand1 = pop(&pilha);
            push(&pilha, operand1 - operand2);
        } else if (token == '*') {
            int operand2 = pop(&pilha);
            int operand1 = pop(&pilha);
            push(&pilha, operand1 * operand2);
        } else if (token == '/') {
            int operand2 = pop(&pilha);
            int operand1 = pop(&pilha);
            if (operand2 == 0) {
                printf("Erro: divisão por zero\n");
                return 1;
            }
            push(&pilha, operand1 / operand2);
        }
    }

    if (size(&pilha) == 1) {
        int resultado = pop(&pilha);
        printf("Resultado: %d\n", resultado);
    } else {
        printf("Erro: formato de equação em RPN inválido\n");
        return 1;
    }

    return 0;
}
