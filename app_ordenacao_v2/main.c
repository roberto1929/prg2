#include <libprg/libprg.h>



int main() {

    sort_t sort;
    cria_sort(&sort, 5);

    preencher_sort(&sort, 5);

//    bubble_sort(&sort, true);
//    insertion_sort(&sort);
//    selection_sort(&sort, true);
    imprimir_ord(&sort);

    return 0;
}
