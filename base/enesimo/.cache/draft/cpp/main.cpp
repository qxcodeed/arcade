#include <iostream>
// x: número que está sendo testado
// div: divisor que está sendo testado
bool eh_primo(int x, int div = 2) {
    (void) x;
    (void) div;
    return false;
}

// n: n-ésimo número primo
// cont: contador de quantos números primos já foram encontrados
// i: número que está sendo testado
int n_esimo(int n, int cont = 0, int i = 2) {
    (void) n;
    (void) cont;
    (void) i;
    return 0;
}

int main() {
    int n {};
    std::cin >> n;
    std::cout << n_esimo(n) << '\n';
    return 0;
}
