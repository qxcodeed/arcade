# Percorrer in-order

<!--TOC_BEGIN-->
- [Descrição](#descrição)
- [lib](#lib)
- [Arquivos](#arquivos)
- [Testes](#testes)
<!--TOC_END-->

![_](cover.jpg)

## Descrição

- Leia a string que representa a árvore serializada.
- Você deve construir a árvore a partir da string implementando corretamente o construtor do código de partida.
- Você pode entender a lógica de serialização no seguinte [link](https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/).
- A saída é a árvore percorrida in-order, mas já está implementado.

## lib

- lib.hpp

<!--ADD lib.hpp cpp-->
```cpp
#pragma once
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

class BTree {
public:
    Node * root {nullptr};
    BTree(string serial);
    ~BTree();
    std::string format();
    std::string in_order();
};
```
<!--ADD_END-->

## Arquivos

- [main.cpp](main.cpp)
- [student.cpp](student.cpp)
- [lib.h](lib.hpp)
- [lib.cpp](lib.cpp)

## Testes

```txt
>>>>>>>> um
4 # # 
========
[ 4 ]
<<<<<<<<

>>>>>>>> dois
1 # 0 # # 
========
[ 1 0 ]
<<<<<<<<

>>>>>>>> tres
4 # 8 2 # # # 
========
[ 4 2 8 ]
<<<<<<<<

>>>>>>>> quatro
0 9 4 # # # 5 # # 
========
[ 4 9 0 5 ]
<<<<<<<<

>>>>>>>> cinco
0 4 # # 2 0 # # 3 # # 
========
[ 4 0 0 2 3 ]
<<<<<<<<

>>>>>>>> seis
2 0 0 # # # 3 # 7 # 9 # # 
========
[ 0 0 2 3 7 9 ]
<<<<<<<<

>>>>>>>> dez
1 8 7 # # 4 # 6 # # 5 0 # # 9 # 3 2 # # # 
========
[ 7 8 4 6 1 0 5 9 2 3 ]
<<<<<<<<
```
