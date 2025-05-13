// Arquivo de execucao
#include <iostream>
#include <map>
#include "lib.cpp"
//#include "solution_lib.cpp"

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

Node::Node(int info, Node* next){
    allocated_nodes_status[this] = ALLOCATED;
    this->info = info;
    this->next = next;
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

/////////////// TESTE CONSTRUCT ///////////////

void test_constructor(){
    cout << "TESTE Construtor" << endl;
    SLinkedList* list = new SLinkedList(); 

    if(list->head == nullptr){
        cout << "Ok" << endl;
    }else{
        cout << "Atributos incorretos";
    }
}


/////////////// TESTE HAS_INFO ///////////////

void test_has_info(){
    cout << "TESTE has_info" << endl;
    SLinkedList list;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    list.print();
    cout << "has_info " << -1  << " == " << list.hasInfo(-1) << endl;
    cout << "has_info " << 0  << " == " << list.hasInfo(0) << endl;
    cout << "has_info " << 5  << " == " << list.hasInfo(5) << endl;
    cout << "has_info " << 10 << " == " << list.hasInfo(10) << endl;
    cout << "has_info " << 15 << " == " << list.hasInfo(15) << endl;
}

/////////////// TESTE GET ///////////////

void test_get(){
    cout << "TESTE get" << endl;
    SLinkedList list;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);
    // 30 20 15 10

    list.print();
    cout << "get " << 0 << " == " << list.get(0) << endl;
    cout << "get " << 1 << " == " << list.get(1) << endl;
    cout << "get " << 2 << " == " << list.get(2) << endl;
    cout << "get " << 3 << " == " << list.get(3) << endl;
}


/////////////// TESTE PUSH_FRONT ///////////////

void test_push_front(){
    cout << "TESTE push_front" << endl;
    SLinkedList list;

    cout << "push_front " << 10 << endl;
    cout << "push_front " << 15 << endl;
    cout << "push_front " << 20 << endl;
    cout << "push_front " << 30 << endl;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    cout << "Esperado: [30 -> 20 -> 15 -> 10]" << endl;
    list.print();
    cout << allocated_nodes_status.size() << " Nos alocados" << endl;
}

/////////////// TESTE PUSH_BACK ///////////////

void test_push_back(){
    cout << "TESTE push_back" << endl;
    SLinkedList list;

    cout << "push_back " << 10 << endl;
    cout << "push_back " << 15 << endl;
    cout << "push_back " << 20 << endl;
    cout << "push_back " << 30 << endl;

    list.push_back(10);
    list.push_back(15);
    list.push_back(20);
    list.push_back(30);

    cout << "Expected: [10 -> 15 -> 20 -> 30]" << endl;
    list.print();
}



/////////////// TESTE POP_FRONT ///////////////

void test_pop_front(){
    cout << "TESTE pop_front" << endl;
    SLinkedList list;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    Node* node0 = list.head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;

    cout << "Esperado: [30 -> 20 -> 15 -> 10]" << endl;
    list.print();
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: [20 -> 15 -> 10]" << endl;
    list.print();
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: [15 -> 10]" << endl;
    list.print();
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: [10]" << endl;
    list.print();
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: []" << endl;
    list.print();
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: []" << endl;
    list.print();

    bool all_nodes_deleted =    allocated_nodes_status[node0] == DELETED &&
                                allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED;

    if(all_nodes_deleted){
        cout << "Todos os Nos foram devidamente deletados" << endl;
    }else{
        cout << "Existem Nos removidos da lista que nao foram liberados na memoria" << endl;
    }
}


/////////////// TESTE POP_BACK ///////////////

void test_pop_back(){
    cout << "TESTE pop_back" << endl;
    SLinkedList list;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    Node* node0 = list.head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;

    cout << "Esperado: [30 -> 20 -> 15 -> 10]" << endl;
    list.print();
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: [30 -> 20 -> 15]" << endl;
    list.print();
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: [30 -> 20]" << endl;
    list.print();
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: [30]" << endl;
    list.print();
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: []" << endl;
    list.print();
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: []" << endl;
    list.print();

    bool all_nodes_deleted =    allocated_nodes_status[node0] == DELETED &&
                                allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED;

    if(all_nodes_deleted){
        cout << "Todos os Nos foram devidamente deletados" << endl;
    }else{
        cout << "Existem Nos removidos da lista que nao foram liberados na memoria" << endl;
    }
}


/////////////// TESTE CLEAR ///////////////

void test_clear(){
    cout << "TESTE clear" << endl;
    SLinkedList list;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    Node* node0 = list.head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;

    cout << "Esperado: [30 -> 20 -> 15 -> 10]" << endl;
    list.print();

    cout << "clear" << endl; list.clear();
    cout << "Esperado: []" << endl;
    list.print();

    cout << "clear" << endl; list.clear();
    cout << "Esperado: []" << endl;
    list.print();

    bool all_nodes_deleted =    allocated_nodes_status[node0] == DELETED &&
                                allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED;

    if(all_nodes_deleted){
        cout << "Todos os Nos foram devidamente deletados" << endl;
    }else{
        cout << "Existem Nos removidos da lista que nao foram liberados na memoria" << endl;
    }
}


/////////////// TESTE LENGTH ///////////////

void test_length(){
    cout << "TESTE length" << endl;
    SLinkedList list;

    list.print();
    cout << "length " << " == " << list.length() << endl;    
    list.push_front(42);

    list.print();
    cout << "length " << " == " << list.length() << endl;    
    list.push_front(42);

    list.print();
    cout << "length " << " == " << list.length() << endl;
}


/////////////// TESTE EMPTY ///////////////

void test_empty(){
    cout << "TESTE empty" << endl;
    SLinkedList list;

    list.print();
    cout << "empty " << " == " << list.empty() << endl;    
    list.push_front(42);

    list.print();
    cout << "empty " << " == " << list.empty() << endl;    
}

/////////////// TESTE DESTRUCTOR ///////////////

void test_destructor(){
    cout << "TESTE destructor" << endl;
    SLinkedList* list = new SLinkedList;

    list->push_front(10);
    list->push_front(15);
    list->push_front(20);
    list->push_front(30);

    Node* node0 = list->head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;

    bool all_nodes_deleted =    allocated_nodes_status[node0] == DELETED &&
                                allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED;

    delete list;
    if(all_nodes_deleted){
        cout << "Todos os Nos foram devidamente deletados" << endl;
    }else{
        cout << "Existem Nos nao foram liberados na memoria" << endl;
    }
}


/////////////// FIM TESTES ///////////////

int main(){
    std::string input;
    std::cin >> input;

    if(input == "test_constructor") test_constructor();
    if(input == "test_has_info") test_has_info();
    if(input == "test_get") test_get();
    if(input == "test_push_front") test_push_front();
    if(input == "test_push_back") test_push_back();
    if(input == "test_pop_front") test_pop_front();
    if(input == "test_pop_back") test_pop_back();
    if(input == "test_clear") test_clear();
    if(input == "test_length") test_length();
    if(input == "test_empty") test_empty();
    if(input == "test_destructor") test_destructor();
}
