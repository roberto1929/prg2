cmake_minimum_required(VERSION 3.26)
project(aula_8 C)

set(CMAKE_C_STANDARD 17)

add_executable(aula_8 main.c
        fatorial.c
        fatorial.h
        fibonacci.c
        fibonacci.h
        fibo_rec.c
        fibo_rec.h
)
