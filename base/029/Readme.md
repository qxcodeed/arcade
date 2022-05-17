## L2 - {human} matrix

![](__capa.jpg)

O c++ padrão não tem uma classe Matriz. Mas nós podemos criar a nossa. Ela será muito útil para alguns exercícios desse repositório.


Você pode usar o modelo a seguir. Vai precisar estudar sobre:
- sobrecarga de métodos ==, !=, << e [].
- classes com template.
- especialização de template.

As sobrecargas do ostream já estão implementados. Os métodos de classe demarcados por { ... } ainda não. Comente tudo e vá descomentando e implementando aos pouquinhos. Teste seu código a cada método para ter certeza de que ele faz o que deve fazer.

<!--FILTER solver.cpp cpp-->
```cpp
#include <iostream>
#include <sstream>
#include <vector>

struct Pos {
    int l, c;
    Pos(int l, int c) { ... } 
    bool operator==(Pos pos) { ... }
    bool operator!=(Pos pos) { ... }
    std::string str() { ... }
};

std::ostream &operator<<(std::ostream &os, Pos pos) {
    return os << pos.str();
}

template <class T>
class matrix {
    int nl{0}, nc{0};
    std::vector<std::vector<T>> data;

public:
    // construtor com todos os valores default nulos
    matrix(int nl, int nc) { ... } 

    // construtor passando o valor default de cada elemento
    matrix(int nl, int nc, T def) { ... } 

    //return number of lines
    int nlines() { ... }

    //return number of columns
    int ncols() { ... }

    // retorna elemento se passar posicão
    T& at(Pos pos) { ... }

    // retorna elemento se passar posicão
    T& operator[](Pos pos) { ... }

    // retorna linha
    std::vector<T> &operator[](int l) { ... }

    // retorna se posição está dentro da matrix
    bool inside(Pos pos) { ... }

    // retorna se essa posição existe e eh esse valor
    bool is_value(Pos pos, char value) { ... }

    //retorna string com valores separados por espaço
    std::string str() { ... }
};

//faz uma especialização para imprimir matrix de char
//sem espaços entre os elementos
template <>
std::string matrix<char>::str() { ... }

template <class T>
std::ostream& operator<<(std::ostream& os, matrix<T>& m) {
    return os << m.str();
}

int main() {
    {
        matrix<int> m(3, 4, 5);
        std::cout << m;
    }
    {
        matrix<char> m(3, 4, 'a');
        std::cout << m;
    }
    {
        matrix<int> m(3, 4);
        m[0][0] = 1; //acesso via vetor secundário
        m[{2, 2}] = 2; //acesso via posicao
        std::cout << m;
        std::cout << m.inside({-1, 2}) << '\n';//nao existe
        std::cout << m.is_value({2, 2}, 2) << '\n';//se eh esse valor
        std::cout << m.is_value({-1, 2}, 0) << '\n';
    }

}
```
<!--FILTER_END-->
