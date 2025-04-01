// Arquivo de execucao
#include <iostream>
#include <map>
//#include "solution_lib.cpp"
#include "lib.cpp"

using std::cout;
using std::endl;

bool LOG_ALLOCATED = false;
std::map<void*, int> allocated_nodes_status = {};
std::map<int, int> mapa = {};
const int ALLOCATED = 1;
const int DELETED = 2;

// Salvar Nos alocados
Node::Node() {
    allocated_nodes_status[this] = ALLOCATED;
}

Node::Node(int info, Node* left, Node* right) {
    allocated_nodes_status[this] = ALLOCATED;
    this->info = info;
    this->left = left;
    this->right = right;
    
    this->parent = nullptr;
    this->height = -1;
    this->size = -1;
    this->level = -1;
}
Node::~Node() {
    allocated_nodes_status[this] = DELETED;
}

template <typename K, typename V>
void printMap(const std::map<K, V>& m) {
    for (const auto& pair : m) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}

/////////////// TESTES AUXILIARES /////////////

void print_node(Node *node) {
    if(node == nullptr) {
        cout << "Node(empty)" << endl;
    } else {
        int parent_info = -1;
        if(node->parent != nullptr) {
            parent_info = node->parent->info;
        }
        cout << "Node(" << node->info << ", "
                        << parent_info << ", "
                        << node->size << ", "
                        << node->level << ", "
                        << node->height << ")"
                        << endl;
    }
}

void print_tree(Node *current) {
    if(current != nullptr) {
        print_node(current);
        print_tree(current->left);
        print_tree(current->right);
    }
}

/*
 Exemplo:
 
    T =   32
         /  \
        45  12
       /  \
      10  37
*/

/////////////// TESTE FILL ///////////////

void test_fill() {
    cout << "TESTE fill" << endl;
    BinaryTree tree;
    Node *node32 = new Node(32);
    Node *node45 = new Node(45);
    Node *node10 = new Node(10);
    Node *node37 = new Node(37);
    Node *node12 = new Node(12);

    cout << "insert 32" << endl; tree.root = node32;
    cout << "insert 45" << endl; node32->left = node45;
    cout << "insert 37" << endl; node45->right = node37;
    cout << "insert 10" << endl; node45->left = node10;
    cout << "insert 12" << endl; node32->right = node12;
    tree.print();
    
    cout << "fill" << endl; tree.fill();

    print_node(node32);
    print_node(node45);
    print_node(node10);
    print_node(node37);
    print_node(node12);
}


/////////////// TESTE FILL 2 ///////////////

void test_fill_2() {
    cout << "TESTE fill 2" << endl;
    BinaryTree tree;
    Node *root = new Node(32,
        new Node(11,
            new Node(6, NULL, NULL),
            new Node(2, NULL, NULL)
        ),
        new Node(112,
            new Node(63,
                new Node(66, NULL, NULL),
                new Node(11,
                    new Node(-45, NULL, NULL),
                    new Node(19,
                        new Node(-1000, NULL, NULL),
                        new Node(1223, NULL, NULL)
                    )
                )
            ),
            new Node(21, NULL, NULL)
        )
    );

    tree.root = root;
    tree.print();
    
    cout << "fill" << endl; tree.fill();

    print_tree(tree.root);
}


/////////////// FIM TESTES ///////////////

int main() {
    std::string input;
    std::cin >> input;

    if(input == "test_fill") test_fill();
    if(input == "test_fill_2") test_fill_2();
}
