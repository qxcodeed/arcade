#include <iostream>

int f (int n) {
    (void) n;
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << f(n) << std::endl;
}