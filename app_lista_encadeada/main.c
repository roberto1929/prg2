#include <stdio.h>
#include <libprg/libprg.h>

int main() {
    // Inicializar sua estrutura de dados aqui

    int opcao;
    while (1) {
        printf("Menu:\n");
        printf("1. Criar estrutura de dados\n");
        printf("2. Inserir elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Buscar elemento\n");
        printf("5. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Implementar a criação de estrutura de dados aqui
                break;
            case 2:
                // Implementar a inserção de elementos aqui
                break;
            case 3:
                // Implementar a remoção de elementos aqui
                break;
            case 4:
                // Implementar a busca de elementos aqui
                break;
            case 5:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
}
