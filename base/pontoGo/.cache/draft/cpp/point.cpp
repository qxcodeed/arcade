#include <iostream>
#include <vector>
#include <cmath>

#include "point.hpp"

Ponto::Ponto(int x, int y) {  
    //DEL!
    this->x = x;
    this->y = y;
    //ACT!
    // (void) x;
    // (void) y;
}

double Ponto::dist(const Ponto& p) const {
    //DEL!
    double dx = std::abs(p.x - this->x);
    double dy = std::abs(p.y - this->y);
    double value = sqrt((dx*dx + dy*dy));
    return value;
    //ACT!
    // (void) p;
    // return 0.0;
}

double reta(const Ponto& p, const Ponto& q) {
    //DEL!
    double m;
    m = (q.Y() - p.Y()) / (q.X() - p.X());
    return m;
    //ACT!
    // (void) p;
    // (void) q;
    // return 0.0;
}


int min_dist(const Ponto& p, std::vector<Ponto> vet) {
    //DEL!
    int best_i = 0;
    for (u_int i = 1; i < vet.size(); i++) {
        if (p.dist(vet[i]) < p.dist(vet[best_i])) {
            best_i = i;
        }
    }
   return best_i;
    //ACT!
    // (void) p;
    // (void) vet;
    // return 0;
}
