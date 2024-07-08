#include <libprg/libprg.h>

int main() {
    struct timeval start;
    clock_t comecar;
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

    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    printf("Bubble:\n");
    comecar = clock();
    inicio(&start);
    bubble_sort(&sort, true);
    printf("Vetor após a ordenação: ");
    imprimir_ord(&sort);
    printf("Tempo de CPU: %f\n", finaliza_cpu(comecar));
    printf("Tempo de relógio de parede: %f\n", finaliza(&start));
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");

    printf("Insertion:\n");
    comecar = clock();
    inicio(&start);
    insertion_sort(&sort);
    printf("Vetor após a ordenação: ");
    imprimir_ord(&sort);
    printf("Tempo de CPU: %f\n", finaliza_cpu(comecar));
    printf("Tempo de relógio de parede: %f\n", finaliza(&start));
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");

    printf("Selection:\n");
    comecar = clock();
    inicio(&start);
    selection_sort(&sort, true);
    printf("Vetor após a ordenação: ");
    imprimir_ord(&sort);
    printf("Tempo de CPU: %f\n", finaliza_cpu(comecar));
    printf("Tempo de relógio de parede: %f\n", finaliza(&start));
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");

    printf("Merge:\n");
    comecar = clock();
    inicio(&start);
    int esquerda = 0;
    int direita = sort.tamanho - 1;
    merge_sort(&sort, esquerda, direita);
    printf("Vetor após a ordenação: ");
    imprimir_ord(&sort);
    printf("Tempo de CPU: %f\n", finaliza_cpu(comecar));
    printf("Tempo de relógio de parede: %f\n", finaliza(&start));
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");

    printf("Quick sort:\n");
    comecar = clock();
    inicio(&start);
    quick_sort(&sort, esquerda, direita);
    printf("Vetor após a ordenação: ");
    imprimir_ord(&sort);
    printf("Tempo de CPU: %f\n", finaliza_cpu(comecar));
    printf("Tempo de relógio de parede: %f\n", finaliza(&start));
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");

    return 0;
}
