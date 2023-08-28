#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fatorial.h"

#include "fibo_rec.h"
#include "fibonacci.h"
int fatorial_inte(int n);

void aloca_memoria_pilha(int quantidade){
    int tamanho = quantidade * (1 << 20);
    char memoria[tamanho];
    printf("Vetor do teclado: %d kB\n", tamanho/1024);
    printf("Endereço da variável tamanho: %p\n", (void*)&tamanho);
    printf("Distancia entre vetor e tamanho: %ld\n", (((char*)&tamanho-memoria)/1024));
    bzero(memoria, tamanho);
    printf("zerou memória\n");
}

void aloca_memoria_heap(int quantidade){
    int tamanho = quantidade * (1 << 20);
    char *memoria = calloc(tamanho, sizeof (char ));
    printf("Vetor do teclado: %d kB\n", tamanho/1024);
    printf("Endereço da variável tamanho: %p\n", (void*)&tamanho);
    printf("Distancia entre vetor e tamanho: %ld\n", (((char*)&tamanho-memoria)/1024));
    bzero(memoria, tamanho);
    printf("zerou memória\n");
    free(memoria);
}



int mult_ite(int m, int n){
    int resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado += m;
    }
    return resultado;
}

int mult_rec(int m, int n){
    if(n ==0){
        return 0;
    }
    return (m + mult_rec(m, n-1));
}


int main(int argc, char *argv[]) {

    //printf("%d\n", fatorial_inte(8));
        printf("%d\n", fibonacci(8));
    for (int i = 0; i < 10; ++i) {
        printf("%d ", fibo_rec(i));
    }

//    if(strcmp(argv[1], "p")){
//        aloca_memoria_pilha(strtol(argv[2],NULL, 10));
//    }
//    if(strcmp(argv[1], "h")){
//        aloca_memoria_heap(strtol(argv[2],NULL, 10));
//    }
    return 0;
}
