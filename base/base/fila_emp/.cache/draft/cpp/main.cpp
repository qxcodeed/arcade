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

template <typename K, typename V>
void printMap(const std::map<K, V>& m) {
    for (const auto& pair : m) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}


/////////////// TESTE ALL ///////////////

void test_all() {
    cout << "TESTE todos (push, pop, peek)" << endl;
    StackedQueue queue;
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

    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    cout << "push " << x << endl; queue.push(x); x++;
    cout << "Fila: "; queue.print();
    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();

    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
    cout << "pop" << endl; queue.pop();
    cout << "Fila: "; queue.print();
 
    cout << "clear" << endl; queue.clear();
    cout << "Lista: "; queue.print();
}

/////////////// FIM TESTES ///////////////

int main() {
    std::string input;
    std::cin >> input;

    if(input == "test_all") test_all();
}
