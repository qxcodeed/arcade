#include <iostream>
#include "fracao.hpp"
#include "fn.hpp"

Frac str2frac(std::string str) {
    auto [num, den] = fn::unpack<int, int>(str, '/');
    return Frac(num, den);
}

int main() {
    auto vet = fn::input() | fn::SPLIT(' ') | fn::MAP(str2frac);
    vet | fn::JOIN(" ") | fn::WRITE();
    ordena_frac(vet);
    vet | fn::JOIN(" ") | fn::WRITE();
}