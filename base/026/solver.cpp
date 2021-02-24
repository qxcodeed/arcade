//tk main.cpp
#include "lib.hpp"
#include <iostream>
using namespace std;

Node * _push_back(Node * node, int value){
    if(node == nullptr)
        return new Node(value);
    node->next = _push_back(node->next, value);
    return node;
}

void LinkedList::push_back(int value){
    this->head = _push_back(this->head, value);
}

void LinkedList::push_front(int value){
    if(this->head == nullptr)
        this->head = new Node(value);
    else
        this->head = new Node(value, this->head);
}

Node * _pop_back(Node * node){
    if(node == nullptr)
        return nullptr;
    if(node->next == nullptr){
        delete node;
        return nullptr;
    }
    node->next = _pop_back(node->next);
    return node;
}

void LinkedList::pop_back(){
    this->head = (this->head);
}
void LinkedList::pop_front(){
    if(head == nullptr)
        return;
    Node * node = head;
    head = head->next;
    delete node;
}
int  LinkedList::size(){
    Node * node = head;
    int cont = 0;
    while(node != nullptr){
        cont += 1;
        node = node->next;
    }
    return cont;
}