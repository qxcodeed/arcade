#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fn.hpp>

class Matriz {
public:
    int nl;     // numero de linhas da matriz
    int nc;     // numero de colunas da matriz
    std::vector<std::vector<int>> data;   // utilizando vector como matriz
    
    // Construtor: aloca matriz com m linhas e n colunas
    Matriz(int nl, int nc): 

    // atribui os dados do vetor para linhas e colunas
    // ex: matrix de 2 linhas por 3 colunas
    // [1,2,3,4,5,6] -> {[1,2,3], [4,5,6]}
    void set(std::vector<int> data);

    // Retorna o numero de linhas da matriz
    std::pair<int, int> size();

    // Retorna o vetor posição i
    std::vector<int>& operator[](int i);
    // matriz no formato {[1, 2, 3, 4], [5, 6, 7, 8]}
    std::string serial() const {
        return fn::tostr(data);
    }
};

std::ostream& operator<<(std::ostream& os, const Matriz& m) {
    return os << m.serial();
}

Matriz operator+(Matriz& A, Matriz& B) {
}

Matriz operator*(Matriz& A, Matriz& B) {
}


//adiciona matriz se o tamanho não for nulo e imprime o indice
void push_valid(std::vector<Matriz>& base, Matriz m) {
        if (m.size().first > 0) {
        std::cout << "index: " << base.size() << '\n';
        base.push_back(m);
    }
}

//converte string [1,2,3,4] para vetor de inteiros {1,2,3,4}
std::vector<int> str2vet(std::string str) {
    return str | fn::SLICE(1, -1) 
               | fn::JOIN() 
               | fn::SPLIT(',') 
               | fn::MAP(fn::strto<int>);
}


int main()
{
    std::vector<Matriz> base;

    while(true) {
        auto line = fn::input();
        auto args = fn::split(line);
        std::cout << "$" << line << '\n';
        auto cmd = args[0];

        if (cmd == "end") {
            break;
        } else if (cmd == "new") {
            base.push_back(Matriz(+args[1], +args[2]));
        } else if (cmd == "set") {
            auto vet = str2vet(args[2]);
            base.at(+args[1]).set(vet);
        } else if (cmd == "look") {
            for (int i = 0; i < (int) base.size(); ++i) {
                fn::print("{}: {}\n", i, base.at(i).serial());
            }
        } else if (cmd == "show") {
            fn::write(base.at(+args[1]));
        } else if (cmd == "sum") {
            auto result = base.at(+args[1]) + base.at(stoi(args[2]));
            push_valid(base, result);
        } else if (cmd == "prod") {
            auto result = base.at(+args[1]) * base.at(stoi(args[2]));
            push_valid(base, result);
        } else {
            std::cout << "fail: comando invalido\n";
        }
        
    }
    return 0;
}
