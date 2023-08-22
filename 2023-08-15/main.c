#include <stdio.h>
#include <stdio.h>
2 #include <stdlib.h>
3 int main(){
    4 int ∗vetor, tamanho = 2;
    5 vetor = calloc(tamanho, sizeof (int));
    6
    7 if (vetor == NULL){
        8 printf("Não foi possível alocar memória\n");
        9 exit(EXIT_FAILURE);
        10 }
    11 vetor[0] = 10; vetor[1] = 20;
    12 tamanho = 4;
    13
    14 vetor = realloc(vetor, tamanho ∗ sizeof (int));
    15 vetor[2] = 30; vetor[3] = 40;
    16
    17 for (int i = 0; i < tamanho; ++i) {
        18 printf("%d\n", ∗(vetor + i));
        19 }
    20 free(vetor);
    21 return 0;
    22 }