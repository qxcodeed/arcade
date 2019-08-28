## @047 10.4 Tree Caminhos para o nó         #doing
## @qxcode

- Entrada
    - linha 1: o serial de uma árvore binária
    - linha 2: um valor de nó
- Saída
    - para nó da árvore que tenha o valor procurado, mostre um por linha o caminho da raiz até o nó, indicando 'l' ou 'r' se o filho é da esquerda ou da direita e -1 se o nó não existir.
- Limitação
    - Você deve percorrer a árvore uma única vez para obter os caminhos.

```cpp
struct Node{
    int value;
    Node * left, * right;
};

struct Tree{
    Node * root;
};

string find_path(Node * root, int value);
```
```
>>>>>>>> 01 um
4 # #
4
========
x
<<<<<<<<

>>>>>>>> 02 dois
1 # 0 # # 
0
========
rx
<<<<<<<<

>>>>>>>> 03 tres
4 # 8 2 # # # 
2
========
rlx
<<<<<<<<

>>>>>>>> 04 quatro
0 9 4 # # # 5 # # 
5
========
rx
<<<<<<<<

>>>>>>>> 05 quatro not found
0 9 4 # # # 5 # # 
7
========
-1
<<<<<<<<

>>>>>>>> 06 cinco
0 4 # # 2 0 # # 4 # # 
4
========
[ 0 l4 ]
[ 0 r2 r4 ]
<<<<<<<<

>>>>>>>> 07 seis
2 9 5 # # # 9 # 7 # 9 # # 
9
========
[ 2 l9 ]
[ 2 r9 ]
[ 2 r9 r7 r9 ]
<<<<<<<<

>>>>>>>> 08 dez
1 8 7 # # 5 # 6 # # 5 0 # # 9 # 5 2 # # # 
5
========
[ 1 l8 r5 ]
[ 1 r5 ]
[ 1 r5 r9 r5 ]
<<<<<<<<

```
