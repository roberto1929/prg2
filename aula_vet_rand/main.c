#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Portuguese");
    int vetor[10]={32,12,45,23,55,98,53,11,3,65};
    int pos_menor, menor, i,j;


    printf("O conteúdo no vetor é: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("O conteúdo no vetor agora é: ");

    for (i = 0; i < 10; ++i) {
        menor = vetor[i];
        pos_menor = i;
        for (j = i + 1; j < 10; ++j) {
            if(vetor[j] < menor){
                menor = vetor[j];
                pos_menor = j;
            }
        }
        vetor[pos_menor] = vetor[i];
        vetor[i] = menor;
    }
    for (i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }



    return 0;
}
