#include <stdio.h>
#include <libprg/libprg.h>


int main(void){
    int op, elemento, temp, deq = 0;
    fila_t fila;

    printf("Bem vindo ao programa de teste de fila\n");
    while (1){
        printf("MENU\n");
        printf("1- Criar uma fila\n");
        printf("2- Inserir um novo elemento;\n");
        printf("3- Remover um elemento\n");
        printf("4- Exibir fila\n");
        printf("Selecione a opção:");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Entre com o tamanho da fila:");
                scanf("%d", &fila.tamanho);
                if(criar_fila(&fila, fila.tamanho) == 0){
                    printf("Estouro de memoria");
                };
                break;
            case 2:
                if (fila.vetor != NULL) { // Verifica se a fila foi criada
                    printf("Entre com o elemento que será inserido:");
                    scanf("%d", &elemento);
                    if (enqueue(&fila, elemento) == 1) {
                        printf("Não há espaço na fila\n");
                    } else {
                        for (int i = 0; i < fila.total; ++i) {
                            printf("%d ", fila.vetor[i]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("Fila não foi criada ainda\n");
                }
                break;
            case 3:
                if (fila.vetor != NULL) {
                    temp = dequeue(&fila);
                    if (temp == -1) {
                        printf("A fila está vazia");
                    } else {
                        printf("Elemento removido: %d\n", temp);
                    }
                } else {
                    printf("Fila não foi criada ainda\n");
                }
                break;
            case 4:
                if (empty(&fila)){
                    printf("Fila vazia\n");

                } else {
                    printf("Fila: ");
                    int i;
                    for (i = 0; i < fila.total; i++) {
                        printf("%d ", fila.vetor[(fila.inicio + i) % fila.tamanho]);
                    }
                    printf("\n");
                }
                break;
            case 0:
                printf("Encerrando programa\n");
                if (fila.vetor != NULL) {
                    free(fila.vetor);
                }
                return 0;
            default:
                printf("Opção invalida\n");
        }
    }
}
