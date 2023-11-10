cmake_minimum_required(VERSION 3.14)
project(app_lista C)

set(CMAKE_C_STANDARD 11)

# Adicione a biblioteca libprg como dependência usando FetchContent
include(FetchContent)
FetchContent_Declare(
        libprg
        GIT_REPOSITORY https://github.com/roberto1929/libprg.git
        GIT_TAG master
)
FetchContent_MakeAvailable(libprg)

# Defina o executável e inclua os diretórios de inclusão e bibliotecas
add_executable(app_lista main.c)
target_include_directories(app_lista PRIVATE ${libprg_SOURCE_DIR}/include)
target_link_libraries(app_lista PRIVATE libprg)

# Mensagens informativas
message(STATUS "libprg_SOURCE_DIR: ${libprg_SOURCE_DIR}")
message(STATUS "libprg_BINARY_DIR: ${libprg_BINARY_DIR}")