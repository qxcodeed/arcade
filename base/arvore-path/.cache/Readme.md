# Caminho até o nó

<!--TOC_BEGIN-->
- [Descrição](#descrição)
- [Exemplo](#exemplo)
- [Testes](#testes)
- [Código base](#código-base)
<!--TOC_END-->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/arvore-path/cover.jpg)

## Descrição

- Entrada
  - linha 1: o serial de uma árvore binária
  - linha 2: um valor de nó
- Saída
  - se o valor existe:
    - mostre o caminho da raiz até o nó,
    - indicando 'l' ou 'r' se o caminho é pelo filho da esquerda ou da direita.
    - ponha um 'x' para quando achar o nó.
  - Se o valor não existir na árvore
    - imprima "!"
- Limitação
  - Você deve percorrer a árvore UMA única vez para obter os caminhos e montar o caminho através do retorno da função.

## Exemplo

Para encontrar o 2 na árvore abaixo, seguimos o caminho `rrrlx`

```c
//serial
1 8 7 # # 4 # 6 # # 5 0 # # 9 # 3 2 # # #

//bshow()
    ┌───7
┌───8
│   │   ┌───#
│   └───4
│       └───6
1
│   ┌───0
└───5
    │   ┌───#
    └───9
        │   ┌───2
        └───3
            └───#
```

```cpp
//a função recursiva find deve retornar uma sequencia o path até o destino com x no final
string find_path(Node * root, int value);
```

## Testes

```txt
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

>>>>>>>> 04 not found
0 9 4 # # # 5 # # 
7
========
!
<<<<<<<<

>>>>>>>>
1 8 7 # # 4 # 6 # # 5 0 # # 9 # 3 2 # # #
2
========
rrrlx
<<<<<<<<

```

## Código base

```cpp
#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root;
    BTree(){
        this->root = nullptr;
    }

    void clone(stringstream& ss, Node ** elo){
        string value;
        ss >> value;
        if(value == "#")
            return;
        int num;
        stringstream(value) >> num;
        *elo =  new Node(num);
        clone(ss, &(*elo)->left);
        clone(ss, &(*elo)->right);
    }

    BTree(string serial){
        stringstream ss(serial);
        clone(ss, &root);
    }

    void __destroy(Node * node){
        if(node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    ~BTree(){
        __destroy(this->root);
    }

    string find_path(Node * node, int value){
        //TODO
    }
};

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    int value;
    cin >> value;
    string path = bt.find_path(bt.root, value);
    cout << path << "\n";
}
```
