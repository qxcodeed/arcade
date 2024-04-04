#include <iostream>
#include <vector>
#include <cmath>

#include "point.hpp"
// ++
Ponto::Ponto(int x, int y) {  
    this->x = x;
    this->y = y;
    // $$
    // (void) x;
    // (void) y;
}

double Ponto::dist(const Ponto& p) const {
    double dx = std::abs(p.x - this->x);
    double dy = std::abs(p.y - this->y);
    double value = sqrt((dx*dx + dy*dy));
    return value;
    // $$
    // (void) p;
    // return 0.0;
}

double reta(const Ponto& p, const Ponto& q) {
    double m;
    m = (q.Y() - p.Y()) / (q.X() - p.X());
    return m;
    // $$
    // (void) p;
    // (void) q;
    // return 0.0;
}


int min_dist(const Ponto& p, std::vector<Ponto> vet) {
    int best_i = 0;
    for (size_t i = 1; i < vet.size(); i++) {
        if (p.dist(vet[i]) < p.dist(vet[best_i])) {
            best_i = i;
        }
    }
   return best_i;
    // $$
    // (void) p;
    // (void) vet;
    // return 0;
}
