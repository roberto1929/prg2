#include <stdio.h>
#include <libprg/libprg.h>
#include <stdlib.h>

int main() {
    clock_t start = 0, end;
    struct timeval inicio, fim;

        int escolha = 0;
            arvore_t arvore;
            int n;
            double tempo_de_cpu, tempo_parede;

            printf("Entre com um n: ");
            scanf("%d", &n);
            criar_arvore(n);

            printf("Inserir números na árvore de busca binária\n");
            comeca(&inicio);
            inserir_valor(&arvore, n);
            tempo_de_cpu = medir_tempo_cpu(start);
            printf("Tempo de CPU: %f\n", tempo_de_cpu);
            free(arvore);
            comeca(&inicio);
            inserir_valor(&arvore, n);
            tempo_parede = medir_tempo_cpu(start);
            printf("Tempo de parede: %f", tempo_parede);
            free(arvore);

    return 0;
}
