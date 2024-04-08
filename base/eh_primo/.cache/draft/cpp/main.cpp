#include <iostream>

// x: número que está sendo testado
// div: divisor que está sendo testado
bool eh_primo(int x, int div = 2) {
    (void) x;
    (void) div;
    return false;
}

int main() {
    int x {};
    std::cin >> x;
    std::cout << (eh_primo(x) ? "true" : "false") << '\n'; 
    return 0;
}