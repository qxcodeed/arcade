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

Node::Node(int info, Node* left, Node* right){
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

void print_node(Node *node){
    if(node == NULL){
        cout << "Node(empty)" << endl;
    }else{
        cout << "Node(" << node->info << ")" << endl;
    }
}

/*
    Exemplo:
    
       T =   40
            /  \
           20  70
          /  \
         10  30
*/

/////////////// TESTE SEARCH ///////////////

void test_insert(){
    cout << "TESTE insert" << endl;
    BSTree tree;

    cout << "insert 40" << endl; tree.insert(40);
    cout << "insert 20" << endl; tree.insert(20);
    cout << "insert 10" << endl; tree.insert(10);
    cout << "insert 30" << endl; tree.insert(30);
    cout << "insert 70" << endl; tree.insert(70);
    tree.print();
}

void test_insert2(){
    cout << "TESTE insert" << endl;
    BSTree tree;

    cout << "insert 40" << endl; tree.insert(40);
    cout << "insert 45" << endl; tree.insert(45);
    cout << "insert 20" << endl; tree.insert(20);
    cout << "insert 15" << endl; tree.insert(15);
    cout << "insert 10" << endl; tree.insert(10);
    cout << "insert 30" << endl; tree.insert(30);
    cout << "insert 35" << endl; tree.insert(35);
    cout << "insert 75" << endl; tree.insert(75);
    cout << "insert 70" << endl; tree.insert(70);
    cout << "insert 80" << endl; tree.insert(80);
    cout << "insert 90" << endl; tree.insert(90);
    cout << "insert 5" << endl; tree.insert(5);
    cout << "insert 1" << endl; tree.insert(1);
    cout << "insert 7" << endl; tree.insert(7);
    cout << "insert 2" << endl; tree.insert(2);
    cout << "insert 8" << endl; tree.insert(8);
    cout << "insert 0" << endl; tree.insert(0);
    cout << "insert -10" << endl; tree.insert(-10);
    tree.print();
}

/////////////// TESTE SEARCH ///////////////

/*
    Exemplo:

       T =   40
            /  \
           20  70
          /  \
         10  30
*/

void test_search(){
    cout << "TESTE push_front" << endl;
    cout << "TESTE insert" << endl;
    BSTree tree;

    cout << "insert 40" << endl; tree.insert(40);
    cout << "insert 20" << endl; tree.insert(20);
    cout << "insert 10" << endl; tree.insert(10);
    cout << "insert 30" << endl; tree.insert(30);
    cout << "insert 70" << endl; tree.insert(70);
    tree.print();

    cout << "search 40: "; print_node(tree.search(40));
    cout << "search 20: "; print_node(tree.search(20));
    cout << "search 10: "; print_node(tree.search(10));
    cout << "search 30: "; print_node(tree.search(30));
    cout << "search 70: "; print_node(tree.search(70));

    cout << "search -20: "; print_node(tree.search(-20));
    cout << "search 1000: "; print_node(tree.search(1000));
    cout << "search 45: "; print_node(tree.search(44));
    cout << "search 25: "; print_node(tree.search(25));
    cout << "search 35: "; print_node(tree.search(35));
    cout << "search 65: "; print_node(tree.search(65));
}

/////////////// TESTE SIZE ///////////////

void test_size(){
    cout << "TESTE size" << endl;
    BSTree tree;

    cout << "size " << tree.size() << endl;
    cout << "insert 40" << endl; tree.insert(40);
    cout << "size " << tree.size() << endl;
    cout << "insert 45" << endl; tree.insert(45);
    cout << "size " << tree.size() << endl;
    cout << "insert 20" << endl; tree.insert(20);
    cout << "size " << tree.size() << endl;
    cout << "insert 10" << endl; tree.insert(10);
    cout << "size " << tree.size() << endl;
    cout << "insert 30" << endl; tree.insert(30);
    cout << "size " << tree.size() << endl;
    cout << "insert 75" << endl; tree.insert(75);
    cout << "size " << tree.size() << endl;
    cout << "insert 70" << endl; tree.insert(70);
    cout << "size " << tree.size() << endl;
    cout << "insert 90" << endl; tree.insert(90);
    cout << "size " << tree.size() << endl;
    cout << "insert 5" << endl; tree.insert(5);
    cout << "size " << tree.size() << endl;
    cout << "insert 1" << endl; tree.insert(1);
    cout << "size " << tree.size() << endl;
    cout << "insert 7" << endl; tree.insert(7);
    cout << "size " << tree.size() << endl;
    cout << "insert -10" << endl; tree.insert(-10);
    tree.print();
    cout << "size " << tree.size() << endl;
}

/////////////// TESTE MIN MAX ///////////////

void test_min_max(){
    cout << "TESTE min max" << endl;
    BSTree tree;

    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 40" << endl; tree.insert(40);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 45" << endl; tree.insert(45);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 20" << endl; tree.insert(20);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 10" << endl; tree.insert(10);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 30" << endl; tree.insert(30);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 75" << endl; tree.insert(75);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 70" << endl; tree.insert(70);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 90" << endl; tree.insert(90);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 5" << endl; tree.insert(5);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 1" << endl; tree.insert(1);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert 7" << endl; tree.insert(7);
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
    cout << "insert -10" << endl; tree.insert(-10);
    tree.print();
    cout << "min " << tree.min() << endl; cout << "max " << tree.max() << endl;
}

/////////////// FIM TESTES ///////////////

int main(){
    std::string input;
    std::cin >> input;

    if(input == "test_insert") test_insert();
    if(input == "test_insert_2") test_insert2();
    if(input == "test_size") test_size();
    if(input == "test_min_max") test_min_max();
}
