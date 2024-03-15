#include "lib.hpp"
#include <sstream>
#include <functional>

BTree::~BTree(){

    std::function <void (Node*)>
    destroy = [&](Node * node) {
        if(node == nullptr)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    };

    destroy(this->root);
}


std::string BTree::in_order() {
    std::stringstream os;

    std::function <void (Node*)>
    walk = [&](Node* node) {
        if(node == nullptr)
            return;
        walk(node->left);
        os << node->value << " ";
        walk(node->right);
    };

    os << "[ ";
    walk(root);
    os << "]";

    return os.str();
}


std::string BTree::format(){
    std::ostringstream os;

    std::function <void (Node*, std::string)> 
    walk = [&](Node * node, string path) {
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            walk(node->left , path + "l");
        for(int i = 0; i < (int) path.size() - 1; i++)
            os << (path[i] != path[i + 1] ? "│   " : "    ");
        if(path != "")
            os << (path.back() == 'l' ? "┌───" : "└───");
        if(node == nullptr){
            os << "#" << endl;
            return;
        }
        os << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            walk(node->right, path + "r");
    };

    walk(this->root, "");
    return os.str();
}



    


