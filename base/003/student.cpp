#include <stdio.h>

void show(int nl, int nc, char * mat){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%c", mat[l * nc + c]);
        puts("");
    }
}
/*
para acessar a posicao l, c da matriz voce deve utilizar
mat[l * nc + c]
*/
void tocar_fogo(int nl, int nc, char * mat, int l, int c){
    //TODO faca seu codigo aqui
}

int main(){
    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &l, &c);
    char mat[nl][nc];
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            scanf(" %c", &mat[l][c]);
    tocar_fogo(nl, nc, &mat[0][0], l, c);
    show(nl, nc, &mat[0][0]);
}
