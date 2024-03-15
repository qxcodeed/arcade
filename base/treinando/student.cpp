#include "lib.hpp"
namespace alu {

    //imprime recursivamente os elementos de um vetor
    void __show(int * init, int * end) {
        (void) init;
        (void) end;
    }

    void show(int * init, int * end) {
        std::cout << "[ ";
        __show(init, end);
        std::cout << "]";
    }

    //imprime recursivamente os elementos de um vetor de trás pra frente
    void __show_rev(int * init, int * end) {
        //todo: implement
        (void) init;
        (void) end;
    }

    void show_rev(int * init, int * end) {
        std::cout << "[ ";
        __show_rev(init, end);
        std::cout << "]";
    }

    void reverse(int * init, int * end) {
        //todo: implement
        (void) init;
        (void) end;
    }

    int sum(int * init, int * end) {
        //todo: implement
        (void) init;
        (void) end;
        return 0;
    };

    int mult(int * init, int * end) {
        //todo: implement
        (void) init;
        (void) end;
        return 0;
    };

    int menor(int * init, int * end) {
        //todo: implement
        (void) init;
        (void) end;
        return 0;
    };

} // namespace alu