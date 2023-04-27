#include <iostream>
#include <vector>
#include <sstream>
#include "lib.hpp"

int main() {

    //lendo vetor
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> valores;
    int value { };
    while (ss >> value)
        valores.push_back(value);

    //pegando ponteiros para o vetor
    int * init = valores.data();
    int * end = init + valores.size();

    std::cout << "vet : ";
    alu::show(init, end);
    std::cout << "\n";

    std::cout << "rvet: ";
    alu::show_rev(init, end);
    std::cout << "\n";

    std::cout << "sum : " << alu::sum(init, end) << "\n";
    std::cout << "mult: " << alu::mult(init, end) << "\n";
    std::cout << "min : " << alu::menor(init, end) << "\n";
    alu::reverse(init, end);

    std::cout << "inv : ";
    alu::show(init, end);
    std::cout << "\n";

}

