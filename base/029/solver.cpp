#include <iostream>
#include <sstream>
#include <vector>
//
struct Pos {
    int l, c;
    Pos(int l, int c) : 
        l(l), c(c) {
    }
    bool operator==(Pos pos) {
        return pos.l == l && pos.c == c;
    }
    bool operator!=(Pos pos) {
        return !(*this == pos);
    }
    std::string str() {
        std::stringstream ss;
        ss << "{" << l << "," << c << "}";
        return ss.str();
    }
};
//!RAW

std::ostream &operator<<(std::ostream &os, Pos pos) {
    return os << pos.str();
}

//!ADD
template <class T>
class matrix {
    int nl{0}, nc{0};
    std::vector<std::vector<T>> data;

public:
    // construtor com todos os valores default nulos
    matrix(int nl, int nc) : 
        nl(nl), nc(nc), data(nl, std::vector<T>(nc)) {
    }

    // construtor passando o valor default de cada elemento
    matrix(int nl, int nc, T def) : 
        nl(nl), nc(nc), data(nl, std::vector<T>(nc, def)) {
    }

    //return number of lines
    int nlines() {
        return nl;
    }

    //return number of columns
    int ncols() {
        return nc;
    }

    // retorna elemento se passar posicão
    T& at(Pos pos) {
        return data[pos.l][pos.c];
    }

    // retorna elemento se passar posicão
    T& operator[](Pos pos) {
        return at(pos);
    }

    // retorna linha
    std::vector<T> &operator[](int l) {
        return data[l];
    }

    // retorna se posição está dentro da matrix
    bool inside(Pos pos) {
        return !(pos.l < 0 || pos.l >= nl || pos.c < 0 || pos.c >= nc);
    }

    // retorna se essa posição existe e eh esse valor
    bool is_value(Pos pos, T value) {
        return inside(pos) && at(pos) == value;
    }

    //retorna string com valores separados por espaço
    std::string str() {
        std::stringstream ss;
        for (int l = 0; l < nl; l++) {
            for (int c = 0; c < nc; c++)
                ss << (c == 0 ? "" : " ") << data[l][c];
            ss << '\n';
        }
        return ss.str();
    }
};
//
//faz uma especialização para imprimir matrix de char
//sem espaços entre os elementos
template <>
std::string matrix<char>::str() {
//!DEL
    std::stringstream ss;
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++)
            ss << data[l][c]; 
        ss << '\n';
    }
    return ss.str();
}
//!RAW

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