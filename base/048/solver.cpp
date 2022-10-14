#include <sstream>
#include <iostream>
#include <functional>
#include "lib.hpp"

BTree::BTree(std::string serial) {
    std::stringstream ss(serial);
    
    std::function <void (Node **)>
    clone = [&clone, &ss](auto ** elo) {
        string value;
        ss >> value;
        if(value == "#")
            return;
        int num;
        stringstream(value) >> num;
        *elo =  new Node(num);
        clone(&(**elo).left);
        clone(&(*elo)->right);
    };

    clone(&root);
}

