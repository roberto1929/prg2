cmake_minimum_required(VERSION 3.21)
project(app_ord_texto C)

set(CMAKE_C_STANDARD 17)

include(FetchContent)

cmake_policy(SET CMP0135 NEW)

FetchContent_Declare(
        libprg
        #GIT_REPOSITORY https://github.com/roberto1929/libprg.git
        #GIT_TAG 0.0.1
        # You can reference a local directory instead
        URL file:///${CMAKE_CURRENT_SOURCE_DIR}/../../libprg
)
FetchContent_MakeAvailable(libprg)

add_executable(app_ord_texto main.c
)
target_link_libraries(app_ord_texto PUBLIC libprg)