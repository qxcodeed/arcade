#pragma once

#include <iostream>

namespace alu {
    //imprime recursivamente os elementos de um vetor
    void __show(int * init, int * end);
    void show(int * init, int * end);

    //imprime recursivamente os elementos de um vetor de trás pra frente
    void __show_rev(int * init, int * end);

    void show_rev(int * init, int * end);

    void reverse(int * init, int * end);

    int sum(int * init, int * end);

    int mult(int * init, int * end);

    int menor(int * init, int * end);
    
} // namespace alu