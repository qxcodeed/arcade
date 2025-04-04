#include <iostream>
#include <vector>
#include "lib.hpp"

void processa(std::vector<int> vet){
    //DEL!
    if(vet.size() == 0) {
        return;
    }
    std::vector<int> aux;
    for(u_int i = 0; i < vet.size() - 1; i++) {
        aux.push_back(vet[i] + vet[i + 1]);
    }
    processa(aux);
    std::cout << "[";
    for(auto x : vet) {
        std::cout << " " << x;
    }
    std::cout << " ]\n";

    //ACT!
    // (void) vet;
    //ADD!
    // 1. defina o ponto de parada
    // 2. monte o vetor auxiliar com os resultados das somas
    // 3. chame recursivamente a função processa para o vetor auxiliar
    // 4. imprima o vetor original
}
