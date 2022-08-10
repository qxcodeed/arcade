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
//consigo imprimir a matriz diretamente através do método str
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

    matrix(std::vector<std::vector<T>> init) { ... } 
    //return number of lines
    int lines() {
        return nl;
    }

    //return number of columns
    int cols() {
        return nc;
    }
    // retorna elemento se passar posicão
    T& at(Pos pos) { ... }

    // retorna elemento se passar posicão
    T& operator[](Pos pos) { ... }

    // retorna linha
    std::vector<T> &operator[](int l) { ... }

    // retorna se posição está dentro da matrix
    bool inside(Pos pos) { ... }

    // retorna se essa posição existe e eh esse valor
    bool is_value(Pos pos, T value) { ... }

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

