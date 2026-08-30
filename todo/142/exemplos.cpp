#include <iostream>
#include <vector>
#include <list>
#include <algorithm> //find sort
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

int exemplo_vet()
{
    vector<int> vet = {1, 2, 3, 4, 5, 1, 2, 10, 12, 7};

    for(vector<int>::iterator i = vet.begin(); i != vet.end(); i++)
        cout << *i << " ";

    cout << endl;

    //alterar os dados exige referencia
    for(auto &elem : vet)
        elem++;

    for(auto i = vet.begin(); i != vet.end(); i++)
        (*i)++;

    cout << endl;

    for(auto elem : vet)
        cout << elem << " ";

    //auto
//    auto x = 5.0;
//    auto y = "casa";
//    auto z = 'z';
    cout << endl;
    auto it = std::find(vet.begin(), vet.end(), 4);
    if(it != vet.end()){
        it += 2;
        cout << *it;
    }

    std::sort(vet.begin(), vet.end());
    for(auto x : vet)
        cout << x << " ";

    return 0;
}

void exemplo_list(){
    list<string> nomes = { "uva", "vovo", "eva", "ivo", "vovo", "ovo", "avo", "vovo"};

    auto it = nomes.begin();
    while(it != nomes.end()){
        if(*it == "vovo")
            it = nomes.erase(it);
        else
            it++;
    }
    for(auto elem : nomes)
        cout << elem << " ";
    cout << endl;

}

#include <fstream>
void exemplo_arquivo(){
    ifstream input("data.txt");
    if(!input.is_open()){
        cout << "AAAAAAAAAAAAAAAAAAAA DEU PAU!!!!!!!" << endl;
    }
    string opcao;
    while(input >> opcao){
        int num;
        input >> num;
        cout << "nome: " << opcao << " valor: " << num << "\n";
    }
    input.close();
    ofstream saida("saida.txt");
    saida << "terminei!" << endl;
    saida.close();
}

void exemplo_mapa(){
    list<string> nomes = { "uva", "vovo", "eva", "ivo",
                           "vovo", "ovo", "avo", "vovo"};
    unordered_map<string, int> ocorrencias;
    for(auto nome : nomes)
        if(ocorrencias.find(nome) == ocorrencias.end())
            ocorrencias[nome] = 1;
        else
            ocorrencias[nome]++;

    for(auto par : ocorrencias)
        cout << par.first << " " << par.second << endl;
}

void exemplo_set(){
    srand(time(NULL));
    unordered_set<int> conj;

    for(int i = 0; i < 50; i++){
        conj.insert(rand() % 25);
    }
    for(auto x : conj)
        cout << x << " ";
}

int main(){
    //exemplo_vet();
    //exemplo_arquivo();
    //exemplo_mapa();
    exemplo_set();
    return 0;
}
