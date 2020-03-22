#include <stdio.h>

#define PROF
#ifdef PROF
const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.'; 
#else
#endif

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
#ifdef PROF
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return;
    if(mat[l * nc + c] != TREE)
        return;
    mat[l * nc + c] = FIRE;
    tocar_fogo(nl, nc, mat, l, c + 1);
    tocar_fogo(nl, nc, mat, l, c - 1);
    tocar_fogo(nl, nc, mat, l - 1, c);
    tocar_fogo(nl, nc, mat, l + 1, c);
#else
    //TODO faca seu codigo aqui
#endif
}

int main(){
    int nl = 0;
    int nc = 0;
    int _l = 0;
    int _c = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &_l, &_c);
    char mat[nl][nc];
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            scanf(" %c", &mat[l][c]);
    tocar_fogo(nl, nc, &mat[0][0], _l, _c);
    show(nl, nc, &mat[0][0]);
}
