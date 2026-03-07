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
Node::Node(int info, Node* next, Node* previous){
    allocated_nodes_status[this] = ALLOCATED;
    this->info = info;
    this->next = next;
    this->previous = previous;
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
    DLinkedList* list = new DLinkedList(); 

    if(list->head == NULL){
        cout << "Ok" << endl;
    }else{
        cout << "Atributos incorretos";
    }
}


/////////////// TESTE HAS_INFO ///////////////

void test_has_info(){
    cout << "TESTE has_info" << endl;
    DLinkedList list;

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

/////////////// TESTE PUSH_FRONT ///////////////

void test_push_front(){
    cout << "TESTE push_front" << endl;
    DLinkedList list;

    cout << "push_front " << 10 << endl;
    cout << "push_front " << 15 << endl;
    cout << "push_front " << 20 << endl;
    cout << "push_front " << 30 << endl;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    cout << "Esperado: [30 <-> 20 <-> 15 <-> 10]" << endl;
    list.print();
    cout << allocated_nodes_status.size() << " Nos alocados" << endl;
}

/////////////// TESTE PUSH_BACK ///////////////

bool test_previous_and_tail(DLinkedList &list){
    if(list.head == NULL) return true;

    if(list.head->previous != NULL){
        cout << "O valor previous do primeiro No deve ser NULL." << endl;
        return false;
    }
    Node *temp;
    for(temp = list.head; temp->next != NULL; temp = temp->next){
        if(temp->next->previous != temp){
            cout << "Valor atribuido ao previous incorreto." << endl;
            return false;
        }
    }
    if(temp != list.tail){
        cout << "O valor atribuido a 'tail' esta incorreto." << endl;
    }
    return true;
}

void test_push_back(){
    cout << "TESTE push_back" << endl;
    DLinkedList list;

    cout << "push_back " << 10 << endl;
    cout << "push_back " << 15 << endl;
    cout << "push_back " << 20 << endl;
    cout << "push_back " << 30 << endl;

    list.push_back(10);
    list.push_back(15);
    list.push_back(20);
    list.push_back(30);

    list.print();
    if(!test_previous_and_tail(list)) return;
}

/////////////// TESTE POP_FRONT ///////////////

void test_pop_front(){
    cout << "TESTE pop_front" << endl;
    DLinkedList list;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    Node* node0 = list.head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;

    cout << "Esperado: [30 <-> 20 <-> 15 <-> 10]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: [20 <-> 15 <-> 10]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: [15 <-> 10]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: [10]" << endl;
    if(!test_previous_and_tail(list)) return;
    list.print();
    cout << "pop_front" << endl; list.pop_front();
    cout << "Esperado: []" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
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
    DLinkedList list;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    Node* node0 = list.head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;

    cout << "Esperado: [30 <-> 20 <-> 15 <-> 10]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: [30 <-> 20 <-> 15]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: [30 <-> 20]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: [30]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: []" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;
    cout << "pop_back" << endl; list.pop_back();
    cout << "Esperado: []" << endl;
    if(!test_previous_and_tail(list)) return;
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


/////////////// TESTE REMOVE_ONE ///////////////

void test_remove_one(){
    cout << "TESTE remove_one" << endl;
    DLinkedList list;

    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    // 10, 20, 30, 10, 20, 30 //
    Node* node0 = list.head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;
    Node* node4 = node3->next;
    Node* node5 = node4->next;

    cout << "Esperado: [10 <-> 20 <-> 30 <-> 10 <-> 20 <-> 30]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;

    cout << "remove_one 30" << endl; list.remove_one(30);
    cout << "Esperado: [10 <-> 20 <-> 10 <-> 20 <-> 30]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;

    cout << "remove_one 30" << endl; list.remove_one(30);
    cout << "Esperado: [10 <-> 20 <-> 10 <-> 20]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;

    cout << "remove_one 30" << endl; list.remove_one(30);
    cout << "Esperado: [10 <-> 20 <-> 10 <-> 20]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;

    cout << "remove_one 20" << endl; list.remove_one(20);
    cout << "Esperado: [10 <-> 10 <-> 20]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;

    cout << "remove_one 20" << endl; list.remove_one(20);
    cout << "Esperado: [10 <-> 10]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;

    cout << "remove_one 10" << endl; list.remove_one(10);
    cout << "Esperado: [10]" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;

    cout << "remove_one 10" << endl; list.remove_one(10);
    cout << "Esperado: []" << endl;
    list.print();
    if(!test_previous_and_tail(list)) return;

    bool all_nodes_deleted =    allocated_nodes_status[node0] == DELETED &&
                                allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED &&
                                allocated_nodes_status[node4] == DELETED &&
                                allocated_nodes_status[node5] == DELETED;

    if(all_nodes_deleted){
        cout << "Todos os Nos foram devidamente deletados" << endl;
    }else{
        cout << "Existem Nos removidos da lista que nao foram liberados na memoria" << endl;
    }
}


/////////////// TESTE CLEAR ///////////////

void test_clear(){
    cout << "TESTE clear" << endl;
    DLinkedList list;

    list.push_front(10);
    list.push_front(15);
    list.push_front(20);
    list.push_front(30);

    Node* node0 = list.head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;

    cout << "Esperado: [30 <-> 20 <-> 15 <-> 10]" << endl;
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
    DLinkedList list;

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
    DLinkedList list;

    list.print();
    cout << "empty " << " == " << list.empty() << endl;    
    list.push_front(42);

    list.print();
    cout << "empty " << " == " << list.empty() << endl;    
}

/////////////// TESTE DESTRUCTOR ///////////////

void test_destructor(){
    cout << "TESTE destructor" << endl;
    DLinkedList* list = new DLinkedList;

    list->push_front(10);
    list->push_front(15);
    list->push_front(20);
    list->push_front(30);

    Node* node0 = list->head;
    Node* node1 = node0->next;
    Node* node2 = node1->next;
    Node* node3 = node2->next;
    list->print();
    delete list;

    bool all_nodes_deleted =    allocated_nodes_status[node0] == DELETED &&
                                allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED;

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

    if(input == "test_has_info") test_has_info();
    if(input == "test_push_front") test_push_front();
    if(input == "test_push_back") test_push_back();
    if(input == "test_pop_front") test_pop_front();
    if(input == "test_pop_back") test_pop_back();
    if(input == "test_remove_one") test_remove_one();
}


