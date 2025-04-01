# Menor caminho entre dois pontos

![_](cover.jpg)

Dessa vez, o labirinto não é perfeito e existem múltiplos caminhos que podem levar ao destino. Seu objetivo é implementar o algoritmo de floodfill pathfinding.

Leia uma matriz que representa um labirinto perfeito, os pontos de inicio e fim e imprima o labirinto mostrando o caminho entre os pontos.

- Entrada
  - Linha 1: número de linhas e das colunas da matriz
  - Linhas subsequentes: matriz composta por 4 caracteres
    - `#` representa uma parede
    - ` ` representa um corredor por onde se pode andar
    - `I` representa o início
    - `F` representa o fim

- Saída
  - Imprima a matriz utilizando o char `.` para mostrar o caminho entre início e fim

## Sugestão do algoritmo

```c
bool procurar_saida(vector<string> &mat, Pos inicio, Pos fim){
    iniciar uma matriz de distâncias
    iniciar a fila
    inserir a posicao inicial da fila e marcá-la com 0 na matriz de distâncias
    enquanto a fila não estiver vazia
        pegue a posição da frente
        para cada vizinho 'viz' de frente
            se ele não eh parede a ser percorrido
                marque esse vizinho na matriz
                na matriz de distância, coloque 1 a mais que a posição de 'frente'
                se esse 'viz' for o destino
                    return
        fila.pop_front();
    }
    return false;
}

```

Após encontrar a saída, refaça o caminho usando a matriz de distância para chegar no elemento início.

## Dica

- inicializar a matriz de distancia

```cpp
    vector<vector<int>> mat(nl, vector<int>(nc, -1));
```

- inicializar a fila

```cpp
    queue<Pos> fila;
```

- algoritmo de retorno

```cpp
    ponto = destino
    enquanto nao chegar na origem
        pega os vizinho de ponto
            se mat[viz] == mat[ponto] - 1
                ponto = viz
                break
```

## Testes

```txt
>>>>>>>>
10 20
####################
#   # # # #   # ## #
###       ###      #
##  ## ##     ### ##
# I##   ### ###    #
# ##### #   #   ## #
# #     ## ### ##  #
# ## ####   #  #  ##
#   F     #   ## ###
####################
========
####################
#   # # # #   # ## #
###       ###      #
##  ## ##     ### ##
#..##   ### ###    #
#.##### #   #   ## #
#.#     ## ### ##  #
#.## ####   #  #  ##
#....     #   ## ###
####################
<<<<<<<<


>>>>>>>>
10 30
##############################
#           ## # # ##       ##
## # ## ## ##    # #  ## ##  #
## ###  #I    ##   ####   ## #
#  ##  ##### ### #   #  #  # #
# ##  ## F ###   ### ####### #
# ## ### # #   #   # ##   #  #
#  #   # #   ##### # #  # # ##
##   #     #     #     ##    #
##############################
========
##############################
#           ## # # ##       ##
## # ## ## ##....# #  ## ##  #
## ###  #.....##.  ####   ## #
#  ##  ##### ###.#   #  #  # #
# ##  ## ..###...### ####### #
# ## ### #.#...#   # ##   #  #
#  #   # #...##### # #  # # ##
##   #     #     #     ##    #
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
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
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
