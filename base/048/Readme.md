# L2 - Carregando árvore a partir de String - Splitted files

<!--TOC_BEGIN-->
- [Descrição](#descrição)
- [Arquivos](#arquivos)
    - [Código do Estudante](#código-do-estudante)
    - [lib.hpp](#libhpp)
    - [main.cpp](#maincpp)
- [Testes](#testes)
<!--TOC_END-->

![](__capa.jpg)

## Descrição

- Leia a string que representa a árvore serializada.
- Você deve construir a árvore a partir da string implemetando corretamente o construtor do código de partida.
- Você pode entender a lógica de serialização no seguinte [link](https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/).
- A saída é a árvore percorrida in-order, mas já está implementado.


## Arquivos
### Código do Estudante
<!--ADD student.cpp cpp-->
<!--BEGIN-->
```cpp
#include <sstream>
#include <iostream>
#include "lib.hpp"
using namespace std;


BTree::BTree(string serial){
    //TODO
}
```
<!---END--->


### lib.hpp
<!--ADD lib.hpp cpp-->
<!--BEGIN-->
```cpp
#pragma once
#include <iostream>
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

class BTree{
public:
    Node * root {nullptr};
    BTree(string serial); //lib.hpp
    ~BTree();
    void bshow();
    void show_in_order();

private: //recursive
    void destroy(Node * node);
    void bshow(Node * node, string heranca);
    void show_in_order(Node * node);
};
```
<!---END--->


### main.cpp
<!--ADD main.cpp cpp-->
<!--BEGIN-->
```cpp
#include <iostream>
#include <sstream>
#include "lib.hpp"

using namespace std;

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show_in_order();
}

BTree::~BTree(){
    destroy(this->root);
}

void BTree::show_in_order(){
    cout << "[ ";
    show_in_order(root);
    cout << "]\n";
}

void BTree::destroy(Node * node){
    if(node == nullptr)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
    

void BTree::show_in_order(Node * node){
    if(node == nullptr)
        return;
    show_in_order(node->left);
    cout << node->value << " ";
    show_in_order(node->right);
}
```
<!---END--->



## Testes

```
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