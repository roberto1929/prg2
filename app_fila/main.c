#include <stdio.h>
#include <libprg/libprg.h>

int main() {
    fila_t minha_fila;
    criar_fila(&minha_fila);

    int escolha, elemento;

    while (1) {
        printf("Menu:\n");
        printf("1. Criar uma fila\n");
        printf("2. Inserir um novo elemento\n");
        printf("3. Remover um elemento\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o tamanho da fila: ");
                int tamanho;
                scanf("%d", &tamanho);
                criar_fila(&minha_fila, tamanho);
                printf("Fila criada com sucesso!\n");
                break;

            case 2:
                if (full(&minha_fila)) {
                    printf("A fila está cheia. Não é possível inserir mais elementos.\n");
                } else {
                    printf("Digite o elemento a ser inserido: ");
                    scanf("%d", &elemento);
                    enqueue(elemento, &minha_fila);
                    printf("Elemento inserido com sucesso!\n");
                }
                break;

            case 3:
                if (empty(&minha_fila)) {
                    printf("A fila está vazia. Não é possível remover um elemento.\n");
                } else {
                    int elemento_removido = dequeue(&minha_fila);
                    printf("Elemento removido: %d\n", elemento_removido);
                }
                break;

            case 4:
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
