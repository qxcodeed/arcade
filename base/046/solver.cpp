
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

    void clone(stringstream& ss, Node ** elo){
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

    BTree(string serial){
        stringstream ss(serial);
        clone(ss, &root);
    }

    void _destroy(Node * node){
        if(node == nullptr)
            return;
        _destroy(node->left);
        _destroy(node->right);
        delete node;
    }

    ~BTree(){
        _destroy(this->root);
    }

    int getMin(Node * node){
        if(node == nullptr)
            return 0;
        int v = node->value;
        if(node->left != nullptr)
            v = std::min(getMin(node->left), v);
        if(node->right != nullptr)
            v = std::min(getMin(node->right), v);
        return v;
    }

    int getMin(){
        return getMin(root);
    }

    int getSum(Node * node){
        if(node == nullptr)
            return 0;
        return node->value + getSum(node->left) + getSum(node->right);
    }

    int getSum(){
        return getSum(root);
    }
};

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    getline(cin, line);
    cout << bt.getSum() << " " << bt.getMin() << "\n";
}