
#include <iostream>
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

// Clone uma árvore binária consumindo dados de uma stringstream.
Node* clone(stringstream& ss) {
    // TODO
    (void) ss;
    return nullptr;
}

// Não altere daqui para baixo.

void bshow(Node * node, string history = ""){
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->left , history + "l");
    for(int i = 0; i < (int) history.size() - 1; i++)
        cout << (history[i] != history[i + 1] ? "│   " : "    ");
    if(history != "")
        cout << (history.back() == 'l' ? "╭───" : "╰───");
    if(node == nullptr){
        cout << "#" << endl;
        return;
    }
    cout << node->value << endl;
    if(node->left != nullptr || node->right != nullptr) {
        bshow(node->right, history + "r");
    }
}


int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    Node* root = clone(ss);
    bshow(root);
}
