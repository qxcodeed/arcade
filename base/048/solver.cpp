
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
