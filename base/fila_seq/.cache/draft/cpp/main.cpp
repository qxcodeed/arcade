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
    SequentialQueue* queue = new SequentialQueue(8); 

    if(queue->size == 0 && queue->capacity == 8) {
        cout << "Ok" << endl;
    } else {
        cout << "Atributos incorretos";
    }
}


void push_test(SequentialQueue &queue, int info) {
    if(queue.size < queue.capacity) {
        int back = (queue.front + queue.size) % queue.capacity;
        queue.Arr[back] = info;
        queue.size++;
    }
}

int peek_test(SequentialQueue &queue) {
    if(queue.size == 0) {
        return -1;
    } else {
        return queue.Arr[queue.front];
    }
}

/////////////// TESTE HAS_INFO ///////////////

void test_peek() {
    cout << "TESTE peek" << endl;
    SequentialQueue queue(8);
    
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
    SequentialQueue queue(4);

    queue.push(10);
    cout << "push " << 10 << endl;

    queue.push(15);
    cout << "push " << 15 << endl;

    queue.push(20);
    cout << "push " << 20 << endl;

    queue.push(25);
    cout << "push " << 25 << endl;

    cout << "Esperado: [10, 15, 20, 25]" << endl;
    cout << "Fila: "; queue.print();
}

/////////////// TESTE POP ///////////////

void test_pop() {
    cout << "TESTE pop" << endl;
    SequentialQueue queue(8);

    push_test(queue, 10);
    push_test(queue, 15);
    push_test(queue, 20);
    push_test(queue, 25);
    push_test(queue, 30);

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
}

/////////////// TESTE CLEAR ///////////////

void test_clear() {}

/////////////// TESTE SIZE ///////////////

void test_all() {
    cout << "TESTE todos (push, pop, peek, size), capacity = 6" << endl;
    SequentialQueue queue(6);
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
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
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

    cout << "clear" << endl; queue.clear();
    cout << "Fila: "; queue.print();
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
