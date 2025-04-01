// Arquivo de execucao
#include <iostream>
#include "lib.cpp"
const int MAXSIZE = 16;

int main(){
    SequentialSortedListInt list(MAXSIZE);

    /* Testar insert */
    list.print(); // []
    list.insert(10);
    list.print(); // [10]
    list.insert(15);
    list.print(); // [10,15]
    list.insert(5);
    list.print(); // [5,10,15]
    list.insert(0);
    list.print(); // [0,5,10,15]
    list.insert(25);
    list.print(); // [0,5,10,15,25]
    list.insert(20);
    list.print(); // [0,5,10,15,20,25]

    /* Testar get */
    std::cout << list.get(0) << std::endl; // 0
    std::cout << list.get(5) << std::endl; // 25

    /* Testar clear */
    list.clear();
    list.print(); // []
    std::cout << list.countUnique() << std::endl; // 0

    /* Testar countUnique */
    list.insert(1);
    list.print();
    std::cout << list.countUnique() << std::endl; // 1
    list.insert(2);
    list.print();
    std::cout << list.countUnique() << std::endl; // 2
    list.insert(3);
    list.print();
    std::cout << list.countUnique() << std::endl; // 3
    
    list.insert(1);
    list.insert(1);
    list.insert(1);
    list.print();
    std::cout << list.countUnique() << std::endl; // 3

    list.insert(4);
    list.print();
    std::cout << list.countUnique() << std::endl; // 4

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.print();
    std::cout << list.countUnique() << std::endl; // 5

    /* Destrutor chamado */
    // SequentialListInt deleted
}
