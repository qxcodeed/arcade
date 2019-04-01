#include <stdio.h>
#include "xpaint.h"
#include "xmat.h"


int main(int argc, char * argv[]){
    int nl = 0;
    int nc = 0;
    char path[100] = "lab_50_70.txt";
    if(argc == 2)
    strcpy(path, argv[1]);
    FILE * file = fopen(path, "r");
    if(file == NULL){
        puts("arquivo nao encontrado");
        exit(1);
    }
    char line[500];
    fgets(line, sizeof(line), file);
    sscanf(line, "%d %d", &nl, &nc); //reading dimensions
    printf("%d %d\n", nl, nc);
    char mat[nl][nc];
    for(int i = 0; i < nl; i++){
        fgets(line, sizeof(line), file); //reading line
        for(int j = 0; j < nc; j++) //copying data to matriz
            mat[i][j] = line[j];
    }

    xmat_init(nl, nc);
    xs_palette('#', BLACK);
    xs_palette(' ', WHITE);
    x_clear(WHITE);
    xmat_draw(nl, nc, mat);
    x_save("lab");
}
