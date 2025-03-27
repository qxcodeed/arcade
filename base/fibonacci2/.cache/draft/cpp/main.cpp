#include <iostream>

int f (int n) {
    //DEL!
    if (n <= 0) {
        return 0;
    } else if (n == 1 || n == 2) {
        return 1;
    } else if (n == 3) {
        return 2;
    } else {
        return f(n - 2) + f(n - 3);
    }
    //ACT!
    // (void) n;
    // return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << f(n) << std::endl;
}
