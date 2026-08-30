#include <iostream>
#include <vector>
using namespace std;
//                         
//1 2 4 7 8 19 34 36 78 81 89 92 96

pair<bool, vector<int>::iterator> busca_binaria(vector<int>& vet, int value){
    int inf = 0;
    int sup = vet.size() - 1;
    while(inf <= sup){
        int meio = (sup + inf) / 2;
        if(vet[meio] == value){
            return make_pair(true, vet.begin() + meio);
        }else if(value < vet[meio]){
            sup = meio - 1;
        }else{
            inf = meio + 1;
        }
    }
    return make_pair(false, vet.begin() + inf);
}

int main(){
    vector<int> vet;
    for(int i = 0; i < 20; i++){
        int value = rand() % 10;
        cout << value << " ";
        auto resp = busca_binaria(vet, value);
        if(!resp.first){
            vet.insert(resp.second, value);
        }
    }
    cout << "\n";
    for(int i = 0; i < (int) vet.size(); i++){
        cout << vet[i] << " ";
    }
}