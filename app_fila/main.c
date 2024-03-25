#include <stdio.h>
#include <libprg/libprg.h>


int main(void){
    int tamanho,op, elemento, temp, deq = 0;
    fila_t fila = {NULL, 0,0,0,0,};

    printf("Bem vindo ao programa de teste de fila\n");
    while (1){
        printf("MENU\n");
        printf("1- Criar uma fila\n");
        printf("2- Inserir um novo elemento;\n");
        printf("3- Remover um elemento\n");
        printf("Selecione a opção:");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Entre com o tamanho da fila:");
                scanf("%d", &tamanho);
                if(criar_fila(&fila, tamanho) == 0){
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
