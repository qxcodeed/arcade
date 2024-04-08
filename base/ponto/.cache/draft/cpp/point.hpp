#include <iostream>
#include <vector>

class Ponto {
    double x; // abcissa
    double y; // ordenada
public:
    // Construtor 
    Ponto(int x = 0, int y = 0);       // TODO
    // Calcula a distância entre dois pontos
    double dist(const Ponto& p) const; //TODO

    //-----------------------------------------

    // acesso por referência
    double& X() { return x; }
    double& Y() { return y; }
    // acesso por valor
    double X() const { return x; }
    double Y() const { return y; }
};

// Função que calcula a inclinação da reta que passa pelos pontos p e q
double reta(const Ponto& p, const Ponto& q); // TODO

// Função que calcula qual dos pontos do vetor está mais próximo do ponto p
// Retorna o índice do ponto mais próximo
int min_dist(const Ponto& p, std::vector<Ponto> vet); // TODO