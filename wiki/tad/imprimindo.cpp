#include <iostream>
#include <sstream>

class Foo {
    int value = 10;
    float f = 3.14;

public:
    // sugestão de criar um método str() para converter o objeto em string
    std::string str() const {
        std::ostringstream ss; //crie a saida dos seus dados
        ss << "value: " << value << ", f: " << f;
        return ss.str();
    }
};

// ensine o ostream a imprimir Foo
std::ostream& operator<<(std::ostream& os, const Foo& foo) {
    return os << foo.str();
}

int main() {
    Foo f;
    std::cout << f.str() << '\n'; // convertendo manualmente
    std::cout << f << '\n'; // usando o operador <<
}
