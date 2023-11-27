#include <stdio.h>
#include <libprg/libprg.h>

clock_t start = 0, end;
struct timeval inicio, fim;


int main() {
    int escolha = 0;
    arvore_t arvore;
    int n;

    while (1) {
        printf("Bem vindo, escolha entre 1 e 2");
        scanf("%d", escolha);
        switch (escolha) {
            case 1:
                printf("Entre com um n");
                scanf("%d", &n);
                criar_arvore(n);
                break;
            case 2:
                printf("Inserir números na árvore de busca binária");
                comeca(&inicio);
                inserir_valor(&arvore, n);
                double tempo_de_cpu = medir_tempo_cpu(start);
                printf("Tempo de CPU: ", tempo_de_cpu);
                break;
        }
    }

    return 0;
}
