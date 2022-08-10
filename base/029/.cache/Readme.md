## @029 L2 - {human} matrix

![](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/029/cover.jpg)

O c++ padrão não tem uma classe Matriz. Mas nós podemos criar a nossa. Ela será muito útil para alguns exercícios desse repositório.

Você pode usar o modelo a seguir. Vai precisar estudar sobre:
- sobrecarga de métodos ==, !=, << e [].
- classes com template.
- especialização de template.

As sobrecargas do `ostream` já estão implementados. Os métodos de classe demarcados por { ... } ainda não. Comente tudo e vá descomentando e implementando aos pouquinhos. Teste seu código a cada método para ter certeza de que ele faz o que deve fazer.

Arquivos
- [biblioteca](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/029/mat.h)
- [main](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/029/main.cpp)

```txt
>>>>>>>>
testes na main
========
@case matriz de inteiros: 1 
@case matriz de char: 1 
@case inicialização: 
@case acesso: 1 
@case check: 1 1 1 
acertos: 6/6
<<<<<<<<
```

<!--ADD mat.h cpp-->
```cpp
#include <iostream>
#include <sstream>
#include <vector>
//!+1
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
//!=
//consigo imprimir a matriz diretamente através do método str
std::ostream &operator<<(std::ostream &os, Pos pos) {
    return os << pos.str();
}

//!+1
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

    matrix(std::vector<std::vector<T>> init) : 
        data(init) {
    }
//!=
    //return number of lines
    int lines() {
        return nl;
    }

    //return number of columns
    int cols() {
        return nc;
    }
//!+1
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
//!+0

//faz uma especialização para imprimir matrix de char
//sem espaços entre os elementos
template <>
std::string matrix<char>::str() {
    std::stringstream ss;
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++)
            ss << data[l][c]; 
        ss << '\n';
    }
    return ss.str();
}
//!=

template <class T>
std::ostream& operator<<(std::ostream& os, matrix<T>& m) {
    return os << m.str();
}
```
<!--ADD_END-->