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

template <typename K, typename V>
void printMap(const std::map<K, V>& m) {
    for (const auto& pair : m) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}

/////////////// TESTE CONSTRUCT ///////////////

void test_constructor() {
    cout << "TESTE Construtor" << endl;
    Stack* stack = new Stack(8); 

    if(stack->size == 0 && stack->capacity == 8) {
        cout << "Ok" << endl;
    } else {
        cout << "Atributos incorretos";
    }
}


void push_test(Stack &stack, int info) {
    if(!stack.full()) {
        stack.Arr[stack.size] = info;
        stack.size++;
    }
}

int peek_test(Stack &stack) {
    if(!stack.empty()) {
        return stack.Arr[stack.size-1];
    } else {
        return -1;
    }
}

/////////////// TESTE HAS_INFO ///////////////

void test_peek() {
    cout << "TESTE peek" << endl;
    Stack stack(8);
    
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
    cout << "capacidade == 4" << endl;
    Stack stack(4);

    stack.push(10);
    cout << "push " << 10 << endl;

    stack.push(15);
    cout << "push " << 15 << endl;

    stack.push(20);
    cout << "push " << 20 << endl;

    stack.push(25);
    cout << "push " << 25 << endl;

    stack.push(55);
    cout << "push " << 55 << endl;

    cout << "Esperado: [10, 15, 20, 25]" << endl;
    cout << "Pilha: "; stack.print();
}

/////////////// TESTE POP ///////////////

void test_pop() {
    cout << "TESTE pop" << endl;
    Stack stack(8);

    push_test(stack, 10);
    push_test(stack, 15);
    push_test(stack, 20);
    push_test(stack, 25);
    push_test(stack, 30);

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
}

/////////////// TESTE CLEAR ///////////////

void test_clear() {
    cout << "TESTE clear" << endl;
    Stack stack(16);

    push_test(stack, 10);
    push_test(stack, 15);
    push_test(stack, 20);
    push_test(stack, 25);
    push_test(stack, 30);

    cout << "Pilha: "; stack.print();
    cout << "clear" << endl;
    cout << "Pilha: "; stack.print();
}


/////////////// TESTE COMPLETO ///////////////

void test_all() {
    cout << "TESTE todos (push, pop, peek, size)" << endl;
    Stack stack(1024);

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
