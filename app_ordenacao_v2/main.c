#include <libprg/libprg.h>

int main() {

    int tamanho;
    sort_t sort;

    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    printf("APP ORDENAÇÃO\n");
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");

    cria_sort(&sort, tamanho);
    printf("Vetor antes da ordenação: ");
    preencher_sort(&sort, tamanho);

    imprimir_ord(&sort);
    printf("\n");

    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");

    bubble_sort(&sort, true);
    printf("Vetor após a ordenação: ");
    imprimir_ord(&sort);
    printf("Tamanho do vetor: %d\n", tamanho);
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    free(sort.vetor);


    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);
    cria_sort(&sort, tamanho);
    printf("Vetor antes da ordenação: ");
    preencher_sort(&sort, tamanho);
    insertion_sort(&sort);
    printf("Vetor após a ordenação: ");
    imprimir_ord(&sort);
    printf("Tamanho do vetor: %d\n", tamanho);
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    free(sort.vetor);


    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tamanho);
    cria_sort(&sort, tamanho);
    printf("Vetor antes da ordenação: ");
    preencher_sort(&sort, tamanho);
    selection_sort(&sort, true);
    printf("Vetor após a ordenação: ");
    imprimir_ord(&sort);
    printf("Tamanho do vetor: %d\n", tamanho);
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    free(sort.vetor);

    return 0;
}
