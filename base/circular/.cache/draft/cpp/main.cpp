// Arquivo de execucao
#include <iostream>
#include "lib.cpp"
const int MAXSIZE = 16;

int main(){
    SequentialCircularList list(MAXSIZE);

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    std::cout << list.get(0) << std::endl; // 10
    std::cout << list.get(1) << std::endl; // 20
    std::cout << list.get(2) << std::endl; // 30
    std::cout << list.get(3) << std::endl; // 40

    std::cout << list.get(4) << std::endl; // 10
    std::cout << list.get(5) << std::endl; // 20
    std::cout << list.get(6) << std::endl; // 30
    std::cout << list.get(7) << std::endl; // 40

    std::cout << list.get(1195592) << std::endl; // 10
    std::cout << list.get(6061) << std::endl; // 20
    std::cout << list.get(56666) << std::endl; // 30
    std::cout << list.get(396767) << std::endl; // 40
}
