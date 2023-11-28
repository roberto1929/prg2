#include <stdio.h>
#include <libprg/libprg.h>

clock_t start = 0, end;
struct timeval inicio, fim;



int num_aleatorio(int min, int max){
    return min + rand() % (max - min + 1);
}

int procura_maior_valor(arvore_t *raiz){
    while (raiz->direita != NULL){
        raiz = raiz->direita;
    }
    return raiz->valor;
}

int procura_menor_valor(arvore_t *raiz){
    while (raiz->esquerda != NULL){
        raiz = raiz->esquerda;
    }
    return raiz->valor;
}

int main() {
    arvore_t *raiz = NULL;
    int n = 10;
    int num, maior_valor, menor_valor;

    criar_arvore(n);
    comeca(&inicio);

    for (int i = 0; i < n; ++i) {
        num = num_aleatorio(1,100);
        raiz = inserir_valor(raiz,num);
    }

    double tempo_de_cpu = medir_tempo_cpu(start);
    printf("Tempo de CPU para inserir números: %f\n", tempo_de_cpu);

    comeca(&inicio);
    maior_valor = procura_maior_valor(raiz);

    double tempo_de_cpu = medir_tempo_cpu(start);
    printf("Tempo de CPU para achar maiior valor: %f\n", tempo_de_cpu);

    comeca(&inicio);

    menor_valor = procura_menor_valor(raiz);

    double tempo_de_cpu = medir_tempo_cpu(start);
    printf("Tempo de CPU para achar menor valor: %f\n", tempo_de_cpu);

    printf("Maior valor encotrado: %d", maior_valor);
    printf("\n");
    printf("Menor valor encotrado: %d", menor_valor);
    printf("\n");

    destruir_arvore(raiz);
    return 0;
}
