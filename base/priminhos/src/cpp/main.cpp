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

// M: vetor de inteiros
// n: tamanho do vetor
// ++
void load_prime_list(int M[], int n) {
    if (n == 0) {
        return;
    }
    M[n-1] = n_esimo(n);
    load_prime_list(M, n-1);
    // $$
    // (void) M;
    // (void) n;
}

// ==
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