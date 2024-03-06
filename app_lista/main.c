#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"  // Inclua o cabeçalho da biblioteca libprg

int main() {
    lista_t lista;
    int opcao, tamanho, elemento, posicao;

    //loop para o menu interativo
    do {
        printf("\nMenu\n");
        printf("1- Criar uma lista povoada\n");
        printf("2- Inserir um novo número\n");
        printf("3- Remover um número\n");
        printf("4- Buscar por um número usando busca linear\n");
        printf("5- Buscar por um número usando busca binária iterativa\n");
        printf("6- Buscar por um número usando busca binária recursiva\n");
        printf("0- Sair\n");

        printf("Entre com sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o tamanho da lista ");
                scanf("%d", &tamanho);
                printf("Você deseja que a lista seja ordenada?(1- Sim, 0 - Não");
                int ordenada;
                scanf("%d", &ordenada);
                if (ordenada) {
                    criar_lista(&lista);
                    povoar_ord(&lista);
                } else {
                    criar_lista(&lista);
                    povoar_nao_ord(&lista);
                }
                break;
            case 2:
                printf("Informe o número que vai ser inserido: ");
                scanf("%d", &elemento);
                printf("Você deseja que a lista seja ordenada?(1- Sim, 0 - Não");
                int ordenada_inserir;
                scanf("%d", &ordenada_inserir);
                if (ordenada_inserir) {
                    if (insere_ord(&lista, elemento)) {
                        printf("Numero inserido\n");
                    } else {
                        printf("Não foi possível inserir o número\n");
                    }
                } else {
                    if (insere_nao_ord(&lista, elemento)) {
                        printf("Numero inserido\n");
                    } else {
                        printf("Não foi possível inserir o número\n");
                    }
                    break;
                    case 3:
                        printf("Informe o número que vai ser removido: ");
                    scanf("%d", &elemento);
                    printf("Você deseja que a lista seja ordenada?(1- Sim, 0 - Não");
                    int ordenada_remover;
                    scanf("%d", &ordenada_remover);
                    if (ordenada_remover) {
                        if (remove_num_ord(&lista, elemento)) {
                            printf("Numero removido\n");
                        } else {
                            printf("Não foi possível remover o número\n");
                        }
                    } else {
                        if (remove_num_nao_ord(&lista, elemento)) {
                            printf("Numero removido\n");
                        } else {
                            printf("Não foi possível remover o número\n");
                        }
                    }
                }
                break;
            case 4:
                printf("Insira o número que quer buscar: ");
                scanf("%d", &elemento);
                posicao = busca_linear(&lista, elemento);
                if(posicao != -1){
                    printf("Numero encontrado na posição\n");
                } else {
                    printf("Numero não encontrado\n");
                }
                                break;
            case 5:
                printf("Insira o número que quer buscar: ");
                scanf("%d", &elemento);
                posicao = busca_bin_int(&lista, elemento);
                if(posicao != -1){
                    printf("Numero encontrado na posição\n");
                } else {
                    printf("Numero não encontrado\n");
                }
                break;
            case 6:
                printf("Insira o número que quer buscar: ");
                scanf("%d", &elemento);
                posicao = busca_bin_rec(&lista,0, lista.total -1, elemento);
                if(posicao != -1){
                    printf("Numero encontrado na posição\n");
                } else {
                    printf("Numero não encontrado\n");
                }
                break;
            case 0:
                printf("Sair do programa\n");
                break;

            default:
                printf("Opção inválida tente novamente\n");
        }

    } while (opcao != 0);

    libera_memoria(&lista);
    return 0;
}
