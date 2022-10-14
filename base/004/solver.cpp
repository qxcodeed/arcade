#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


void print(vector<int> vet){
    cout << "[";
    for(auto x : vet)
        cout << " " << x;
    cout << " ]\n";
}

void processa(vector<int> vet){
    if(vet.size() == 1)
        return;
    vector<int> aux;
    for(size_t i = 0; i < vet.size() - 1; i++)
        aux.push_back(vet[i] + vet[i + 1]);
    processa(aux);
    print(aux);
}

int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while(ss >> value)
        vet.push_back(value);
    processa(vet);
    print(vet);
}