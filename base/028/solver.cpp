#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

template <class T>
vector<T> range(T init, T finish) {
    vector<T> output;
    for (T i = init; i < finish; i++)
        output.push_back(i);
    return output;
}

template <class T>
T shuffle(T data) {
    std::shuffle(data.begin(), data.end());
    return data;
}

struct Problem {
    vector<string> data;
    int size { 9 };
    int dim { 3 };
    vector<pair<int, int>> holes; //posicoes para serem preenchidas

    Problem(vector<string> data) {
        this->data = data;
        this->size = data.size();
        this->dim = sqrt(this->size);

        for (int l = 0; l < size; l++)
            for (int c = 0; c < size; c++)
                if (data[l][c] == '.')
                    holes.push_back(make_pair(l, c));
    }

    bool fit(int hindex, char value) {
        auto [pl, pc] = holes[hindex];
        
        for (int l = 0; l < size; l++) //olhando todas as linhas dessa coluna
            if (data[l][pc] == value) 
                return false;
        
        for (int c = 0; c < size; c++) //olhando todas as colunas dessa linha
            if (data[pl][c] == value)
                return false;
        
        int lh = pl - pl % dim; //achando a cabeça do quadrante removendo a sobra
        int ch = pc - pc % dim;
        for (int l = lh; l < lh + dim; l++)
            for (int c = ch; c < ch + dim; c++)
                if (data[l][c] == value)
                    return false;
        return true;
    }

    void put(int hindex, char value) {
        auto [pl, pc] = holes[hindex];
        data[pl][pc] = value;
    }

    bool solve(int hindex) {
        if (hindex == (int) holes.size())
            return true;
        
        auto values = range<char>('1', '0' + size + 1);
        for (char v : values) {
            if (fit(hindex, v)) {
                put(hindex, v);
                if (solve(hindex + 1))
                    return true;
            }
        }
        put(hindex, '.');
        return false;
    }

    std::string str() {
        std::stringstream ss;
        for (auto line : data)
            ss << line << endl;
        return ss.str();
    }
};

int main() {
    // ifstream ifs("input.txt");
    auto& input = cin;

    int size { };
    input >> size;
    vector<string> data(size);
    for (int i = 0; i < size; i++)
        input >> data[i];
    
    Problem prob(data);
    prob.solve(0);
    std::cout << prob.str();
}