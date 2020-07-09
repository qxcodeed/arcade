#define PROF
#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    #ifdef PROF
        nrot = nrot % vet.size();
        vector<int> aux;
        for(int i = vet.size() - nrot; i < (int)vet.size(); i++)
            aux.push_back(vet[i]);
        for(int i = (int) vet.size() - nrot - 1; i >= 0 ; i--)
            vet[i + nrot] = vet[i];
        for(int i = 0; i < (int) aux.size(); i++)
            vet[i] = aux[i];
    #else

    #endif
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet;
    for(int i = 0; i < size; i++){
        int value;
        cin >> value;
        vet.push_back(value);
    }
    right_rotation(vet, nrot);
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}