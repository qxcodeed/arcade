## @003 L1 - burn

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/003/cover.jpg)

Dado uma matriz que representa espaços vazios e árvores e um ponto inicial onde começa o fogo, retorne a matriz com as árvores queimadas. O fogo se não se espalha nas diagonais, apenas nas 4 direções cardeais.

A matriz está codificada assim.
1a linha: `nl, nc, l, c` respectivamente

- número de linhas e colunas da matriz, linha e coluna onde começa o fogo.
- Nas linhas subsequentes:
  - '\#' representa uma árvore
  - '.' representa um espaço vazio
  - 'o' representa uma árvore queimada

Saída esperada:

- Imprima a matriz após a queimada acontecer.

## Testes

```txt
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

## Ajuda

Você pode utilizar um vetor de strings para representar uma matriz de caracteres. Uma string é um vetor de caracteres. Dessa forma um `vector<string> mat` é uma vetor bidimensional. O exemplo a seguir já carrega a matriz na `main` e já faz um método capaz de imprimir a matriz. Você só precisa implementar o método `tocar_fogo`.

Utilize as seguintes regras para recursão.

- Se a posição for fora da matriz, retorne.
- Se a posição não for uma arvore retorne.
- Queime a arvore.
- Chame a recursão para todos os vizinhos.

```cpp
#include <iostream>
#include <vector>
using namespace std;


void show(vector<string> mat){
    for(int l = 0; l < (int) mat.size(); l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(vector<string> &mat, int l, int c){
    int nl = mat.size();
    int nc = mat[0].size();
    //TODO faca seu codigo aqui
}

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &lfire, &cfire);
    vector<string> mat;
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        mat.push_back(line);
    }
    tocar_fogo(mat, lfire, cfire);
    show(mat);
}


```
