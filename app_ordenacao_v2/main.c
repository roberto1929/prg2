#include <stdio.h>
#include <libprg/libprg.h>
#include <limits.h>

void imprimir(int *vetor){
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int *vetor = NULL;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
    vetor = cria_arranjo(n);

    bubble_sort(vetor);
    imprimir(vetor);
    return 0;
}
