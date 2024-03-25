#include <stdio.h>
#include <libprg/libprg.h>

typedef struct {
    int op, elemento, temp, deq;
} temp_t;


int main(void){

    temp_t temp;
    fila_t fila;
    printf("Bem vindo ao programa de teste de fila\n");
    while (1){
        printf("MENU\n");
        printf("1- Criar uma fila\n");
        printf("2- Inserir um novo elemento;\n");
        printf("3- Remover um elemento\n");
        printf("Selecione a opção:");
        scanf("%d", &temp.op);

        switch (temp.op) {
            case 1:
                printf("Etre com o tamanho da fila:");
                scanf("%d", &fila.fila->tamanho);
                if(cria(fila.fila, fila.fila->tamanho) == -1){
                    printf("Estouro de memoria");
                };
                break;
            case 2:
                printf("Entre com o elemento que será inserido:");
                scanf("%d", temp.elemento);
                if(enqueue(&fila, temp.elemento) == -1){
                    printf("Não há espaço na fila");
                } else {
                    for (int i = 0; i < fila.fila->total; ++i) {
                        printf("%d", fila.fila->vetor[i]);
                    }
                    printf("\n");
                }break;
            case 3:
                temp.temp = dequeue(&fila);
                if(temp.temp == -1){
                    printf("A fila está vazia");
                } else {
                    printf("Elemento removido: %d\n", temp.temp);
                    temp.deq--;
                }
                printf("\n");
                break;
            case 0:
                printf("Encerrando programa\n");
                libera_memoria(&fila);
                return 0;
            default:
                printf("Opção invalida\n");
        }
    }
}
