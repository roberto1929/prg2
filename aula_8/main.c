#include <stdio.h>

int mult_ite(int m, int n){
    int resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado += m;
    }
    return resultado;
}

int mult_rec(int m, int n){
    if(n ==0){
        return 0;
    }
    return (m + mult_rec(m, n-1));
}


int main() {
    printf("%d\n", mult_ite(2,6));
    printf("%d\n", mult_rec(2,6));
    return 0;
}
