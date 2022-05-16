#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <optional>
#include <numeric>
#include <functional>
#include <sstream>

char dig2char(int dig) {
    return dig + '0';
}

struct Problem {
    std::string data;
    int lim;
    Problem(std::string data = "", int lim = 0): data(data), lim(lim){}
};

bool fit(const Problem& prob, int index, char value) {
    auto& [data, lim] = prob;
    int size = data.size();
    int _beg = std::max(index - lim    , 0);
    int _end  = std::min(index + lim + 1, size);
    for(int i = _beg; i < _end; i++)
        if(data[i] == value)
            return false;
    return true;
}

//gera um vector de char de [beg, end[
template <class T>
std::vector<T> range(T _beg, T _end) {
    std::vector<T> output;
    for (char c = _beg; c < _end; c++)
        output.push_back(c);
    return output;
}

template <class T>
std::vector<T> shuffle(std::vector<T> vet) {
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

bool solve(Problem& prob,  int index) {
    if (index == (int) prob.data.size())
        return true;

    if (prob.data[index] != '_')
        return solve(prob, index + 1);
    
    auto values = shuffle(range<char>('0', '0' + prob.lim + 1));
    for (char value : values) {
        if (fit(prob, index, value)) {
            prob.data[index] = value; //perform the change
            if (solve(prob, index + 1))
                return true;
        }
    }
    prob.data[index] = '_'; //undo the change
    return false;
}

void __count_solutions(Problem& prob,  int index, int *solutions) {
    if (index == (int) prob.data.size()) {
        *solutions += 1;
        std::cout << prob.data << '\n';
        return;
    }

    if (prob.data[index] != '_')
        __count_solutions(prob, index + 1, solutions);
    
    auto values = shuffle(range<char>('0', '0' + prob.lim + 1));
    for (char v : values) {
        if (fit(prob, index, v)) {
            prob.data[index] = v; //perform the change
            __count_solutions(prob, index + 1, solutions);
        }
    }
    prob.data[index] = '_'; //undo the change
}

bool can_remove(Problem prob, int index) {
    prob.data[index] = '_';
    int solutions = 0;
    __count_solutions(prob, 0, &solutions);
    std::cout << solutions << '\n';
    return solutions == 1;
}

std::string fmt(auto data) {
    std::ostringstream ss;
    ss << "[";
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? ", " : "") << *it;
    ss << "]";
    return ss.str();
}

int main(int argc, char * argv[]) {
    srand(time(0));
    int size { }, dist { };
    if (argc < 3) {
        puts("Passe size e dist como argumentos");
        return 1;
    }
    std::istringstream(argv[1]) >> size;
    std::istringstream(argv[2]) >> dist;
    std::cout << size << ' ' << dist << '\n';

    Problem prob(std::string(size, '_'), dist);
    solve(prob, 0);

    auto avaliable = range<int>(0, prob.data.size());
    while (!avaliable.empty()) {
        int pos = rand() % avaliable.size();
        int index = avaliable[pos];
        if (can_remove(prob, index))
            prob.data[index] = '_';
        avaliable.erase(avaliable.begin() + pos);
    }

    std::cout << prob.data << '\n';
}