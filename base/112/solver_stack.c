#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>//srand e rand
#include <time.h>

typedef struct {
    int l, c;
} Pos;

#define MAX 200000
const char WALL = '#';
const char OPEN = ' ';

const int N_NEIBS = 4;

#define get_neibs(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}
#define SWAP(a, b, type) do{type SWAP = a; a = b; b = SWAP;}while(0)

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

void break_walls(int nl, int nc, char mat[nl][nc], int l, int c){
    Pos stack[MAX];
    int stack_size = 0;
    mat[l][c] = OPEN;
    stack[stack_size++] = (Pos){l, c}; //push_back

    while(stack_size > 0){
        Pos neibs[4];
        size_t neibs_size = 0;

        Pos top = stack[stack_size - 1];
        Pos all_neibs[] = get_neibs(top.l, top.c);
        for(size_t i = 0; i < 4; i++){
            Pos neib = all_neibs[i];
            if(!equals(nl, nc, mat, neib.l, neib.c, WALL))
                continue;
            if(!eh_furavel(nl, nc, mat, neib.l, neib.c))
                continue;
            neibs[neibs_size++] = neib;
        }
        if(neibs_size == 0)
            stack_size--;
        else{
            Pos chosen = neibs[rand() % neibs_size];
            stack[stack_size++] = chosen;
            mat[chosen.l][chosen.c] = OPEN;
        }
    }
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

int main(int argc, char * argv[]){
    srand(time(NULL));
    int nl = 10; 
    int nc = 30;
    if(argc > 2){
        nl = atoi(argv[1]);
        nc = atoi(argv[2]);
    }
    char mat[nl][nc];
    char * vet = &mat[0][0];
    for(int i = 0; i < nc * nl; i++)
        vet[i] = '#';

    break_walls(nl, nc, mat, 1, 1);

    printf("%d %d\n", nl, nc);

    show(nl, nc, mat);
}