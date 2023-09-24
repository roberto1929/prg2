#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>
#include <time.h>
#include <sys/time.h>

void medir_tempo_inicio(struct timeval *tempo) {
    gettimeofday(tempo, NULL);
}

void medir_tempo_fim(struct timeval *tempo, double *tempo_total) {
    struct timeval fim;
    gettimeofday(&fim, NULL);

    long seg = fim.tv_sec - tempo->tv_sec;
    long mseg = fim.tv_usec - tempo->tv_usec;
    *tempo_total = seg + mseg * 1e-6;
}

int main() {
    int *vetor = NULL;
    int total = 0;
    int tamanho = 0;
    char opcao;

    struct timeval inicio, fim;
    double tempo_total;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Criar uma lista povoada\n");
        printf("2. Inserir um novo número\n");
        printf("3. Remover um número\n");
        printf("4. Buscar por um número usando busca linear\n");
        printf("5. Buscar por um número usando busca binária iterativa\n");
        printf("6. Buscar por um número usando busca binária recursiva\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("Informe o tamanho da lista: ");
                scanf("%d", &tamanho);
                printf("Deseja que a lista seja ordenada (a/d/n)? ");
                scanf(" %c", &opcao);

                if (vetor != NULL) {
                    free(vetor);
                }

                criar_lista(&vetor, tamanho);
                if (opcao == 'a') {
                    povoar_ordenada(vetor, tamanho, 'a');
                } else if (opcao == 'd') {
                    povoar_ordenada(vetor, tamanho, 'd');
                } else if (opcao == 'n') {
                    povoar_nao_ordenada(vetor, tamanho);
                }
                total = tamanho;
                printf("Lista criada e populada.\n");
                break;

            case '2':
                if (vetor == NULL) {
                    printf("A lista não foi criada ainda. Crie uma lista primeiro.\n");
                } else {
                    int elemento;
                    printf("Informe o número a ser inserido: ");
                    scanf("%d", &elemento);

                    medir_tempo_inicio(&inicio);

                    inserir_ordenada(elemento, vetor, tamanho, &total);

                    medir_tempo_fim(&inicio, &tempo_total);
                    printf("Número inserido. Tempo gasto: %f segundos.\n", tempo_total);
                }
                break;

            case '3':
                if (vetor == NULL) {
                    printf("A lista não foi criada ainda. Crie uma lista primeiro.\n");
                } else {
                    int elemento;
                    printf("Informe o número a ser removido: ");
                    scanf("%d", &elemento);
                    remover(elemento, vetor, &total, tamanho);
                    printf("Número removido.\n");
                }
                break;

            case '4':
                if (vetor == NULL) {
                    printf("A lista não foi criada ainda. Crie uma lista primeiro.\n");
                } else {
                    int elemento;
                    printf("Informe o número a ser buscado: ");
                    scanf("%d", &elemento);
                    if (busca_linear(elemento, vetor, total, tamanho)) {
                        printf("Número encontrado.\n");
                    } else {
                        printf("Número não encontrado.\n");
                    }
                }
                break;

            case '5':
                if (vetor == NULL) {
                    printf("A lista não foi criada ainda. Crie uma lista primeiro.\n");
                } else {
                    int elemento;
                    printf("Informe o número a ser buscado: ");
                    scanf("%d", &elemento);
                    if (busca_binaria_ite(elemento, vetor, total)) {
                        printf("Número encontrado.\n");
                    } else {
                        printf("Número não encontrado.\n");
                    }
                }
                break;

            case '6':
                if (vetor == NULL) {
                    printf("A lista não foi criada ainda. Crie uma lista primeiro.\n");
                } else {
                    int elemento;
                    printf("Informe o número a ser buscado: ");
                    scanf("%d", &elemento);

                    medir_tempo_inicio(&inicio);

                    if (busca_binaria_rec(elemento, vetor, total, 0, total - 1)) {
                        printf("Número encontrado.\n");
                    } else {
                        printf("Número não encontrado.\n");
                    }

                    medir_tempo_fim(&inicio, &tempo_total);
                    printf("Busca binária recursiva concluída. Tempo gasto: %f segundos.\n", tempo_total);
                }
                break;

            case '7':
                if (vetor != NULL) {
                    free(vetor); 
                }
                exit(0);

            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}
