#include <iostream>
#include <vector>
#include <sstream>


void processa(std::vector<int> vet){
    (void) vet;
    // 1. defina o ponto de parada
    // 2. monte o vetor auxiliar com os resultados das somas
    // 3. chame recursivamente a função processa para o vetor auxiliar
    // 4. imprima o vetor original
}


int main(){
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> vet;
    int value {};
    while(ss >> value) {
        vet.push_back(value);
    }
    processa(vet);
}
