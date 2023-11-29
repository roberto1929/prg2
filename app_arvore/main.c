#include <stdio.h>
#include <libprg/libprg.h>

clock_t start = 0, end;
struct timeval inicio, fim;

arvore_t *remover_valor(arvore_t *raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->esquerda = remover_valor(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover_valor(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL) {
            no_t *temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            no_t *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        arvore_t *temp = raiz->direita;
        while (temp->esquerda != NULL)
            temp = temp->esquerda;

        raiz->valor = temp->valor;

        raiz->direita = remover_valor(raiz->direita, temp->valor);
    }
    return raiz;
}

void imprime_filho_nivel(arvore_t *raiz, int valor, int nivel){
    if(raiz == NULL){
        printf("Número não encontrado na árvore\n");
        return;
    }
    if (valor == raiz->valor) {
        printf("Número encontrado na árvore.\n");
        if (raiz->esquerda != NULL)
            printf("Filho a esquerda: %d\n", raiz->esquerda->valor);
        else
            printf("Não tem filho à esquerda.\n");

        if (raiz->direita != NULL)
            printf("Filho a direita: %d\n", raiz->direita->valor);
        else
            printf("Não tem filho à direita.\n");

        printf("O nivel do número encontrado na arvore é: %d\n", nivel);
        return;
    }
    if (valor < raiz->valor) {
        imprime_filho_nivel(raiz->esquerda, valor, nivel + 1);
    } else {
        imprime_filho_nivel(raiz->direita, valor, nivel + 1);
    }
}

void imprime_arvore(arvore_t *raiz){
    if(raiz != NULL){
        imprime_arvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprime_arvore(raiz->direita);
    }
}

int num_aleatorio(int min, int max){
    return min + rand() % (max - min + 1);
}

int procura_maior_valor(arvore_t *raiz){
    if (raiz->direita != NULL){
        raiz = raiz->direita;
    }
    return raiz->valor;
}

int procura_menor_valor(arvore_t * raiz){
    if (raiz->esquerda != NULL){
        raiz = raiz->esquerda;
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

    printf("Entre com um valor inteiro: ");
    scanf("%d", &valor_usuario);


//    //tomada de tempo p/ achar o maior valor da árvore
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

    printf("Entre com um valor inteiro: ");
    scanf("%d", &numero_removido);


    comeca(&inicio);

    raiz = remover_valor(raiz,numero_removido);

    tempo_de_parede = medir_tempo_parede(&inicio);
    printf("Tempo para remover na arvore: %f\n", tempo_de_parede);


//    printf("Menor valor da arvore: %d", menor_valor);
//    printf("\n");
//    printf("Maior valor da arvore: %d", maior_valor);
//    printf("\n");

    printf("Arvore após a remoção: ");
    imprime_arvore(raiz);
    printf("\n");

    destruir_arvore(raiz);
    return 0;
}