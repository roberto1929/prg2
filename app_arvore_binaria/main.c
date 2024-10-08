#include <stdio.h>
#include <libprg/libprg.h>

int num_aleatorio(){
    return rand() % 100;
}

int main() {
    arvore_t *raiz = NULL;
    int n = 4;
    int num, valor_usuario, numero_removido;

    //cria minha arvore
    criar_arvore(n);

    for (int i = 0; i < 3; ++i) {
        num = num_aleatorio();
        raiz = inserir_valor(raiz,num);
    }

    printf("Arvore in ordem: ");
    imprime_arvore_in_order(raiz);
    printf("\n");

    printf("Arvore pre ordem: ");
    imprime_arvore_pre_order(raiz);
    printf("\n");

    printf("Arvore pos ordem: ");
    imprime_arvore_post_order(raiz);
    printf("\n");

    imprimir_texto_grafo(raiz);

    printf("Entre com um valor inteiro para verificar se está na árvore: ");
    scanf("%d", &valor_usuario);
    imprime_filho_nivel(raiz,valor_usuario,1);

    printf("Entre com um valor inteiro para remove-lo da árvore: ");
    scanf("%d", &numero_removido);
    raiz = remover_numero(raiz,numero_removido);

    printf("Árvore após a remoção: ");
    imprime_arvore_in_order(raiz);
    printf("\n");
    imprimir_texto_grafo(raiz);

    destruir_arvore(raiz);

    return 0;
}
