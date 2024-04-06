#include "fracao.hpp"

// ++
int Frac::mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
    // $$
    // (void) a;
    // (void) b;
    // return 0;
}

void Frac::reduce() {
    int _mdc = mdc(num, den);
    if (den < 0) {
        num = -num;
        den = -den;
    }
    if (_mdc < 0) {
        _mdc = -_mdc;
    }
    num = num/_mdc;
    den = den/_mdc;
}

bool Frac::operator<(const Frac& other) const {
    return (double)this->num / this->den < (double) other.num / other.den;
    // $$
    // (void) other;
    // return false;
}

bool Frac::operator==(const Frac& other) const {
    return this->num == other.num && this->den == other.den;
    // $$
    // (void) other;
    // return false;
}

Frac Frac::operator+(const Frac& other) const {
    int den = this->den * other.den;
    int num = (this->num * other.den) + (other.num * this->den);
    return Frac(num, den);
    // $$
    // (void) other;
    // return Frac();
}

// função que ordena uma fração
// você pode usar a função std::sort
// ou implementar um algoritmo de ordenação
void ordena_frac(std::vector<Frac>& vet) {
    std::sort(vet.begin(), vet.end(), [](auto a, auto b) {
        return a < b;
    });
    // $$
    // (void) vet;
}


