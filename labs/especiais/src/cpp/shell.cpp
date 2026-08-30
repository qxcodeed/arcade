#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<pair<int, int>> occurr(vector<int> vet) {
    (void) vet;
    // @DROP
    map<int, int> m;
    for (auto x : vet)
        m[abs(x)]++;
    return {m.begin(), m.end()};
    // @UNC
    //return {};
}

vector<pair<int, int>> teams(vector<int> vet) {
    (void) vet;
    // @DROP
    int size = vet.size();
    if (size == 0)
        return {}; 
    vector<pair<int, int>> output;
    output.push_back({vet[0], 1});
    for (int i = 1; i < size; i++) {
        if (output.back().first == vet[i]) {
            output.back().second++;
        } else {
            output.push_back({vet[i], 1});
        }
    }
    return output;
    // @UNC
    //return {};
}

vector<int> mnext(vector<int> vet) {
    (void) vet;
    // @DROP
    int size = vet.size();
    auto has_woman = [&vet, size](int index) {
        return index >= 0 && index < size && vet[index] < 0;
    };
    vector<int> output;
    for (int i= 0; i < size; i++) {
        if (vet[i] > 0 && (has_woman(i - 1) || has_woman(i + 1))) {
            output.push_back(1);
        } else {
            output.push_back(0);
        }
    }
    return output;
    // @UNC
    //return {};
}

vector<int> alone(vector<int> vet) {
    (void) vet;
    // @DROP
    int size = vet.size();
    auto has_woman = [&vet, size](int index) {
        return index >= 0 && index < size && vet[index] < 0;
    };
    vector<int> output;
    for (int i= 0; i < size; i++) {
        if (vet[i] > 0 && (!has_woman(i - 1) && !has_woman(i + 1))) {
            output.push_back(1);
        } else {
            output.push_back(0);
        }
    }
    return output;
    // @UNC
    //return {};
}

int couple(vector<int> vet) {
    (void) vet;
    // @DROP
    int qtd { 0 };
    int size = vet.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (vet[i] != 0 && vet[j] != 0 && vet[j] && vet[i] == -vet[j]) {
                vet[i] = 0;
                vet[j] = 0;
                qtd++;
            }
        }
    }
    return qtd;
    // @UNC
    //return {};
}

bool has_subseq(vector<int> vet, vector<int> seq, int pos) {
    (void) vet;
    (void) seq;
    (void) pos;
    // @DROP
    for (int i = 0; i < (int) seq.size(); i++)
        if (pos + i >= (int) vet.size() || vet[pos + i] != seq[i])
            return false;
    return true;
    // @UNC
    //return {};
}

int subseq(vector<int> vet, vector<int> seq) {
    (void) vet;
    (void) seq;
    // @DROP
    int vet_size = (int) vet.size();
    for (int i = 0; i < vet_size; i++)
        if (has_subseq(vet, seq, i))
            return i;
    return -1;
    // @UNC
    //return {};
}

vector<int> erase(vector<int> vet, vector<int> pos_list) {
    (void) vet;
    (void) pos_list;
    // @DROP
    vector<int> output;
    for (int i = 0; i < (int) vet.size(); i++)
        if (find(pos_list.begin(), pos_list.end(), i) == pos_list.end())
            output.push_back(vet[i]);
    return output;
    // @UNC
    //return {};
}

vector<int> clear(vector<int> vet, int value) {
    (void) vet;
    (void) value;
    // @DROP
    vector<int> output;
    for (auto elem : vet)
        if (elem != value)
            output.push_back(elem);
    return output;
    // @UNC
    //return {};
}


vector<string> split(string str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim))
        tokens.push_back(token);
    return tokens;
}

vector<int> str2vet(string str) {
    vector<int> vet;
    stringstream ss(str.substr(1, str.size() - 2));
    string token;
    while (getline(ss, token, ','))
        vet.push_back(stoi(token));
    return vet;
}

void print(vector<pair<int, int>> output) {
    cout << "[";
    for (int i = 0; i < (int) output.size(); i++) {
        cout << "(" << output[i].first << ", " << output[i].second << ")";
        if (i != (int) output.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}
void print(vector<int> output) {
    cout << "[";
    for (int i = 0; i < (int) output.size(); i++) {
        cout << output[i];
        if (i != (int) output.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}
void print(string output) {
    cout << output << endl;
}
void print(int output) {
    cout << output << endl;
}

int main(){
 
    
    while(true) {
        string line;
        getline(cin, line);
        cout << "$" << line << endl;
        auto args = split(line, ' ');

        if     (args[0] == "occurr" ) { print(occurr(str2vet(args[1])));                   }
        else if(args[0] == "teams"  ) { print(teams(str2vet(args[1])));                    }
        else if(args[0] == "mnext"  ) { print(mnext(str2vet(args[1])));                    }
        else if(args[0] == "alone"  ) { print(alone(str2vet(args[1])));                    }
        else if(args[0] == "erase"  ) { print(erase(str2vet(args[1]), str2vet(args[2])));  }
        else if(args[0] == "clear"  ) { print(clear(str2vet(args[1]), stoi(args[2])));     }
        else if(args[0] == "subseq" ) { print(subseq(str2vet(args[1]), str2vet(args[2]))); }
        else if(args[0] == "couple" ) { print(couple(str2vet(args[1])));                   }
        else if(args[0] == "end"    ) { break;                                             }
        else                          { print("Invalid command");                          }
    }
}