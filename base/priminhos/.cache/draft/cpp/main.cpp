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

// M: vetor de inteiros
// n: tamanho do vetor
void load_prime_list(int M[], int n) {
    (void) M;
    (void) n;
}

int main() {
    int n {};
    std::cin >> n;
    int M[n];
    load_prime_list(M, n);

    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << (i == 0 ? "" : ", ");
        std::cout << M[i];
    }
    std::cout << "]\n";
    return 0;
}