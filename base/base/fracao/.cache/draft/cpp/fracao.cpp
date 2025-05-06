#include "fracao.hpp"

int Frac::mdc(int a, int b) {
    (void) a;
    (void) b;
    return 0;
}

void Frac::reduce() {
}

bool Frac::operator<(const Frac& other) const {
    (void) other;
    return false;
}

bool Frac::operator==(const Frac& other) const {
    (void) other;
    return false;
}

Frac Frac::operator+(const Frac& other) const {
    (void) other;
    return Frac();
}

// função que ordena uma fração
// você pode usar a função std::sort
// ou implementar um algoritmo de ordenação
void ordena_frac(std::vector<Frac>& vet) {
    (void) vet;
}
