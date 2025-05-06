#include <iostream>
#include <map>
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
    if(node == NULL){
        cout << "Node(empty)" << endl;
    }else{
        cout << "Node(" << node->info << ")" << endl;
    }
}
/*
// Exemplo:
// 
//    T =   32
//         /  \
//        45  12
//       /  \
//      10  37
*/

/////////////// TESTE SEARCH ///////////////

void test_insert() {
    cout << "TESTE insert" << endl;
    BinaryTree tree;
    Node *node32 = new Node(32);

    cout << "insert 32" << endl; tree.root = node32;
    cout << "insert 45" << endl; tree.insert_left(node32, 45);
    cout << "insert 12" << endl; tree.insert_right(node32, 12);
    cout << "insert 10" << endl; tree.insert_left(node32->left, 10);
    cout << "insert 37" << endl; tree.insert_right(node32->left, 37);
    tree.print();
}


/////////////// TESTE SEARCH ///////////////
/*
// Exemplo:
// 
//    T =   40
//         /  \
//        20  70
//       /  \
//      10  30
*/

void test_search() {
    cout << "TESTE search" << endl;
    BinaryTree tree;

    tree.root = new Node(55,
        new Node(12,
            new Node(76,
                new Node(33, NULL, NULL)
            )
            ,
            new Node(4, NULL, NULL)
        )
        ,
        new Node(110,
            new Node(762,
                new Node(77, NULL, NULL),
                new Node(-20, NULL, new Node(19, NULL, NULL))
            )
            ,
            new Node(1267,
                new Node(-665, NULL, NULL),
                new Node(-221, NULL, new Node(9, NULL, NULL))
            )
        )
    );

    tree.print();
    
    cout << "search 55: "; print_node(tree.search(55));
    cout << "search 9: "; print_node(tree.search(9));
    cout << "search 77: "; print_node(tree.search(77));
    cout << "search -665: "; print_node(tree.search(-665));
    cout << "search 110: "; print_node(tree.search(110));

    cout << "search -29: "; print_node(tree.search(-29));
    cout << "search 1000: "; print_node(tree.search(1000));
    cout << "search 45: "; print_node(tree.search(44));
    cout << "search 25: "; print_node(tree.search(25));
    cout << "search 35: "; print_node(tree.search(35));
    cout << "search 65: "; print_node(tree.search(65));
}

/////////////// TESTE SIZE ///////////////

void test_size() {
    cout << "TESTE size" << endl;
    BinaryTree tree;
    Node *node32 = new Node(32);
    
    Node *node45 = new Node(45);

    cout << "insert 32" << endl; tree.root = node32;
    cout << "size " << tree.size() << endl;
    cout << "insert 45" << endl; tree.insert_left(node32, 45);
    cout << "size " << tree.size() << endl;
    cout << "insert 12" << endl; tree.insert_right(node32, 12);
    cout << "size " << tree.size() << endl;
    cout << "insert 10" << endl; tree.insert_left(node45, 10);
    cout << "size " << tree.size() << endl;
    cout << "insert 37" << endl; tree.insert_right(node45, 37);
    tree.print();
    cout << "size " << tree.size() << endl;
}

/////////////// TESTE MIN MAX ///////////////

void test_min_max() {
    cout << "TESTE min max" << endl;
    BinaryTree tree;
    Node *node32 = new Node(32);

    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 32" << endl; tree.root = node32;
    cout << "insert 45" << endl; tree.insert_left(node32, 45);
    cout << "insert 12" << endl; tree.insert_right(node32, 12);
    cout << "insert 10" << endl; tree.insert_left(node32->left, 10);
    cout << "insert 37" << endl; tree.insert_right(node32->left, 37);
    tree.print();

    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
}

/////////////// FIM TESTES ///////////////

int main() {
    std::string input;
    std::cin >> input;

    if(input == "test_insert") test_insert();
    if(input == "test_search") test_search();
    if(input == "test_size") test_size();
    if(input == "test_min_max") test_min_max();
}
