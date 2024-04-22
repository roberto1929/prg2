#include <libprg/libprg.h>


int main(){

    no_t *no = NULL;
    listaEncadeada_t lista;
    lista.size = 0;
    stacklist_t pilha;
    pilha.size = 0;

//    adiciona_lista(&lista, &no, 20);
//    adiciona_lista(&lista, &no, 10);
//    adiciona_lista(&lista, &no, 2);
//    adiciona_lista(&lista, &no, 15);



//    printf("Nós: ");
//    imprime_no(no);
//    printf("Tamanho do nó: %d", lista.size);
//
//    remove_lista(&no, 20,&lista);
//    printf("\n");
//    printf("Nós: ");
//    imprime_no(no);
//    printf("Tamanho do nó: %d", lista.size);
//    printf("\n");
//
//    int alvo = 45;
//    no_t *resultado = busca_lista(no, alvo);
//    if(resultado != NULL){
//        printf("Elemento %d encontrado na lista.\n", alvo);
//    } else {
//        printf("Elemento %d não encontrado na lista.\n", alvo);
//    }
//
//    destruir(&no);

    adiciona_pilha(&pilha,&no,45);
    adiciona_pilha(&pilha,&no,20);
    adiciona_pilha(&pilha,&no,10);
    adiciona_pilha(&pilha,&no,2);
    adiciona_pilha(&pilha,&no,15);


    printf("Nós: ");
    imprime_no(no);
    printf("\n");
    printf("Tamanho: %d", pilha.size);
    printf("\n");
    printf("Remover 1º elemento: ");
    remove_pilha(&pilha, &no);
    imprime_no(no);
    printf("\n");
    int alvo = 15;
    no_t *resultado = busca_pilha(no, alvo);

    if(resultado != NULL){
        printf("Elemento %d encontrado na lista.\n", alvo);
    } else {
        printf("Elemento %d não encontrado na lista.\n", alvo);
    }
    printf("\n");

    printf("Nós: ");
    imprime_no(no);
    printf("\n");
    printf("Tamanho: %d", pilha.size);
    printf("\n");
    printf("Remover 1º elemento: ");
    remove_pilha(&pilha, &no);
    imprime_no(no);
    printf("\n");
    alvo = 2;
    resultado = busca_pilha(no, alvo);
    if(resultado != NULL){
        printf("Elemento %d encontrado na lista.\n", alvo);
    } else {
        printf("Elemento %d não encontrado na lista.\n", alvo);
    }
    printf("\n");

    printf("Nós: ");
    imprime_no(no);
    printf("\n");
    printf("Tamanho: %d", pilha.size);
    printf("\n");
    printf("Remover 1º elemento: ");
    remove_pilha(&pilha, &no);
    imprime_no(no);
    printf("\n");
    alvo = 10;
    resultado = busca_pilha(no, alvo);
    if(resultado != NULL){
        printf("Elemento %d encontrado na lista.\n", alvo);
    } else {
        printf("Elemento %d não encontrado na lista.\n", alvo);
    }
    printf("\n");

    printf("Nós: ");
    imprime_no(no);
    printf("\n");
    printf("Tamanho: %d", pilha.size);
    printf("\n");
    printf("Remover 1º elemento: ");
    remove_pilha(&pilha, &no);
    imprime_no(no);
    printf("\n");
    alvo = 20;
    resultado = busca_pilha(no, alvo);
    if(resultado != NULL){
        printf("Elemento %d encontrado na lista.\n", alvo);
    } else {
        printf("Elemento %d não encontrado na lista.\n", alvo);
    }




    destruir(&no);

    return 0;
}