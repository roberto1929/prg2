#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>


int criar_vetor(int vetor[], int tamanho){
    vetor = (int*) malloc(tamanho * sizeof(int));
    srand((unsigned) time(NULL));
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = rand() % 10 +  1;
    }
    return  vetor;
}



void imprimir(int vetor[10]){
    for (int i = 0; i < 10; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void nosso(int vetor[], int tamanho){

    int pos_menor, menor, i,j;
    printf("O conteúdo no vetor é: ");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("O conteúdo no vetor agora é: ");

    for (i = 0; i < tamanho; ++i) {
        menor = vetor[i];
        pos_menor = i;
        for (j = i + 1; j < tamanho; ++j) {
            if(vetor[j] < menor){
                menor = vetor[j];
                pos_menor = j;
            }
        }
        vetor[pos_menor] = vetor[i];
        vetor[i] = menor;
    }
}

void selection_sort(int vetor[], int tamanho){
    int min;
    int aux;
    for (int i = 0; i < tamanho; i++) {
        min = i;
        for (int j = i + 1; j < tamanho ; j++) {
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        if(i != min){
            aux= vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}


void insert_sort(int vetor[], int tamanho){
    int chave;
    int j;
    for (int i = 0; i < tamanho; ++i) {
        chave = vetor[i];
        j = i-1;
        while (j >= 0 && vetor[j] > chave){
            vetor[j+1] = vetor[j];
            j = j -1;
        }
        vetor[j+1] = chave;
    }
}

void bubble_sort(int vetor[10]){
    int aux;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10-1; ++j) {
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}



int main() {
    setlocale(LC_ALL, "Portuguese");

    int *v;
    int n = 10;
    criar_vetor(v,n);

    //bubble_sort(vetor);
    //insert_sort(v, 10);
   // imprimir(v);
    selection_sort(v, 10);
    imprimir(v);

    return 0;
}
