#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void aloca_memoria_pilha(int quantidade){
    int tamanho = quantidade * (1 << 20);
    char memoria[tamanho];
    printf("Vetor do teclado: %d kB\n", tamanho/1024);
    printf("Endereço da variável tamanho: %p\n", (void)&tamanho);
    printf("Distancia entre vetor e tamanho: %ld\n", (((char*)&tamanho-memoria)/1024));
    bzero(memoria, tamanho);
    printf("zerou memória\n");
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
    if(argc> 0){
        aloca_memoria_pilha(strtol(argv[1],NULL, 10);
    }


    printf("%d\n", mult_ite(2,6));
    printf("%d\n", mult_rec(2,6));
    return 0;
}
