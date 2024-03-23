# L2 - fugindo do labirinto @pilhado

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/pilhado/cover.jpg)

Você vai tentar fugir do labirinto usando uma pilha no lugar da recursão.

Um labirinto perfeito é um labirinto no qual entre dois quaisquer pontos existe apenas um único caminho.

Leia uma matriz que representa um labirinto perfeito, os pontos de inicio e fim e imprima o labirinto mostrando o caminho entre os pontos.

- Entrada

  - Linha 1: número de linhas e das colunas da matriz
  - Linhas subsequentes: matriz composta por 4 caracteres
    - `#` representa uma parede
    - ` ` (espaço vazio) representa um corredor por onde se pode andar
    - `I` representa o início
    - `F` representa o fim

- Saída
  - Imprima a matriz utilizando o char `.` para mostrar o caminho entre início e fim

## Arquivos

- Você deve implementar:
  - [student.cpp](https://github.com/qxcodeed/arcade/blob/master/base/pilhado/student.cpp)
    - escrever a função procurar_saida e get_vizinhos.
- Já está implementado:
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/pilhado/main.cpp)
    - Faz a leitura do numero de linhas, numero de colunas e da matriz com os pontos de início e final marcados
    - Chama a função procurar_saida.
    - Imprime a matriz com o caminho marcado.
  - [lib.hpp](https://github.com/qxcodeed/arcade/blob/master/base/pilhado/lib.h)
    - Apenas o cabeçalho da função procurar_saida e get_vizinhos.

## Testes

```txt
>>>>>>>>
10 20
####################
#   # # # #   # ## #
### #     ###      #
##  ## ##   # ### ##
# I##   ### ###    #
# ##### #   #   ## #
# #     ## ### ##  #
# ## ####   #  #  ##
#   F#    #   ## ###
####################
========
####################
#   # # # #   # ## #
### #     ###      #
##  ## ##   # ### ##
#..##   ### ###    #
#.##### #   #   ## #
#.#     ## ### ##  #
#.## ####   #  #  ##
#....#    #   ## ###
####################
<<<<<<<<


>>>>>>>>
10 30
##############################
#  #        ## # # ##       ##
## # ## ## ##    # #  ## ##  #
## ###  #I    ##   ####   ## #
#  ##  ###########   #  #  # #
# ##  ## F # #   ### ####### #
# ## ### ###   #   # ##   #  #
#  # # # #   ##### # #  # # ##
##   #     #     #     ##    #
##############################
========
##############################
#  #        ## # # ##       ##
## # ## ## ##....# #  ## ##  #
## ###  #.....##...####   ## #
#  ##  ###########...#  #  # #
# ##  ##.. # #...###.####### #
# ## ###.###...#...#.##   #  #
#  # # #.#...#####.#.#  # # ##
##   #  ...#     #...  ##    #
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
