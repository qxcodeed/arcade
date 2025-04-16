#include <iostream>

void process(int value) {
    if (value == 0) {
        return;
    }
    int div = value / 2;
    int resto = value % 2;
    process(div);
    std::cout << div << " " << resto << std::endl;
    (void) value;
    if (/* ponto de parada */) {
    ____return;
    }
    faz os calculos de div e resto
    chama a recursão para div
    imprime os valores depois da chamada recursiva
}
