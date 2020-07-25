## #maze 1. Queimada V1 chamada recursiva
## @qxcode

![](__capa.jpg)

Dado uma matriz que representa espaços vazios e árvores e um ponto inicial onde começa o fogo, retorne a matriz com as árvores queimadas.

A matriz está codificada assim.
1a linha: `nl, nc, l, c` respectivamente
-  número de linhas e colunas da matriz, linha e coluna onde começa o fogo.
- Nas linhas subsequentes:
    - '\#' representa uma árvore
    - '.' representa um espaço vazio
    - 'o' representa uma árvore queimada

Saída esperada:
- Imprima a matriz após a queimada acontecer.

## Testes

```
>>>>>>>> 01
2 3 1 1
#.#
.##
========
#.o
.oo
<<<<<<<<

>>>>>>>> 02
5 5 0 0
#..#.
#...#
###..
..#.#
..###
========
o..#.
o...#
ooo..
..o.o
..ooo
<<<<<<<<

>>>>>>>> 03
5 7 2 3
#..#.#.
#..####
####..#
..#.#..
#.###.#
========
o..o.o.
o..oooo
oooo..o
..o.o..
#.ooo.#
<<<<<<<<

```

## Ponto de partida

```cpp
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
```
