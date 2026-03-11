#include <iostream>
#include <vector>
#include <sstream>
#include "point.hpp"
#include "fn.hpp"

Ponto str2point(std::string token) {
    token = token.substr(1, token.size() - 2); //remover ()
    size_t pos = token.find(',');
    std::string x_str = token.substr(0, pos);
    std::string y_str = token.substr(pos + 1);
    return Ponto(std::stod(x_str), std::stod(y_str));
}


int main() {
    Ponto origem = str2point(fn::input());
    auto  vet = fn::input() | fn::SPLIT(' ') | fn::MAP(str2point);
    auto vet_incl = vet | fn::MAP([&](Ponto p) { return reta(origem, p); });
    auto vet_dist = vet | fn::MAP([&](Ponto p) { return origem.dist(p); });
    auto min_idx  = min_dist(origem, vet);

    vet_incl | fn::JOIN(" ", "%.2f") | fn::WRITE();
    vet_dist | fn::JOIN(" ", "%.2f") | fn::WRITE();
    min_idx  | fn::WRITE();
}
