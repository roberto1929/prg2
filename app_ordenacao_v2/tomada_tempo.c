//
// Created by aluno on 24/10/23.
//

#include "tomada_tempo.h"
#include <libprg/libprg.h>

int relogio_parede(int argc, char **argv) {
    struct timeval inicio, fim;

    // Iniciando tomada de tempo
    gettimeofday(&inicio, 0);

    // Finalizando tomada de tempo
    gettimeofday(&fim, 0);

    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);

    return 0;
}

int relogio_cpu(){

}