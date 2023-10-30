//
// Created by aluno on 24/10/23.
//

#include "relogio_cpu.h"
#include <libprg/libprg.h>


int relogio_cpu(int argc, char **argv) {
    //https://www.gnu.org/software/libc/manual/html_node/CPU-Time.html
    clock_t start, end;
    double cpu_time_used;

    // Iniciando tomada de tempo
    start = clock();
    
    // Finalizando tomada de tempo
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto de CPU: %f segundos.\n", cpu_time_used);
    return 0;
}
