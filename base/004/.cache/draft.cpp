#include <iostream>
#include <vector>

void process(int value) {
    if (/* ponto de parada */) {
        return;
    }
    //faz os calculos de div e resto
    process(div);
    //imprime depois da chama recursiva
}

int main() {
    int value {};
    std::cin >> value;
    process(value);
}