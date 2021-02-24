# Build Linked List - push and pop

<!--TOC_BEGIN-->
- [Arquivos](#arquivos)
    - [student.cpp](#studentcpp)
    - [lib.hpp](#libhpp)
    - [main.cpp](#maincpp)
- [Testes](#testes)
<!--TOC_END-->

Seja a implementação de uma lista ligada sem cabeça e sem rabo. Implemente as funções de
- push_back
- push_front
- pop_back
- pop_front
- empty

## Arquivos

### student.cpp
<!--ADD student.cpp cpp-->
```cpp
#include "lib.hpp"
#include <iostream>
using namespace std;

void LinkedList::push_back(int value){

}
void LinkedList::push_front(int value){

}
void LinkedList::pop_back(){

}
void LinkedList::pop_front(){

}
int  LinkedList::size(){
    return 0;
}
```
<!--ADD_END-->

---
### lib.hpp
<!--ADD lib.hpp cpp-->
```cpp
#pragma once
#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr){
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


---
### main.cpp
<!--ADD main.cpp cpp-->
```cpp
#include <iostream>
#include <sstream>
#include "lib.hpp"
using namespace std;

int main(){
    LinkedList ll;
    while(true){
        string line, cmd;
        int value;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "show"){
            cout << ll << endl;
        }else if(cmd == "push_back"){
            while(ss >> value)
                ll.push_back(value);
        }else if(cmd == "push_front"){
            while(ss >> value)
                ll.push_front(value);
        }else if(cmd == "pop_back"){
            ll.pop_back();
        }else if(cmd == "pop_front"){
            ll.pop_back();
        }else if(cmd == "size"){
            cout << ll.size() << endl;
        }
    }
}

LinkedList::LinkedList(){
}

void destroy(Node * node){
    if(node == nullptr)
        return;
    else{
        destroy(node->next);
        delete(node);
    }
}

LinkedList::~LinkedList(){
    destroy(head);
}
ostream& operator<<(ostream& os, LinkedList& lista){
    os << "[ ";
    Node * node = lista.head;
    while(node != nullptr){
        os << node->value << " ";
        node = node->next;
    }
    os << "]";
    return os;
}
```
<!--ADD_END-->



## Testes
```
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