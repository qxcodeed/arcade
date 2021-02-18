#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Pos{
    int l;
    int c;
} Pos;

#define get_neibs(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

void shuffle(Pos vet[], int size){
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        Pos aux = vet[i];
        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}

bool equals(char * mat, int nl, int nc, int l, int c, char value){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return false;
    return mat[l * nc + c] == value;
}

bool eh_furavel(char * mat, int nl, int nc, int l, int c){
    if(!equals(mat, nl, nc, l, c, '#'))
        return false;
    int cont = 0;
    Pos neibs[] = get_neibs(l, c);
    for(int i = 0; i < 4; i++)
        if(equals(mat, nl, nc, neibs[i].l, neibs[i].c, '#'))
            cont++;
    if(cont < 3)
        return false;
    return true;
}

void furar(char * mat, int nl, int nc, int l, int c){
    if(!eh_furavel(mat, nl, nc, l, c))
        return;
    mat[l * nc + c] = ' ';
    Pos neibs[] = get_neibs(l, c);
    shuffle(neibs, 4);
    for(int i = 0; i < 4; i++)
        furar(mat, nl, nc, neibs[i].l, neibs[i].c);    
}

void lab_show(char * mat, int nl, int nc){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l * nc + c] == '#')
                printf("#");
            else
                printf("%c", mat[l * nc + c]);
        }
        puts("");
    }
}

//fill a matriz with a lab
//mat should have size nl * nc 
void lab_fill(char * mat, int nl, int nc){
    for(int i = 0; i < nl * nc; i++)
        mat[i] = '#';
    furar(mat, nl, nc, 1, 1);
}