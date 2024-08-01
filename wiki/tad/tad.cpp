#include <iostream>

class Foo {

    int x;


public:

    Foo(int value = 0) {
        x = value;
    }

    // esse método é chamado quando posso alterar o objeto
    int& getX() { 
        std::cout << "obtendo por referencia\n";
        return x;
    }

    // esse método é chamado quando não posso alterar o objeto
    int getX() const {
        std::cout << "obtendo por valor\n";
        return x;
    }
};

int main() {
    Foo f(5);
    f.getX() = 10; // chama o método int& getX()
    std::cout << f.getX() << '\n'; // 10

    const Foo f2(5);
    // f2.getX() = 10; // erro de compilação
    std::cout << f2.getX() << '\n'; // 5
}
