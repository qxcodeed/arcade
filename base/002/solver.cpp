
#include <iostream>
#include <vector>
#include <sstream>
#include "lib.hpp"

void processa(std::vector<int> vet){
    if(vet.size() == 0)
        return;
    std::vector<int> aux;
    for(size_t i = 0; i < vet.size() - 1; i++)
        aux.push_back(vet[i] + vet[i + 1]);
    processa(aux);
    std::cout << "[";
    for(auto x : vet)
        std::cout << " " << x;
    std::cout << " ]\n";
}