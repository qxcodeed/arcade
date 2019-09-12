
#include <iostream>
#include <cstdlib>
#include <sstream>
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
        clone(ss, &(**elo).left);
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
    




    void show(Node * node, int nivel){
        if(node == nullptr){
            cout << string(nivel, '.') << "#\n";
            return;
        }
        cout << string(nivel, '.') << node->value << "\n";
        if(node->left == nullptr && node->right == nullptr)
            return;
        show(node->left, nivel + 1);
        show(node->right, nivel + 1);
    }

    void show(){
        show(root, 0);
    }
};




int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show();
/* 
    {
        stringstream ss;
        ss << "hoje, dia " << 13 << " estou pesando " << 85.10 << "kilos\n";
        cout << ss.str();
    }
    {
        stringstream ss("banana 1 bananeira goiaba 4 goiabeira uva 6 parreira");
        string fruta;
        int qtd;
        string fruteira;
        while(ss >> fruta >> qtd >> fruteira){
            cout << fruta << qtd << fruteira << "\n";
        }

        float valor;
        stringstream("5.42") >> valor;
    }     
 */



}