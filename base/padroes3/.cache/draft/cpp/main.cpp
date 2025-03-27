#include <iostream>

int calculaPontos(int n, int m) {
    //DEL!
    if (m == 1) {
        return 1;
    }
        
    return calculaPontos(n, m - 1) + (m - 1) * (n - 2) + 1;
    //ACT!
    // (void) n;
    // (void) m;
    // return 0;
}

int main() {
    int m, n;
    std::cin >> n >> m;
    std::cout << calculaPontos(n, m) << std::endl;
}
