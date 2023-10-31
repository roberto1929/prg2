
#include <libprg/libprg.h>

void imprimir(int *vetor){
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int n = 0;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    sort_t sort;

    printf("Tamanho do vetor: %d\n", n);
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    printf("Algoritmo Relógio (seg) CPU (seg)\n");
    printf("------------------------------------\n");

    cria_arranjo(n);

    imprimir(sort.vetor);
    bubble_sort(&sort);
    imprimir(sort.vetor);


//    clock_t start, end;
//    double cpu_time_used;
//    struct timeval inicio, fim;
//    double wall_time_used;
//
//
//    //insertion sort
//    //CPU
//    start = clock();
//    insert_sort(&sort);
//    end = clock();
//    cpu_time_used = ((double )(end - start)) / CLOCKS_PER_SEC;
//    printf("Inserção   %f      ", cpu_time_used);
//
//    //parede
//    gettimeofday(&inicio, 0);
//    insert_sort(&sort);
//    gettimeofday(&fim, 0);
//    long seg = fim.tv_sec - inicio.tv_sec;
//    long mseg = fim.tv_usec - inicio.tv_usec;
//    double tempo_total = seg + mseg * 1e-6;
//    printf("%f\n", tempo_total);
//
//
//
//    // selection sort
//    //CPU
//    start = clock();
//    selection_sort(&sort);
//    end = clock();
//    cpu_time_used= ((double)(end - start)) / CLOCKS_PER_SEC;
//    printf("Seleção    %f      ", cpu_time_used);
//    //parede
//    gettimeofday(&inicio, 0);
//    selection_sort(&sort);
//    gettimeofday(&fim, 0);
//    seg = fim.tv_sec - inicio.tv_sec;
//    mseg = fim.tv_usec - inicio.tv_usec;
//    tempo_total = seg + mseg * 1e-6;
//    printf("%f\n", tempo_total);
//
//
//
//    // bubble sort
//    //CPU
//    start = clock();
//    bubble_sort(&sort);
//    end = clock();
//    cpu_time_used= ((double)(end - start)) / CLOCKS_PER_SEC;
//    printf("Bolha      %f      ", cpu_time_used);
//    //parede
//    gettimeofday(&inicio, 0);
//    bubble_sort(&sort);
//    gettimeofday(&fim, 0);
//    seg = fim.tv_sec - inicio.tv_sec;
//    mseg = fim.tv_usec - inicio.tv_usec;
//    tempo_total = seg + mseg * 1e-6;
//    printf("%f\n", tempo_total);
//
//
//    printf("------------------------------------\n");
//    free(sort.vetor);


    return 0;
}
