#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"  // Inclua o cabeçalho da biblioteca libprg

int main() {
    lista_t lista;
    int opcao, tamanho, elemento, posicao;

    // Loop do menu interativo
    do {
        printf("\nMenu:\n");
        printf("1. Criar uma lista povoada\n");
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
                printf("Informe o tamanho da lista: ");
                scanf("%d", &tamanho);
                printf("Deseja que a lista seja ordenada? (1 - Sim, 0 - Não): ");
                int ordenada;
                scanf("%d", &ordenada);
                if (ordenada) {
                    criar_lista(&lista);
                    povoar_ordenada(&lista);
                } else {
                    criar_lista(&lista);
                    povoar_nao_ordenada(&lista);
                }
                break;
            case 2:
                printf("Informe o número a ser inserido: ");
                scanf("%d", &elemento);
                printf("Deseja inserir na lista ordenada? (1 - Sim, 0 - Não): ");
                int ordenada_inserir;
                scanf("%d", &ordenada_inserir);
                if (ordenada_inserir) {
                    if (inserir_ordenada(&lista, elemento)) {
                        printf("Número inserido com sucesso!\n");
                    } else {
                        printf("Erro ao inserir o número.\n");
                    }
                } else {
                    if (inserir_nao_ord(&lista, elemento)) {
                        printf("Número inserido com sucesso!\n");
                    } else {
                        printf("Erro ao inserir o número.\n");
                    }
                }
                break;
            case 3:
                printf("Informe o número a ser removido: ");
                scanf("%d", &elemento);
                printf("Deseja remover da lista ordenada? (1 - Sim, 0 - Não): ");
                int ordenada_remover;
                scanf("%d", &ordenada_remover);
                if (ordenada_remover) {
                    if (remover_ordenada(&lista, elemento)) {
                        printf("Número removido com sucesso!\n");
                    } else {
                        printf("Erro ao remover o número.\n");
                    }
                } else {
                    if (remover_nao_ord(&lista, elemento)) {
                        printf("Número removido com sucesso!\n");
                    } else {
                        printf("Erro ao remover o número.\n");
                    }
                }
                break;
            case 4:
                printf("Informe o número a ser buscado: ");
                scanf("%d", &elemento);
                posicao = busca_linear(&lista, elemento);
                if (posicao != -1) {
                    printf("Número encontrado na posição %d.\n", posicao);
                } else {
                    printf("Número não encontrado na lista.\n");
                }
                break;
            case 5:
                printf("Informe o número a ser buscado: ");
                scanf("%d", &elemento);
                posicao = busca_binaria_ite(&lista, elemento);
                if (posicao != -1) {
                    printf("Número encontrado na posição %d.\n", posicao);
                } else {
                    printf("Número não encontrado na lista.\n");
                }
                break;
            case 6:
                printf("Informe o número a ser buscado: ");
                scanf("%d", &elemento);
                posicao = busca_binaria_rec(&lista, 0, lista.total - 1, elemento);
                if (posicao != -1) {
                    printf("Número encontrado na posição %d.\n", posicao);
                } else {
                    printf("Número não encontrado na lista.\n");
                }
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    // Libere a memória alocada
    libera_memoria(&lista);

    return 0;
}
