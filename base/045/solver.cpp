
#include <iostream>
#include <cstdlib>
#include <sstream>
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

struct BTree{
    Node * root;
    BTree(){
        this->root = nullptr;
    }
    void clone(stringstream& ss, Node ** elo);


    BTree(string serial){
        stringstream ss(serial);
        clone(ss, &root);
    }

    void __destroy(Node * node){
        if(node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    ~BTree(){
        __destroy(this->root);
    }

    Node * find(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value)
            return node;
        auto left = find(node->left, value);
        if(left != nullptr)
            return left;
        return find(node->right, value);
    }

    Node * find(int value){
        return find(this->root, value);
    }

    int getAltura(Node * node){
        if(node == nullptr)
            return 0;
        int max = std::max(getAltura(node->left), getAltura(node->right));
        return max + 1;
    }

    int getHeight(){
        return getAltura(root);
    }

    int getNivel(Node * node, int nivel, int value){
        if(node == nullptr)
            return 0;
        if(node->value == value)
            return nivel;
        auto left = getNivel(node->left, nivel + 1, value);
        if(left != 0)
            return left;
        return getNivel(node->right, nivel + 1, value);
    }

    int getProfundidade(int value){
        return getNivel(this->root, 1, value);
    }
    
};

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    getline(cin, line);
    stringstream ss(line);
    int value;
        while(ss >> value){ //enquanto houver elementos no buffer
        Node * node = bt.find(value);
        if(node != nullptr)
            cout << bt.getAltura(node) << " " << bt.getProfundidade(value) << "\n";
        else
            cout << "-1\n";
    }
}

void BTree::clone(stringstream& ss, Node ** elo){
    string value;
    ss >> value;
    if(value == "#")
        return;
    int num;
    stringstream(value) >> num;
    *elo =  new Node(num);
    clone(ss, &(*elo)->left);
    clone(ss, &(*elo)->right);
}
