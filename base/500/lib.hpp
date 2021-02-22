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