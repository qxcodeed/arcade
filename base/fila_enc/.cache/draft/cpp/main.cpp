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

Node::Node(int info, Node* next) {
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

void test_constructor() {
    cout << "TESTE Construtor" << endl;
    LinkedQueue* queue = new LinkedQueue(); 

    if(queue->front == nullptr && queue->size == 0){
        cout << "Ok" << endl;
    }else{
        cout << "Atributos incorretos";
    }
}


void push_test(LinkedQueue &queue, int info) {
    if(queue.front == nullptr) {
        queue.front = queue.back = new Node(info, nullptr);
    } else {
        auto nnode = new Node(info, nullptr);
        queue.back->next = nnode;
        queue.back = nnode;
    }
}

int peek_test(LinkedQueue &queue) {
    if(queue.front == nullptr) {
        return -1;
    } else {
        return queue.front->info;
    }
}

/////////////// TESTE HAS_INFO ///////////////

void test_peek() {
    cout << "TESTE peek" << endl;
    LinkedQueue queue;
    
    queue.print();

    push_test(queue, 10);
    cout << "push 10" << endl;
    cout << "peek == " << queue.peek() << endl;

    push_test(queue, 15);
    cout << "push 15" << endl;
    cout << "peek == " << queue.peek() << endl;
    
    push_test(queue, 20);
    cout << "push 20" << endl;
    cout << "peek == " << queue.peek() << endl;
}


/////////////// TESTE PUSH ///////////////

void test_push() {
    allocated_nodes_status.clear();
    cout << "TESTE push" << endl;
    LinkedQueue queue;

    queue.push(10);
    cout << "push " << 10 << endl;

    queue.push(15);
    cout << "push " << 15 << endl;

    queue.push(20);
    cout << "push " << 20 << endl;

    queue.push(25);
    cout << "push " << 25 << endl;

    cout << "Esperado: [10 -> 15 -> 20 -> 25]" << endl;
    cout << "Fila: "; queue.print();
    cout << allocated_nodes_status.size() << " Nos alocados" << endl;
}

/////////////// TESTE POP ///////////////

void test_pop() {
    cout << "TESTE pop" << endl;
    LinkedQueue queue;

    push_test(queue, 10);
    push_test(queue, 15);
    push_test(queue, 20);
    push_test(queue, 25);
    push_test(queue, 30);

    Node *node1 = queue.front;
    Node *node2 = node1->next;
    Node *node3 = node2->next;
    Node *node4 = node3->next;
    Node *node5 = node4->next;

    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();

    bool all_nodes_deleted =    allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED &&
                                allocated_nodes_status[node4] == DELETED &&
                                allocated_nodes_status[node5] == DELETED;

    if(all_nodes_deleted) {
        cout << "Todos os Nos foram devidamente deletados" << endl;
    } else {
        cout << "Existem Nos removidos da fila que nao foram liberados na memoria" << endl;
    }
}

/////////////// TESTE CLEAR ///////////////

void test_clear() {}

/////////////// TESTE SIZE ///////////////

void test_all() {
    cout << "TESTE todos (push, pop, peek, size)" << endl;
    LinkedQueue queue;
    int x = 1;
    
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();

    cout << "Lista: "; queue.print();
    cout << "size: " << queue.size << endl;
}

/////////////// FIM TESTES ///////////////

int main() {
    std::string input;
    std::cin >> input;

    if(input == "test_peek") test_peek();
    if(input == "test_push") test_push();
    if(input == "test_pop") test_pop();
    if(input == "test_all") test_all();
}
