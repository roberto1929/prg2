
#include <libprg/libprg.h>

void imprimir(int *vetor){
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int n = 0;
    int right = 0, left = 0, s,e;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
    sort_t sort;
    sort.n = n;
    printf("Tamanho do vetor: %d\n", n);
    printf("−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−\n");
    printf("Algoritmo Relógio (seg) CPU (seg)\n");
    printf("------------------------------------\n");


    sort.vetor = cria_arranjo(n);

    clock_t start = 0, end;
    struct timeval inicio, fim;


    //insertion sort
        //CPU
    comeca(&inicio);
    insert_sort(&sort);
    double tempo_cpu = medir_tempo_cpu(start);
    printf("Inserção   %f      ", tempo_cpu);

        //parede
    comeca(&inicio);
    insert_sort(&sort);
    double tempo_parede = medir_tempo_parede(&inicio);
    printf("%f\n", tempo_parede);


    // selection sort
    cria_arranjo(n);
        //CPU
    comeca(&inicio);
    selection_sort(&sort);
    tempo_cpu = medir_tempo_cpu(start);
    printf("Seleção    %f      ", tempo_cpu);

        //parede
    comeca(&inicio);
    selection_sort(&sort);
    tempo_parede = medir_tempo_parede(&inicio);
    printf("%f\n", tempo_parede);
    free(sort.vetor);


    // bubble sort
    cria_arranjo(n);
        //CPU
    comeca(&inicio);
    bubble_sort(&sort);
    tempo_cpu = medir_tempo_cpu(start);
    printf("Bolha      %f      ",tempo_cpu);
        //parede
    comeca(&inicio);
    bubble_sort(&sort);
    tempo_parede = medir_tempo_parede(&inicio);
    printf("%f\n", tempo_parede);
    free(sort.vetor);

// merge sort
    cria_arranjo(n);
//CPU
    comeca(&inicio);
    merge_sort(&sort, left, right);
    tempo_cpu = medir_tempo_cpu(start);
    printf("Merge      %f      ", tempo_cpu);
//PAREDE
    comeca(&inicio);
    merge_sort(&sort, left, right);
    tempo_parede = medir_tempo_parede(&inicio);
    printf("%f\n", tempo_parede);
    free(sort.vetor);


    // quick sort
    cria_arranjo(n);
//CPU
    comeca(&inicio);
    quick_sort(&sort, s, e);
    tempo_cpu = medir_tempo_cpu(start);
    printf("Quick      %f      ", tempo_cpu);
//PAREDE
    comeca(&inicio);
    quick_sort(&sort, s, e);
    tempo_parede = medir_tempo_parede(&inicio);
    printf("%f\n", tempo_parede);

    printf("------------------------------------\n");
    free(sort.vetor);


    return 0;
}
