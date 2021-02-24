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