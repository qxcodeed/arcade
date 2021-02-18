#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "solver_lib.h"


int main(int argc, char * argv[]){
    srand(time(NULL));
    int nl = 30;
    int nc = 30;

    if(argc > 2){
        nl = atoi(argv[1]);
        nc = atoi(argv[2]);
    }

    char mat[nl * nc];
    create_lab(mat, nl, nc);

    printf("%d %d\n", nl, nc);
    show_full(mat, nl, nc);
}