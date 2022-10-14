#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>  //setw
#include <aux.hpp>

//++1
class Matriz {
public:
    int nl;     // numero de linhas da matriz
    int nc;     // numero de colunas da matriz
    std::vector<std::vector<int>> data;   // utilizando vector como matriz
    
    // Construtor: aloca matriz com m linhas e n colunas
    Matriz(int nl, int nc): 
        nl(nl), nc(nc), data(nl, std::vector<int>(nc, 0)) {
    }

    // atribui os dados do vetor para linhas e colunas
    // ex: matrix de 2 linhas por 3 colunas
    // [1,2,3,4,5,6] -> {[1,2,3], [4,5,6]}
    void set(std::vector<int> data) {
        int i = 0;
        for(auto& v : this->data) {
            for(auto& e : v) {
                e = data[i++];
            }
        }
    }

    // Retorna o numero de linhas da matriz
    std::pair<int, int> size() {
        return {nl, nc};
    }

    // Retorna o vetor posição i
    std::vector<int>& operator[](int i) {
        static std::vector<int> dummy(nc, 0);
        if (i < 0 || i >= nl) {
            std::cerr << "Erro: indice fora do intervalo" << std::endl;
            return dummy;
        }
        return data[i];
    }

    // matriz no formato {[1, 2, 3, 4], [5, 6, 7, 8]}
    std::string serial();
};

//++0
Matriz operator+(Matriz& A, Matriz& B) {
    if (A.size() != B.size()) {
        std::cout << "fail: incompativeis\n";
        return Matriz(0, 0);
    }
    auto [nl, nc] = A.size();
    Matriz C(nl, nc);
    for(int i = 0; i < nl; ++i) {
        for(int j = 0; j < nc; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matriz operator*(Matriz& A, Matriz& B) {
    auto [nla, nca] = A.size();
    auto [nlb, ncb] = B.size();
    if (nca != nlb) {
        std::cout << "fail: incompativeis\n";
        return Matriz(0, 0);
    }
    Matriz C(nla, ncb);
    for(int i = 0; i < nla; ++i) {
        for(int j = 0; j < ncb; ++j) {
            for(int k = 0; k < nca; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

//==

// matriz no formato quadrado
std::ostream& operator<<(std::ostream& os, Matriz m);

// imprimindo todos os seriais das matrizes colocando o indice
std::ostream& operator<<(std::ostream& os, std::vector<Matriz> vet);

//adiciona matriz se o tamanho não for nulo e imprime o indice
void push_valid(std::vector<Matriz>& base, Matriz m);

int main()
{
	aux::Chain chain;
    aux::Param param;
    std::vector<Matriz> base;

    auto __VET = [&](int index) { return aux::to_vet<int>(param.at(index));};
    auto __INT = [&](int index) { return aux::to<int>    (param.at(index));};
	
    chain["new"]  = [&] { base.push_back(Matriz(__INT(1), __INT(2))); };
    chain["set"]  = [&] { base.at(__INT(1)).set(__VET(2));};
    chain["look"] = [&] { base               | aux::PRINT(); };
	chain["show"] = [&] { base.at(__INT(1))  | aux::PRINT();};
    chain["sum"]  = [&] { push_valid(base, base.at(__INT(1)) + base.at(__INT(2))); };
    chain["prod"] = [&] { push_valid(base, base.at(__INT(1)) * base.at(__INT(2))); };

    aux::execute(chain, param);
	return 0;
}

// matriz no formato {[1, 2, 3, 4], [5, 6, 7, 8]}
std::string Matriz::serial() {
    std::stringstream ss;
    ss << (data | aux::MAP(LAMBDA(x, x | aux::FMT())) | aux::FMT(", ", "{", "}"));
    return ss.str();
}

// matriz no formato quadrado
std::ostream& operator<<(std::ostream& os, Matriz m) {
    auto fmtvalue = [] (int x) { std::stringstream ss; ss << std::setw(4) << x; return ss.str(); };
    auto fmtvet   = [&](auto vet) { return vet | aux::MAP(fmtvalue) | aux::FMT(); };
    return os << (m.data | aux::MAP(fmtvet) | aux::JOIN("\n"));
}

// imprimindo todos os seriais das matrizes colocando o indice
std::ostream& operator<<(std::ostream& os, std::vector<Matriz> vet) {
    int i = 0;
    auto fmt = [&i] (auto x) { return std::to_string(i++) + ": " + x.serial(); };
    return os << (vet | aux::MAP(fmt) | aux::JOIN("\n"));
}

//adiciona matriz se o tamanho não for nulo e imprime o indice
void push_valid(std::vector<Matriz>& base, Matriz m) {
    if (m.size().first > 0) {
        std::cout << "index: " << base.size() << '\n';
        base.push_back(m);
    }
}