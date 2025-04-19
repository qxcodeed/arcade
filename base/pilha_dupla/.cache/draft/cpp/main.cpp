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
    DoubleStack* stack = new DoubleStack(8); 

    if(stack->sizeA == 0 && stack->sizeB == 0 && stack->capacity == 8) {
        cout << "Ok" << endl;
    } else {
        cout << "Atributos incorretos";
    }
}

/////////////// TESTE PUSH ///////////////

void test_push() {
    cout << "TESTE push (capacity 6)" << endl;
    DoubleStack stack(6);
    
    stack.print();

    cout << "pushA 10" << endl; stack.pushA(10);
    stack.print();

    cout << "pushA 20" << endl; stack.pushA(20);
    stack.print();

    cout << "pushA 30" << endl; stack.pushA(30);
    stack.print();

    cout << "pushA 40" << endl; stack.pushA(40);
    stack.print();

    cout << "pushB 50" << endl; stack.pushB(50);
    stack.print();

    cout << "pushB 60" << endl; stack.pushB(60);
    stack.print();

    cout << "pushA 70" << endl; stack.pushA(70);
    stack.print();

    cout << "pushB 80" << endl; stack.pushB(80);
    stack.print();
}


/////////////// TESTE PEEK ///////////////

void test_peek() {
    allocated_nodes_status.clear();
    cout << "TESTE peek" << endl;
    cout << "capacidade == 4" << endl;
    DoubleStack stack(4);

    cout << "pushA 10" << endl; stack.pushA(10);
    cout << "peekA == " << stack.peekA() << endl;

    cout << "pushA 20" << endl; stack.pushA(10);
    cout << "peekA == " << stack.peekA() << endl;

    cout << "pushB 30" << endl; stack.pushB(30);
    cout << "peekB == " << stack.peekB() << endl;

    cout << "pushB 40" << endl; stack.pushB(40);
    cout << "peekB == " << stack.peekB() << endl;
}

/////////////// TESTE POP ///////////////

void test_pop() {
    cout << "TESTE pop (capacity 6)" << endl;
    DoubleStack stack(6);
    
    stack.print();

    cout << "pushA 10" << endl; stack.pushA(10);
    cout << "pushA 20" << endl; stack.pushA(20);
    cout << "pushA 30" << endl; stack.pushA(30);
    cout << "pushA 40" << endl; stack.pushA(40);
    stack.print();

    cout << "pushB 50" << endl; stack.pushB(50);
    cout << "pushB 60" << endl; stack.pushB(60);
    stack.print();

    cout << "popA" << endl; stack.popA();
    stack.print();

    cout << "pushB 70" << endl; stack.pushB(70);
    stack.print();

    cout << "pushB 80" << endl; stack.pushB(80);
    stack.print();


    cout << "popA" << endl; stack.popA();
    stack.print();

    cout << "popA" << endl; stack.popA();
    stack.print();
    
    cout << "popA" << endl; stack.popA();
    stack.print();
    
    cout << "popA" << endl; stack.popA();
    stack.print();

    cout << "popB" << endl; stack.popB();
    stack.print();
    
    cout << "popB" << endl; stack.popB();
    stack.print();
    
    cout << "popB" << endl; stack.popB();
    stack.print();
    
    cout << "popB" << endl; stack.popB();
    stack.print();

    cout << "pushA 90" << endl; stack.pushA(90);
    stack.print();

    cout << "pushB 100" << endl; stack.pushB(100);
    stack.print();

    cout << "popA" << endl; stack.popA();
    stack.print();

    cout << "popB" << endl; stack.popB();
    stack.print();
}

/////////////// TESTE CLEAR ///////////////

void test_clear() {
    cout << "TESTE clear capacity(4)" << endl;
    DoubleStack stack(4);

    cout << "pushA 10" << endl; stack.pushA(10);
    cout << "pushA 20" << endl; stack.pushA(20);
    cout << "pushB 30" << endl; stack.pushB(30);
    cout << "pushB 40" << endl; stack.pushB(40);
    stack.print();

    cout << "clearA" << endl; stack.clearA();
    stack.print();

    cout << "clearB" << endl; stack.clearB();
    stack.print();
}


/////////////// FIM TESTES ///////////////

int main() {
    std::string input;
    std::cin >> input;

    if(input == "test_peek") test_peek();
    if(input == "test_push") test_push();
    if(input == "test_pop") test_pop();
    if(input == "test_clear") test_clear();
}
