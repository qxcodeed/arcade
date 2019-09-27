## $06_tree_ 4. Tree Caminhos para o nó #doing
## @qxcode

![](__capa.jpg)

- Entrada
    - linha 1: o serial de uma árvore binária
    - linha 2: um valor de nó
- Saída
    - para nó da árvore que tenha o valor procurado, mostre o caminho da raiz até o nó, indicando 'l' ou 'r' se o caminho é pelo filho da esquerda ou da direita. 
    - Inicio com um '>' para o root e ponha um 'x' quando achar o nó.
    - Se o valor não existir na árvore, imprima valor não encontrado.
- Limitação
    - Você deve percorrer a árvore uma única vez para obter os caminhos.

```cpp
struct Node{
    int value;
    Node * left, * right;
};

string find_path(Node * root, int value);
```

```
>>>>>>>> 01 um
4 # #
4
========
>x
<<<<<<<<

>>>>>>>> 02 dois
1 # 0 # # 
0
========
>rx
<<<<<<<<

>>>>>>>> 03 tres
4 # 8 2 # # # 
2
========
>rlx
<<<<<<<<

>>>>>>>> 04 not found
0 9 4 # # # 5 # # 
7
========
value not fount
<<<<<<<<

```
