#include <stdio.h>
#define XPAINT_FULL
#include <xpaint.h>


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
    x_open(nl * 30, nc * 30, "lab");
    x_grid_init(30, 1);
    xs_palette('#', x_make_color(0, 0, 0, 255));
    xs_palette(' ', x_make_color(255, 255, 255, 255));
    x_set_scolor("white");
    x_clear();
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == '#'){
                x_set_scolor("black");
                x_grid_square(l, c);
            }else if(mat[l][c] == ' '){
                x_set_scolor("white");
                x_grid_square(l, c);
            }
        }
    }
    x_save();
    x_close();
}
