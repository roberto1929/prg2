#include <stdio.h>
#include <libprg/libprg.h>


int main(void) {
    fila_t *fila;
    int opcao, elemento, x, y;
    printf("Bem vindo ao nosso sistema\n");
    while (1) {
        printf("===========MENU===========\n");
        printf("1- Criar fila\n");
        printf("2- Inserir um novo número\n");
        printf("3- Remover um elemento\n");
        printf("0- Encerrar o programa\n");

        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Insira o tamanho da lista:");
                scanf("%d", &elemento);
                fila = criar_fila(elemento);

                break;

            case 2:
                printf("Valor a ser inserido:");
                scanf("%d", &x);
                enqueue(fila, x);
                printf("Elemento inserdo com sucesso\n");
                break;
            case 3:
                printf("Elemento a ser removido:");
                scanf("%d", &y);
                printf("O elemento %d foi removido\n",dequeue(fila));

                break;
            case 0:
                printf("Encerrando o programa\n");
                return 0;
            default:
                printf("Opção inválida");
        }

    }
}