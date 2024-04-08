//lib.hpp
#pragma once
#include <iostream>

namespace alu {
    // init: aponta para o primeiro elemento do vetor
    // end: aponta para uma posição depois do último elemento do vetor
    // converte o vetor para texto no formato [1, 2, 3, 4]
    std::string tostr(int * init, int * end);

    // converte o vetor para texto, porém ao contrário
    std::string torev(int * init, int * end);

    // inverte os elementos do vetor inplace
    void reverse(int * init, int * end);

    // soma os elementos do vetor
    int sum(int * init, int * end);

    // multiplica os elementos do vetor
    // retorne 1, se o vetor estiver vazio
    int mult(int * init, int * end);

    // DESAFIO
    // retorne a posição do menor elemento do vetor
    int min(int * init, int * end);

} // namespace alu