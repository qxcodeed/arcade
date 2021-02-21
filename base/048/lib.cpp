#include <sstream>
#include <iostream>
#include "lib.hpp"
using namespace std;

void clone(stringstream& ss, Node ** elo){
    string value;
    ss >> value;
    if(value == "#")
        return;
    int num;
    stringstream(value) >> num;
    *elo =  new Node(num);
    clone(ss, &(**elo).left);
    clone(ss, &(*elo)->right);
}

BTree::BTree(string serial){
    stringstream ss(serial);
    clone(ss, &root);
}

