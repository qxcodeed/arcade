#include <stdio.h>
#include <string.h>
#define XPAINT
#include "xpaint.h"

void create_img(int nl, int nc, char mat[nl][nc]) {
    x_open(nc * 30, nl * 30, "lab");
    x_grid_init(30, 1);
    x_color_set(WHITE);
    x_clear();
    for(int l = 0; l < nl; l++) {
        for(int c = 0; c < nc; c++) {
            if(mat[l][c] == '#'){
                x_color_set(BLACK);
                x_grid_square(l, c);
            } else if(mat[l][c] == ' ') {
                x_color_set(WHITE);
                x_grid_square(l, c);
            }
        }
    }
    x_save();
    x_close();
}

void load_mat_from_file(int nl, int nc, char mat[nl][nc], const char * path) {
    FILE * file = fopen(path, "r");
    if(file == NULL) {
        puts("arquivo nao encontrado");
        exit(1);
    }
    char line[500];
    fgets(line, sizeof(line), file);
    sscanf(line, "%d %d", &nl, &nc); //reading dimensions

    for(int i = 0; i < nl; i++){
        fgets(line, sizeof(line), file); //reading line
        for(int j = 0; j < nc; j++) //copying data to matriz
            mat[i][j] = line[j];
    }
}

int main(int argc, char * argv[]){
    int nl = 0;
    int nc = 0;
    char path[100];
    if(argc == 1) {
        puts("you need pass the path to your lab as argument");
        return 1;
    } else {
        strcpy(path, argv[1]);
    }
    char mat[nl][nc];
    load_mat_from_file(nl, nc, mat, path);
    create_img(nl, nc, mat);
    return 0;
}
