#include <stdio.h>
#include <locale.h>

int primeiro_ex();
int segundo_ex()


int main(int argc, char* argv[]) {
    printf("Bem vindo!\n");
    int escolha;
    setlocale(LC_ALL, "Portuguese");

    do {
        printf("Menu:\n");
        printf("1- Encontrar o maior valor\n");
        printf("2- Sorteie um número de forma pseudo aleatória\n");
        printf("3- Informar números pares e impares\n");
        printf("4- Simuador de jogo de azar\n");
        printf("5- Elemento excluido do vetor\n");
        printf("6- Matriz de identidade\n");
        printf("7- Palindromo\n");
        printf("8- Contador de vogal\n");
        printf("0- Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: primeiro_ex();
                break;
            case 2: segundo_ex();
                break;
            case 3:;
                break;
            case 4:;
                break;
            case 5:;
                break;
            case 6:;
                break;
            case 7:;
                break;
            case 8:;
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");

        }
    } while (escolha !=0);
    return 0;
}
