# @026 L1 - build list

Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/026/Readme.md)

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/026/cover.jpg)

<!--TOC_BEGIN-->
- [Arquivos](#arquivos)
- [Header](#header)
- [Testes](#testes)
<!--TOC_END-->

Seja a uma lista ligada sem cabeça e sem rabo. Implemente as funções de:

- push_back
- push_front
- pop_back
- pop_front
- empty

## Arquivos

- [student.cpp](https://github.com/qxcodeed/arcade/blob/master/base/026/student.cpp)
- [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/026/main.cpp)
- [lib.hpp](https://github.com/qxcodeed/arcade/blob/master/base/026/lib.hpp)

## Header
<!--ADD lib.hpp cpp-->
```cpp
//lib.hpp
#pragma once
#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

struct LinkedList{
    Node * head {nullptr};

    //esses métodos aqui são pra você implementar no arquivo student.cpp
    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    int  size();

    //Os métodos abaixo já estão implementados abaixo da main
    LinkedList();
    ~LinkedList();
    friend ostream& operator<<(ostream& os, LinkedList& lista);
};
```
<!--ADD_END-->

***

## Testes

```txt
>>>>>>>>
show
push_back 1
show
size
end
========
$show
[ ]
$push_back 1
$show
[ 1 ]
$size
1
$end
<<<<<<<<

>>>>>>>>
show
push_back 1
show
push_back 2 3 5 6 7
show
end
========
$show
[ ]
$push_back 1
$show
[ 1 ]
$push_back 2 3 5 6 7
$show
[ 1 2 3 5 6 7 ]
$end
<<<<<<<<

>>>>>>>>
show
push_back 2 1
show
pop_back
show
pop_back
show
pop_back
show
end
========
$show
[ ]
$push_back 2 1
$show
[ 2 1 ]
$pop_back
$show
[ 2 1 ]
$pop_back
$show
[ 2 1 ]
$pop_back
$show
[ 2 1 ]
$end
<<<<<<<<

>>>>>>>>
show
push_front 1 2 3 4 5
show
end
========
$show
[ ]
$push_front 1 2 3 4 5
$show
[ 5 4 3 2 1 ]
$end
<<<<<<<<

>>>>>>>>
show
push_front 1 2 3 4
show
pop_front
show
pop_front
show
pop_front
show
pop_front
show
pop_front
show
pop_front
show
end
========
$show
[ ]
$push_front 1 2 3 4
$show
[ 4 3 2 1 ]
$pop_front
$show
[ 4 3 2 1 ]
$pop_front
$show
[ 4 3 2 1 ]
$pop_front
$show
[ 4 3 2 1 ]
$pop_front
$show
[ 4 3 2 1 ]
$pop_front
$show
[ 4 3 2 1 ]
$pop_front
$show
[ 4 3 2 1 ]
$end
<<<<<<<<

```
