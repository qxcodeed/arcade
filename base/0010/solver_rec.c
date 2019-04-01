#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "_create_rec.h"


int main(int argc, char * argv[]){
    srand(time(NULL));
    int nl = 10;
    int nc = 30;

    if(argc > 2){
        nl = atoi(argv[1]);
        nc = atoi(argv[2]);
    }

    char mat[nl][nc];
    create_lab(nl, nc, mat);

    printf("%d %d\n", nl, nc);
    show(nl, nc, mat);
}