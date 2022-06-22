#include <iostream>
#include <list>
using namespace std;

void show(list<long>& lista, list<long>::iterator& sword){
    cout << "[";
    for(auto it = lista.begin(); it != lista.end(); ++it){
        cout << " " << *it;
        if(it == sword)
            cout << ">";
    }
    cout << " ]\n";
}
#include <cstdlib>
int main(int argc, char * argv[]){
    if(argc == 1){
        puts("passe parametro de tamanho da instancia");
        return 1;
    }
    long qtd = atol(argv[1]);
    long esc = 1;
    list<long> lista;
    for(long i = 1; i <= qtd; i++)
        lista.push_back(i);

    auto it = lista.begin();
    std::advance(it, esc - 1);
    
    while(lista.size() > 1){
    //    show(lista, it);
        it++;
        if(it == lista.end()) it = lista.begin();
        it = lista.erase(it);
        if(it == lista.end()) it = lista.begin();
    }
    show(lista, it);
}
