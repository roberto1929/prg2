//
// Created by aluno on 28/08/23.
//
#include <stdio.h>
#include "fibo_rec.h"
    int fibo_rec(int n){
        if( (n == 0) || (n == 1)){
            return n;
        }
        int atual = fibo_rec(n - 1) + fibo_rec(n - 2);
//
}