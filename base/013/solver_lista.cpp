#include <iostream>
#include <list>
using namespace std;

void show(list<int>& lista, list<int>::iterator& sword){
    cout << "[";
    for(auto it = lista.begin(); it != lista.end(); ++it){
        cout << " " << *it;
        if(it == sword)
            cout << ">";
    }
    cout << " ]\n";
}

int main(){
    int qtd = 0;
    int esc = 0;
    cin >> qtd >> esc; 
    list<int> lista;
    for(int i = 1; i <= qtd; i++)
        lista.push_back(i);

    list<int>::iterator it = lista.begin();
    std::advance(it, esc - 1);
    
    while(lista.size() > 1){
        show(lista, it);
        it++;
        if(it == lista.end()) it = lista.begin();
        it = lista.erase(it);
        if(it == lista.end()) it = lista.begin();
    }
    show(lista, it);
}
