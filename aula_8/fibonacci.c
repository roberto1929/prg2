//
// Created by aluno on 28/08/23.
//

#include "fibonacci.h"
#include <stdio.h>

int fibonacci(int n)
{
    int p=0;
    int s=1;
    if(n <= 0){
        return 0;
    }
    if(n ==1){
        printf("0\n");
        return 0;
    }
    printf("0 1 ");
    for (int i = 0; i < n; i++) {
        int atual = p + s;
        printf("%d ", atual);
        p = s;
        s = atual;
    }
    return 0;
}

