#include <stdio.h>
#include <libprg/libprg.h>

int num_aleatorio(int min, int max){
    return min + rand() % (max - min + 1);
}

int main() {
    arvore_t arvore;
    arvore_t *raiz = NULL;
    int n = 6;
    int num, valor_usuario, numero_removido;

    //cria minha arvore
    criar_arvore(n);

    // tomada de tempo pra inserir valores na árvore
    for (int i = 0; i < n; ++i) {
        num = num_aleatorio(50,100);
        raiz = inserir_valor(raiz,num);
    }

    printf("Arvore in ordem: ");
    imprime_arvore_in_order(raiz);
    printf("\n");

    printf("Arvore pre ordem: ");
    imprime_arvore_pre_order(raiz);
    printf("\n");

//    printf("Arvore pos ordem: ");
//    imprime_arvore_post_order(raiz);
//    printf("\n");

    printf("strict graph{\n");
    printf("label=\"Árvore de busca binária\";\n");
    printf("node [shape=\"circle\", color=\"#339966\", style=\"filled\",\n");
    printf("\tfixedsize=true];\n");
    imprime_arvore_grafo(raiz);
    printf("}\n");



    printf("Entre com um valor inteiro para verificar se está na árvore: ");
    scanf("%d", &valor_usuario);
    imprime_filho_nivel(raiz,valor_usuario,1);

    printf("Entre com um valor inteiro para remove-lo da árvore: ");
    scanf("%d", &numero_removido);
    raiz = remover_numero(raiz,numero_removido);

    printf("Árvore após a remoção: ");
    imprime_arvore_in_order(raiz);
    printf("\n");


    destruir_arvore(raiz);

    return 0;
}
