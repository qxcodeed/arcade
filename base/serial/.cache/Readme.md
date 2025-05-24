# Lendo uma árvore a partir de um serial

<!--TOC_BEGIN-->
- [Descrição](#descrição)
- [Testes](#testes)
- [Ajuda](#ajuda)
- [Código base](#código-base)
<!--TOC_END-->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/serial/cover.jpg)

## Descrição

- Leia a string que representa a árvore serializada.
- Você deve construir a árvore a partir da string implementando corretamente o construtor do código de partida.
- Você pode entender a lógica de serialização no seguinte [link](https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/).
- A saída é a árvore percorrida in-order, mas já está implementado no código de partida.

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

## Ajuda

Você pode utilizar o código a seguir como ponto de partida. O método `bshow` da árvore imprime a árvore em um formato amigável. Você pode utilizá-lo para conferir se seu código está funcionando corretamente.

Para o caso da árvore do último teste, temos essa saída.

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

Para simplificar o código, estou utilizando a convenção `__` para expressar quais são os métodos privados, própria do python.

Os locais onde você deve colocar seu código estão marcados com //TODO. Como estamos lidando com árvores, você deverá criar também os métodos recursivos para realizar a operação de construção da árvore.

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
    Node * root {nullptr};
    BTree(){
    }


    BTree(string serial){
        //TODO faça o construtor que constroi a árvore utilizando o texto
        //aprenda a utilizar o stringstream, se você ainda não sabe
    }

    ~BTree(){ //destrutor da árvore
        __destroy(this->root);
    }

    void __destroy(Node * node){
        if(node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }
    
    void bshow(){
        __bshow(this->root);
    }

    void __bshow(Node * node, string heranca = ""){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->left , heranca + "l");
        for(int i = 0; i < (int) heranca.size() - 1; i++)
            cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if(heranca != "")
            cout << (heranca.back() == 'l' ? "┌───" : "└───");
        if(node == nullptr){
            cout << "#" << endl;
            return;
        }
        cout << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->right, heranca + "r");
    }

    void show_in_order(){
        cout << "[ ";
        __show_in_order(root);
        cout << "]\n";
    }

    void __show_in_order(Node * node){
        if(node == nullptr)
            return;
        __show_in_order(node->left);
        cout << node->value << " ";
        __show_in_order(node->right);
    }

};

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show_in_order();
}
```