#include <libprg/libprg.h>


int main(){

    no_t *no;
    listaEncadeada_t lista;
    lista.size = 0;
//    stacklist_t pilha;
//    pilha.size = 0;
    no_t* inicio = NULL;

    adiciona_lista(&lista, &no, 20);
    adiciona_lista(&lista, &no, 10);
    adiciona_lista(&lista, &no, 2);
    adiciona_lista(&lista, &no, 15);



    printf("Nós: ");
    imprime_no(no);
    printf("Tamanho do nó: %d", lista.size);

    remove_lista(&no, 20,&lista);
    printf("\n");
    printf("Nós: ");
    imprime_no(no);
    printf("Tamanho do nó: %d", lista.size);
    printf("\n");
    printf("Indice: %d", busca_lista(&no, 2));

    destruir(&no);

    //    adiciona_pilha(&pilha,&no,20);
//    adiciona_pilha(&pilha,&no,10);
//    adiciona_pilha(&pilha,&no,2);
//    adiciona_pilha(&pilha,&no,15);

    return 0;
}