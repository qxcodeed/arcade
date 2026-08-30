#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <optional>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

const int MARKER_INT = -1;
const char MARKER_CHAR = '_';

bool enable_shuffle = true;


struct Problem {
    vector<int> data;
    int lim;
    Problem(vector<int> data, int lim):
        data(data), lim(lim){    
    }

    Problem(string data, int lim){
        stringstream ss(data);
        char c;
        while(ss >> c)
            this->data.push_back(c == MARKER_CHAR ? MARKER_INT : (c - '0'));
        this->lim = lim;    
    }

    friend ostream& operator<<(ostream &os, const Problem& prob) {
        auto& [data, lim] = prob;
        for(auto value : data)
            if(value == MARKER_INT)
                os << MARKER_CHAR;
            else
                os << value;
        os << " : " << lim;
        return os;
    }
};

bool fit(Problem prob, int index, int value) {
    auto& [data, lim] = prob;
    int size = data.size();
    int inicio = std::max(index - lim    , 0);
    int final  = std::min(index + lim + 1, size);
    for(int i = inicio; i < final; i++)
        if(data[i] == value)
            return false;
    return true;
}

vector<int> range(int max) {
    vector<int> vet(max + 1);
    for(int i = 0; i <= max; i++)
        vet[i] = i;
    if(enable_shuffle)
        random_shuffle(begin(vet), end(vet));
    return vet;
}

// int find_next(Problem prob, int atual) {
//     for(int i = atual + 1; i < (int) prob.data.size(); i++)
//         if(prob.data[i] == MARKER_INT)
//             return i;
//     return -1;
// }


int find_next(Problem prob, int atual) {
    vector<int> empties;
    for(int i = 0; i < (int) prob.data.size(); i++)
        if(prob.data[i] == MARKER_INT)
            empties.push_back(i);
    return empties.size() == 0 ? -1 : empties[rand() % empties.size()];
}

std::optional<Problem> solve(Problem prob, int index) {
    auto& [data, lim] = prob;
    if(index == -1)
        return prob;
    if(data[index] != MARKER_INT)
        index = find_next(prob, index);
    for(auto v : range(lim)) {
        if(fit(prob, index, v)) {
            data[index] = v;
            cerr << prob << endl;
            int next = find_next(prob, index);
            if(auto resp = solve(prob, next))
                return resp;
        }
    }
    return {};
}


// std::optional<Problem> interative_solve(Problem prob, int lim, Generator range) {
//     vector<int> empties;
//     for(int i = 0; i < prob.size(); i++)
//         if(prob[i] == MARKER_INT)
//             empties.push_back(i);
//     int empties_index = 0;

//     while(empties_index < (int) empties.size()){
//         int value = vet[empties[empties_index]]
//         if(fit(prob, lim, empties[empties_index], ))
//         for(auto v : range(lim)) {
//             if(fit(prob, lim, index, v)) {
//                 prob[index] = v;
//                 cout << prob << endl;
//                 if(auto resp = solve(prob, lim, index + 1, range))
//                     return resp;
//             }
//         }
//     }
//     return {};
// }


bool can_erase(Problem prob, int index) {
    auto& [data, lim] = prob;
    int cont = 0;
    for(auto v : range(lim)) {
        data[index] = MARKER_INT;
        if(fit(prob, index, v)){
            data[index] = v;
            if(solve(prob, find_next(prob, index)))
                cont++;
            if(cont == 2)
                return false;
        }
    }
    return true;
}

Problem create(int size, int lim) {
    enable_shuffle = true;
    auto resp = solve(Problem(string(size, MARKER_CHAR), lim), 0);
    auto prob = resp.value();
    auto vet_pos = range(size - 1);
    enable_shuffle = false;

    for(auto pos : vet_pos){
        if(can_erase(prob, pos)){
            prob.data[pos] = MARKER_INT;
            cout << "erased " << pos << endl;
        } else {
            cout << "blocked " << pos << endl;
        }
    }
    return prob;
}

int main() {
    srand(time(0));
    // auto prob = Problem("2__0______________3___________", 3);
    // auto resp = solve(prob, 0).value_or(prob);
    auto resp = create(5, 3);
    cout << resp << endl;
    //cout << resp.data << endl;
}