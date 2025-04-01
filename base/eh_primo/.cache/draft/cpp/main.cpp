#include <iostream>

// x: número que está sendo testado
// div: divisor que está sendo testado
bool eh_primo(int x, int div = 2) {
    //DEL!
    if (div > x / 2) {
        return true;
    }
    if ( x % div == 0 || x == 1) {
        return false;
    }
    return eh_primo(x, div + 1);
    //ACT!
    // (void) x;
    // (void) div;
    // return false;
}

int main() {
    int x {};
    std::cin >> x;
    std::cout << (eh_primo(x) ? "true" : "false") << '\n'; 
    return 0;
}
