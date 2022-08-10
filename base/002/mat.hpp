//!DEL
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <optional>
#include <numeric>
#include <functional>
#include <sstream>
//!RAW
const char EMPTY = '.';

//metodo genérico para formatar um container como texto
template <class T>
std::string fmt(T data) {
    std::ostringstream ss;
    ss << "[";
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? ", " : "") << *it;
    ss << "]";
    return ss.str();
}

//gera um vector generico de [beg, end[
template <class T>
std::vector<T> range(T _beg, T _end) {
    std::vector<T> output;
    for (char c = _beg; c < _end; c++)
        output.push_back(c);
    return output;
}

//embaralha e retorna um vetor generico
template <class T>
std::vector<T> shuffle(std::vector<T> vet) {
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

//!ADD
struct Problem {
    std::string data;
    int lim;
    std::vector<int> holes; //posicoes a preencher

    Problem(std::string data, int lim) {
        this->data = data;
        this->lim = lim;
        for (int i = 0; i < (int) data.size(); i++)
            if (data[i] == EMPTY)
                this->holes.push_back(i);
    }

    //se posso colocar esse valor em data[index]
    bool fit(int index, char value) {
        int size = data.size();
        int inicio = std::max(index - lim    , 0);
        int final  = std::min(index + lim + 1, size);
        for(int i = inicio; i < final; i++)
            if(data[i] == value)
                return false;
        return true;
    }

    //tenta resolver o problema recursivamente retornando na primeira solução encontrada
    bool solve(int hindex) {
        if (hindex == (int) holes.size()) //se cheguei no fim, então preenchi tudo
            return true; //deu certo
        //
        auto index = holes[hindex];
        //
        auto values = shuffle(range<char>('0', '0' + lim + 1));
        for (char v : values) {
            if (this->fit(index, v)) {
                this->data[index] = v;
                if (this->solve(hindex + 1))
                    return true;
            }
        }
        data[index] = EMPTY;
        return false;
    }

    //tenta resoler o problema recursivamente contando quantas soluções existem
    int count_solutions(int hindex) {
        if (hindex == (int) this->holes.size())
            return true;
        //
        auto index = holes[hindex];
        //
        int solutions = 0;
        auto values = shuffle(range<char>('0', '0' + lim + 1));
        for (char v : values) {
            if (this->fit(index, v)) {
                this->data[index] = v;
                solutions += count_solutions(hindex + 1);
            }
        }
        data[index] = EMPTY;
        return solutions;
    }

    //verifica se remover essa posição, gera uma única solução
    bool can_remove(int index) {
        auto data_backup = this->data;
        data_backup[index] = EMPTY;
        Problem prob(data_backup, lim);
        int solutions = prob.count_solutions(0);
        // std::cout << index << " " << solutions << '\n';
        return solutions == 1;
    }

    //pega a lista de todas as posições e embaralha
    //para cada posição, se removê-la gera um problema com única solução
    //então remova
    void fill_holes() {
        auto avaliable = shuffle(range<int>(0, data.size()));
        for (int index : avaliable)
            if (can_remove(index))
                data[index] = EMPTY;
    }
};


//!RAW
int main(int argc, char * argv[]) {
    srand(time(0));
    int size { 5 }, lim { 3 };
    if (argc < 3) {
        puts("Passe size e lim como argumentos");
        return 1;
    }
    std::istringstream(argv[1]) >> size;
    std::istringstream(argv[2]) >> lim;
    std::cout << size << ' ' << lim << '\n';

    Problem prob(std::string(size, EMPTY), lim);
    prob.solve(0);
    std::cout << prob.data << "\n";
    prob.fill_holes();
    std::cout << prob.data << '\n';
}