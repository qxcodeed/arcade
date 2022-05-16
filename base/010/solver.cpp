#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <optional>
#include <numeric>
#include <functional>
#include <sstream>

const char EMPTY = '.';

//gera um vector de char de [beg, end[
template <class T>
std::vector<T> range(T _beg, T _end) {
    std::vector<T> output;
    for (char c = _beg; c < _end; c++)
        output.push_back(c);
    return output;
}

struct Problem {
    std::string data;
    int lim;
    std::vector<int> holes;

    Problem(std::string data, int lim) {
        this->data = data;
        this->lim = lim;
        for (int i = 0; i < (int) data.size(); i++)
            if (data[i] == EMPTY)
                this->holes.push_back(i);
    }

    bool fit(int index, char value) {
        int size = data.size();
        int inicio = std::max(index - lim    , 0);
        int final  = std::min(index + lim + 1, size);
        for(int i = inicio; i < final; i++)
            if(data[i] == value)
                return false;
        return true;
    }

    bool solve(int hindex) {
        if (hindex == (int) holes.size()) //se cheguei no fim, então preenchi tudo
            return true; //deu certo

        auto index = holes[hindex];

        for (char value : range<char>('0', '0' + lim + 1)) {
            if (this->fit(index, value)) { //consigo colocar esse valor nesse indice
                this->data[index] = value; //coloco o valor
                if (this->solve(hindex + 1)) //tento ir pro proximo
                    return true; //se algum proximo resolveu o problema, então deu certo
            }
        }
        this->data[index] = EMPTY; //se chegou aqui, não achou resposta, desfaz qualquer mudança
        return false; //deu ruim
    }
};



int main() {
    std::string data;
    int lim { };
    std::cin >> data >> lim;
    Problem prob(data, lim);
    prob.solve(0);
    std::cout << prob.data << '\n';
}