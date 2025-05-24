# Percorrer in-order

<!--TOC_BEGIN-->
- [Descrição](#descrição)
- [lib](#lib)
- [Arquivos](#arquivos)
- [Testes](#testes)
<!--TOC_END-->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/dividido/cover.jpg)

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

- [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/dividido/main.cpp)
- [student.cpp](https://github.com/qxcodeed/arcade/blob/master/base/dividido/student.cpp)
- [lib.h](https://github.com/qxcodeed/arcade/blob/master/base/dividido/lib.hpp)
- [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/dividido/lib.cpp)

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
