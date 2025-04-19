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
    Stack* stack = new Stack(); 

    if(stack->top == nullptr && stack->size == 0) {
        cout << "Ok" << endl;
    } else {
        cout << "Atributos incorretos";
    }
}


void push_test(Stack &stack, int info) {
    if(stack.top == nullptr) {
        stack.top = new Node(info, nullptr);
    } else {
        stack.top = new Node(info, stack.top);
    }
}

int peek_test(Stack &stack) {
    if(stack.top == nullptr) {
        return -1;
    } else {
        return stack.top->info;
    }
}

/////////////// TESTE HAS_INFO ///////////////

void test_peek() {
    cout << "TESTE peek" << endl;
    Stack stack;
    
    stack.print();

    push_test(stack, 10);
    cout << "push 10" << endl;
    cout << "peek == " << stack.peek() << endl;

    push_test(stack, 15);
    cout << "push 15" << endl;
    cout << "peek == " << stack.peek() << endl;
    
    push_test(stack, 20);
    cout << "push 20" << endl;
    cout << "peek == " << stack.peek() << endl;
}


/////////////// TESTE PUSH ///////////////

void test_push() {
    allocated_nodes_status.clear();
    cout << "TESTE push" << endl;
    Stack stack;

    stack.push(10);
    cout << "push " << 10 << endl;

    stack.push(15);
    cout << "push " << 15 << endl;

    stack.push(20);
    cout << "push " << 20 << endl;

    stack.push(25);
    cout << "push " << 25 << endl;

    cout << "Esperado: [25 -> 20 -> 15 -> 10]" << endl;
    cout << "Pilha: "; stack.print();
    cout << allocated_nodes_status.size() << " Nos alocados" << endl;
}

/////////////// TESTE POP ///////////////

void test_pop() {
    cout << "TESTE pop" << endl;
    Stack stack;

    push_test(stack, 10);
    push_test(stack, 15);
    push_test(stack, 20);
    push_test(stack, 25);
    push_test(stack, 30);

    Node *node1 = stack.top;
    Node *node2 = node1->next;
    Node *node3 = node2->next;
    Node *node4 = node3->next;
    Node *node5 = node4->next;

    cout << "Pilha: "; stack.print();

    cout << "pop" << endl; stack.pop();
    cout << "Pilha: "; stack.print();

    cout << "pop" << endl; stack.pop();
    cout << "Pilha: "; stack.print();

    cout << "pop" << endl; stack.pop();
    cout << "Pilha: "; stack.print();

    cout << "pop" << endl; stack.pop();
    cout << "Pilha: "; stack.print();

    cout << "pop" << endl; stack.pop();
    cout << "Pilha: "; stack.print();

    bool all_nodes_deleted =    allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED &&
                                allocated_nodes_status[node4] == DELETED &&
                                allocated_nodes_status[node5] == DELETED;

    if(all_nodes_deleted) {
        cout << "Todos os Nos foram devidamente deletados" << endl;
    } else {
        cout << "Existem Nos removidos da pilha que nao foram liberados na memoria" << endl;
    }
}

/////////////// TESTE CLEAR ///////////////

void test_clear() {
    cout << "TESTE clear" << endl;
    Stack stack;

    push_test(stack, 10);
    push_test(stack, 15);
    push_test(stack, 20);
    push_test(stack, 25);
    push_test(stack, 30);

    Node *node1 = stack.top;
    Node *node2 = node1->next;
    Node *node3 = node2->next;
    Node *node4 = node3->next;
    Node *node5 = node4->next;

    cout << "Pilha: "; stack.print();
    cout << "clear" << endl;
    cout << "Pilha: "; stack.print();

    bool all_nodes_deleted =    allocated_nodes_status[node1] == DELETED &&
                                allocated_nodes_status[node2] == DELETED &&
                                allocated_nodes_status[node3] == DELETED &&
                                allocated_nodes_status[node4] == DELETED &&
                                allocated_nodes_status[node5] == DELETED;

    if(all_nodes_deleted) {
        cout << "Todos os Nos foram devidamente deletados" << endl;
    } else {
        cout << "Existem Nos removidos da pilha que nao foram liberados na memoria" << endl;
    }
}


/////////////// TESTE SIZE ///////////////

void test_all() {
    cout << "TESTE todos (push, pop, peek, size)" << endl;
    Stack stack;

    for(int i = 0; i < 1000; i++) {
        stack.push(i);
        if(i%100 == 0) {
            cout << "push " << i << " to " << i + 99 << endl;
        }
        if(i%100 == 99) {
            cout << "peek == " << stack.peek() << endl;
            cout << "size == " << stack.size << endl << endl;
        }
    }

    for(int i = 0; i < 1000; i++) {
        stack.pop();
        if(i%100 == 99) {
            cout << "pop 100 times" << endl;
            if(stack.size > 0) {
                cout << "peek == " << stack.peek() << endl;
                cout << "size == " << stack.size << endl << endl;
            }
        }
    }

    cout << "Lista: "; stack.print();
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
