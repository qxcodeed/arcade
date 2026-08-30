
#include <iostream>
#include <sstream>
#include <stack>
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

// Imprime o nó atual com o espaçamento baseado na profundidade
int rec_sum(Node * node) {
    if (node == nullptr) {
        return 0;
    }
    return node->value + rec_sum(node->left) + rec_sum(node->right);
}

int rec_min(Node * node) {
    if (node->left == nullptr && node->right == nullptr) {
        return node->value;
    }
    auto value = node->value;
    if (node->left != nullptr) {
        value = min(value, rec_min(node->left));
    }
    if (node->right != nullptr) {
        value = min(value, rec_min(node->right));
    }
    return value;
}
// ---------------------------------------------------------
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

Node* clone(stringstream& ss) {
    string value;
    ss >> value;
    if(value == "#")
        return nullptr;
    int num;
    stringstream(value) >> num;
    Node* node = new Node(num);
    node->left = clone(ss);
    node->right = clone(ss);
    return node;
}


int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    Node* root = clone(ss);
    cout << "Arvore:\n";
    bshow(root);
    cout << "Soma: " << rec_sum(root) << ", Minimo: " << rec_min(root) << endl;
    return 0;
}