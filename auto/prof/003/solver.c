#include <stdio.h>

#define PROF
#ifdef PROF
const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.'; 
#else
#endif

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        puts("");
    }
}

void tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
#ifdef PROF
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return;
    if(mat[l][c] != TREE)
        return;
    mat[l][c] = FIRE;
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
    int l = 0;
    int c = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &l, &c);
    char mat[nl][nc];
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            scanf(" %c", &mat[l][c]);
    tocar_fogo(nl, nc, mat, l, c);
    show(nl, nc, mat);
}
