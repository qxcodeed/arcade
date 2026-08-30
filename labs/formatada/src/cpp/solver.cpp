
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

// Imprime o nó atual com o espaçamento baseado na profundidade
void my_show(Node * node, int depth = 0) {
    (void) node;
    (void) depth;
    // TODO
    // @DROP
    if (node == nullptr) {
        cout << string(depth * 4, '.') << "#" << endl;
    } else {
        if (node->left != nullptr || node->right != nullptr)
            my_show(node->left, depth + 1);
        cout << string(depth * 4, '.') << node->value << endl;
        if (node->left != nullptr || node->right != nullptr)
            my_show(node->right, depth + 1);
    }
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
    bshow(root);
    my_show(root);
}