#include <stdio.h>

long fib_ite(int n){
    if (n == 0){
        return 0;
    }
    long a = 0;
    long b = 1;
    for (int i = 0; i < n; ++i) {
        int k = a+b;
        a = b;
        b = k;
    }
}

long fib_rec(int n){
    if((n ==0)|| (n ==1)){
        return n;
    } return (fib_rec(n-1)+ fib_rec(n-2));
}

#include <sys/time.h>

int main(int argc, char **argv) {
    struct timeval inicio, fim;

    gettimeofday(&inicio, 0);

    fib_ite(32);

    gettimeofday(&fim, 0);

    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);

    fib_rec(32);

    gettimeofday(&fim, 0);

    seg = fim.tv_sec - inicio.tv_sec;
    mseg = fim.tv_usec - inicio.tv_usec;
    tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);
    return 0;
}

