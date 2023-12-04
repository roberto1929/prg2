#include <stdio.h>
#include <libprg/libprg.h>

clock_t start = 0, end;
struct timeval inicio, fim;

int num_aleatorio(int min, int max){
    return min + rand() % (max - min + 1);
}

int procura_menor_valor(arvore_t * raiz){
    if (raiz->esquerda != NULL){
        raiz = raiz->esquerda;
    }
    return raiz->valor;
}

int procura_maior_valor(arvore_t *raiz){
    if (raiz->direita != NULL){
        raiz = raiz->direita;
    }
    return raiz->valor;
}

int main() {
    arvore_t arvore;
    arvore_t *raiz = NULL;
    int n = 20;
    int num, maior_valor, menor_valor, valor_usuario, numero_removido;

    //cria minha arvore
    criar_arvore(n);

    // tomada de tempo pra inserir valores na árvore
    comeca(&inicio);
    for (int i = 0; i < n; ++i) {
        num = num_aleatorio(50,100);
        raiz = inserir_valor(raiz,num);
    }

    double tempo_de_cpu = medir_tempo_cpu(start);
    printf("Tempo para inserir números: %f\n", tempo_de_cpu);

    printf("Arvore: ");
    imprime_arvore(raiz);
    printf("\n");

    printf("Entre com um valor inteiro para verificar se está na árvore: ");
    scanf("%d", &valor_usuario);


//    //tomada de tempo pra achar o maior valor da árvore
//    comeca(&inicio);
//    maior_valor = procura_maior_valor(raiz);
//
//    tempo_de_cpu = medir_tempo_cpu(start);
//    //printf("Tempo para achar maior valor: %f\n", tempo_de_cpu);
//
//    //tomada de tempo p/ achar p menor valor
//    comeca(&inicio);
//    menor_valor = procura_menor_valor(raiz);
//
//    tempo_de_cpu = medir_tempo_cpu(start);
//    //printf("Tempo para achar menor valor: %f\n", tempo_de_cpu);
//
    comeca(&inicio);

    imprime_filho_nivel(raiz,valor_usuario,1);

    double tempo_de_parede = medir_tempo_parede(&inicio);
    printf("Tempo para achar filhos e o nivel na arvore: %f\n", tempo_de_parede);

    printf("Entre com um valor inteiro para remove-lo da árvore: ");
    scanf("%d", &numero_removido);


    comeca(&inicio);

    raiz = remover_numero(raiz,numero_removido);

    tempo_de_parede = medir_tempo_parede(&inicio);
    printf("Tempo para remover na árvore: %f\n", tempo_de_parede);


//    printf("Menor valor da arvore: %d", menor_valor);
//    printf("\n");
//    printf("Maior valor da arvore: %d", maior_valor);
//    printf("\n");

    printf("Árvore após a remoção: ");
    imprime_arvore(raiz);
    printf("\n");

    destruir_arvore(raiz);
    return 0;
}