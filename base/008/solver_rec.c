#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>//srand e rand
#include <time.h>

typedef struct{
    int l, c;
} Indice;


int nl, nc;
const char WALL = '#';
const char OPEN = ' ';

const int delta_l[] = {0, -1, 0, 1};
const int delta_c[] = {-1, 0, 1, 0};
const int N_NEIBS = 4;

#define SWAP(a, b, type) do{type SWAP = a; a = b; b = SWAP;}while(0)

bool is_inside(Indice ind){
    return (ind.l >= 0 && ind.l < nl && ind.c >= 0 && ind.c < nc);
}

bool has_value(char * mat, int l, int c, char value){
    if(l < 0 || l >= nl || c < 0 || c >= nc)
        return false;
    return mat[l * nc + c] == value;    
}

bool search(char * mat, bool * vis, Indice pos, Indice pend){
    if(!is_inside(pos) || (mat[pos.l * nc + pos.c] == WALL) || vis[pos.l * nc + pos.c])
        return false;
    vis[pos.l * nc + pos.c] = true;
    bool is_path = false;
    if((pos.l == pend.l) && (pos.c == pend.c))
        is_path = true;
    else{
        for(size_t i = 0; i < 4; i++){
            if(search(mat, vis, (Indice){pos.l + delta_l[i], pos.c + delta_c[i]}, pend)){
                is_path = true;
                break;
            }
        }
    }
    if(is_path){
        mat[pos.l * nc + pos.c] = '.';
        printf("[%d %d]", pos.l, pos.c);
        return true;
    }
    return false;   
}

int main(){
    scanf("%d %d", &nl, &nc);
    Indice pbegin;
    scanf("%d %d", &pbegin.l, &pbegin.c);
    Indice pend;
    scanf("%d %d", &pend.l, &pend.c);
    getchar(); //remove \n

    char mat[nl * nc]; //reading mat
    {
        char line[nc + 2]; //+1 para \0 e +1 para \n que o fgets pega
        for(int i = 0; i < nl; i++){
            fgets(line, sizeof(line), stdin);
            memcpy(&mat[i * nc], line, nc);
        }
    }
    bool vis[nl * nc]; //initialize visitados
    for(int i = 0; i < nl * nc; i++)
        vis[i] = false;
    search(mat, vis, pend, pbegin);

    printf("\n%d %d\n", nl, nc);
    {
        char line[nc + 1];
        line[nc] = '\0';
        for(int i = 0; i < nl; i++){
            memcpy(line, &mat[i * nc], nc);
            puts(line);
        }
    }
}