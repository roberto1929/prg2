//
// Created by aluno on 22/08/23.
//
#include <stdio.h>
#include "fatorial.h"

int fatorial_inte(int n){
    while (n > 1) {
        n = n * (n-1);
        break;
    }
}