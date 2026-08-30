#include <iostream>

int calculaPontos(int n, int m) {
    // @DROP
    if (m == 1) {
        return 1;
    }
        
    return calculaPontos(n, m - 1) + (m - 1) * (n - 2) + 1;
    // @UNC
    // (void) n;
    // (void) m;
    // return 0;
}

int main() {
    int m, n;
    std::cin >> n >> m;
    std::cout << calculaPontos(n, m) << std::endl;
}
