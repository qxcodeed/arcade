# Escapando do labirinto

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/labirinto/cover.jpg)

Um labirinto perfeito é um labirinto no qual entre dois quaisquer pontos existe apenas um único caminho.

Leia uma matriz que representa um labirinto perfeito, os pontos de inicio e fim e imprima o labirinto mostrando o caminho entre os pontos.

- Entrada
  - Linha 1: número de linhas e das colunas da matriz
  - Linhas subsequentes: matriz composta por 4 caracteres
    - `#` representa uma parede
    - `_` representa um corredor por onde se pode andar
    - `I` representa o início
    - `F` representa o fim

- Saída
  - Imprima a matriz utilizando o char `.` para mostrar o caminho entre início e fim


```txt
>>>>>>>>
10 20
####################
#___#_#_#_#___#_##_#
###_#_____###______#
##__##_##___#_###_##
#_I##___###_###____#
#_#####_#___#___##_#
#_#_____##_###_##__#
#_##_####___#__#__##
#___F#____#___##_###
####################
========
####################
#___#_#_#_#___#_##_#
###_#_____###______#
##__##_##___#_###_##
#..##___###_###____#
#.#####_#___#___##_#
#.#_____##_###_##__#
#.##_####___#__#__##
#....#____#___##_###
####################
<<<<<<<<


>>>>>>>>
10 30
##############################
#__#________##_#_#_##_______##
##_#_##_##_##____#_#__##_##__#
##_###__#I____##___####___##_#
#__##__###########___#__#__#_#
#_##__##_F_#_#___###_#######_#
#_##_###_###___#___#_##___#__#
#__#_#_#_#___#####_#_#__#_#_##
##___#_____#_____#_____##____#
##############################
========
##############################
#__#________##_#_#_##_______##
##_#_##_##_##....#_#__##_##__#
##_###__#.....##...####___##_#
#__##__###########...#__#__#_#
#_##__##.._#_#...###.#######_#
#_##_###.###...#...#.##___#__#
#__#_#_#.#...#####.#.#__#_#_##
##___#__...#_____#...__##____#
##############################
<<<<<<<<
```

## Help

Você pode usar esse código como ajuda. Ele carrega a matriz e mostra. O método `get_vizinhos` é bem útil para iterar nos vizinhos de um ponto.

```c++
#include <iostream>
#include <vector>
using namespace std;

struct Pos{
    int l;
    int c;
};

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}


int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = '_';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = '_';
                fim = Pos {l, c};
            }
        }
    }

    for(string line : mat)
        cout << line << endl;
    cout << "       nl=" << nl << " nc=" << nc << "\n";
    cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl;
}
```
