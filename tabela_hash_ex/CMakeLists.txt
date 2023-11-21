cmake_minimum_required(VERSION 3.26)
project(prg2 C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fsanitize=address")

add_executable(prg2 main.c)