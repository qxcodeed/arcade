## 04.1 Labirinto Criando com Recursão video
## @qxcode

!toc

<!-- include (solver.c lang=c) -->
```c
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>
# include "xpaint.h"

# include "xmat.h"

typedef struct _Pos{
    int l;
    int c;
} Pos;

# define get_neibs(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

void shuffle(Pos vet[], int size){
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        Pos aux = vet[i];
        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}

bool equals(int nl, int nc, char mat[nl][nc], int l, int c, char value){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return false;
    return mat[l][c] == value;
}

bool eh_furavel(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!equals(nl, nc, mat, l, c, '#'))
        return false;
    int cont = 0;
    Pos neibs[] = get_neibs(l, c);
    for(int i = 0; i < 4; i++)
        if(equals(nl, nc, mat, neibs[i].l, neibs[i].c, '#'))
            cont++;
    if(cont < 3)
        return false;
    return true;
}

void furar(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!eh_furavel(nl, nc, mat, l, c)){
        return;
    }
    mat[l][c] = ' ';
    
    x_clear(WHITE);
    xmat_draw(nl, nc, mat);
    xmat_put_circle(l, c, GREEN);
    x_log("lab");

    Pos neibs[] = get_neibs(l, c);
    shuffle(neibs, 4);
    for(int i = 0; i < 4; i++){
        x_clear(WHITE);
        xmat_draw(nl, nc, mat);
        xmat_put_circle(neibs[i].l, neibs[i].c, YELLOW);
        xmat_put_circle(l, c, GREEN);
        xmat_put_number(neibs[i].l, neibs[i].c, WHITE, i);
        x_log("lab");
        furar(nl, nc, mat, neibs[i].l, neibs[i].c);    
    }
    mat[l][c] = 'x';
    x_clear(WHITE);
    xmat_draw(nl, nc, mat);
    xmat_put_circle(l, c, GREEN);
    x_log("lab");
}

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == '#')
                printf("█");
            else
                printf("%c", mat[l][c]);
        }
        puts("");
    }
}

void create_lab(int nl, int nc, char mat[nl][nc]){
    char * p = &mat[0][0];
    for(int i = 0; i < nl * nc; i++)
        p[i] = '#';
    furar(nl, nc, mat, 1, 1);
}

int main(int argc, char * argv[]){
    srand(time(NULL));
    int nl = 20;
    int nc = 20;

    if(argc > 2){
        nl = atoi(argv[1]);
        nc = atoi(argv[2]);
    }

    char mat[nl][nc];
    xmat_init(nl, nc);
    xs_palette(' ', ORANGE);
    xs_palette('#', BLACK);
    xs_palette('x', WHITE);
    MAT_DELTA = 1;
    create_lab(nl, nc, mat);

    //printf("%d %d\n", nl, nc);
    //show(nl, nc, mat);
    x_close();
}```
<!-- /include -->
