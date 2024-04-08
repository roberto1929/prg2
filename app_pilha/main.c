#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>


int main(int argc, char *argv[]) {

    if(argc != 2){
        printf("Uso: %s <expressão RPN>", argv[0]);
    }
    pilha_t* pilha;
    criar_pilha(pilha, strlen(argv[1]));
    char* token = strtok(argv[1], " ");

    while (token != NULL){
        if(isdigit(*token)){
            push(pilha, atoi(token));
        } else {
            int op1 = pop(pilha);
            int op2 = pop(pilha);
            switch (*token) {
                case '+':
                    push(pilha, op1 + op2);
                    break;
                case '-':
                    push(pilha, op1 - op2);
                    break;
                case '*':
                    push(pilha, op1 * op2);
                    break;
                case '/':
                    push(pilha, op1 / op2);
                    break;
                default:
                    printf("Operador inválido: %c\n", *token);
                    return -1;
            }
        }
        token = strtok(NULL, " ");
    }

    int resultado = pop(pilha);
    free(pilha->vetor);


    if(empty_p(pilha)){
        printf("Resultado: %d\n", resultado);
    } else {
        printf("Erro ao avaliar a expressão\n");
    }

    return 0;
}