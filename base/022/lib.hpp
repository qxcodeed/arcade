#ifndef LIB_H
#define LIB_H

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int _value = 0, Node * _left = nullptr, Node * _right = nullptr){
        this->value = _value;
        this->left = _left;
        this->right = _right;
    }
};

string find(Node * root, int value);

#endif