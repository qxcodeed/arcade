#include <iostream>
// ++
// x: número que está sendo testado
// div: divisor que está sendo testado
bool eh_primo(int x, int div = 2) {
    if (div > x / 2) {
        return true;
    }
    if ( x % div == 0 || x == 1) {
        return false;
    }
    return eh_primo(x, div + 1);
    // $$
    // (void) x;
    // (void) div;
    // return false;
}

// ++
// n: n-ésimo número primo
// cont: contador de quantos números primos já foram encontrados
// i: número que está sendo testado
int n_esimo(int n, int cont = 0, int i = 2) {
    if (cont == n) {
        return i - 1; //quando contador chegar no limite, eu dei um passo a mais
    }
    if ( eh_primo(i, 2) ) { //eh primo, então incrementa o contador de primos e vai pra prox interação
        return n_esimo(n, cont + 1, i + 1);
    }
    return n_esimo(n, cont, i + 1); //so vai pra prox interação
    // $$
    // (void) n;
    // (void) cont;
    // (void) i;
    // return 0;
}

// ==
int main() {
    int n {};
    std::cin >> n;
    std::cout << n_esimo(n) << '\n';
    return 0;
}
