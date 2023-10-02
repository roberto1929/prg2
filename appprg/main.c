#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>
#include <time.h>

int main() {
    ListaLinear lista;
    int opcao, n, elemento;

    inicializarLista(&lista, 100); // Tamanho máximo da lista é 100

    do {
        printf("MENU:\n");
        printf("1. Criar uma lista povoada de tamanho n\n");
        printf("2. Inserir um novo número\n");
        printf("3. Remover um número\n");
        printf("4. Buscar por um número usando busca linear\n");
        printf("5. Buscar por um número usando busca binária iterativa\n");
        printf("6. Buscar por um número usando busca binária recursiva\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o tamanho da lista: ");
                scanf("%d", &n);
                // Escolha se a lista será ordenada ou não
                printf("A lista será ordenada (1) ou não ordenada (0)? ");
                int ordenada;
                scanf("%d", &ordenada);
                if (ordenada) {
                    povoarOrdenada(&lista, n, 1000); // Povoar com números aleatórios de 0 a 999
                } else {
                    povoarNaoOrdenada(&lista, n, 1000); // Povoar com números aleatórios de 0 a 999
                }
                break;
            case 2:
                printf("Digite o número a ser inserido: ");
                scanf("%d", &elemento);
                if (ordenada) {
                    inserirOrdenado(&lista, elemento);
                } else {
                    inserirNaoOrdenado(&lista, elemento);
                }
                break;
            case 3:
                printf("Digite o número a ser removido: ");
                scanf("%d", &elemento);
                if (ordenada) {
                    removerOrdenado(&lista, elemento);
                } else {
                    removerNaoOrdenado(&lista, elemento);
                }
                break;
            case 4:
                printf("Digite o número a ser buscado: ");
                scanf("%d", &elemento);
                int resultado = buscaLinear(&lista, elemento);
                if (resultado != -1) {
                    printf("Elemento encontrado no índice %d\n", resultado);
                } else {
                    printf("Elemento não encontrado na lista.\n");
                }
                break;
            case 5:
                printf("Digite o número a ser buscado: ");
                scanf("%d", &elemento);
                resultado = buscaBinariaIterativa(&lista, elemento);
                if (resultado != -1) {
                    printf("Elemento encontrado no índice %d\n", resultado);
                } else {
                    printf("Elemento não encontrado na lista.\n");
                }
                break;
            case 6:
                printf("Digite o número a ser buscado: ");
                scanf("%d", &elemento);
                resultado = buscaBinariaRecursiva(&lista, elemento, 0, lista.tamanho - 1);
                if (resultado != -1) {
                    printf("Elemento encontrado no índice %d\n", resultado);
                } else {
                    printf("Elemento não encontrado na lista.\n");
                }
                break;
            case 0:
                liberarLista(&lista);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
