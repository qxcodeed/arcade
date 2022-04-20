#include <iostream>
#include <list>
#include <numeric>


void show(std::list<int>& lista, std::list<int>::iterator& sword){
    std::cout << "[";
    for(auto it = lista.begin(); it != lista.end(); ++it){
        std::cout << " " << *it;
        if(it == sword)
            std::cout << ">";
    }
    std::cout << " ]\n";
}

int main(){
    int size { };
    int chosen { };
    std::cin >> size >> chosen; 
    std::list<int> lista(size);
    std::iota(std::begin(lista), std::end(lista), 1); //jeito fresco de inserir de 1 até n
    auto sword = std::next(lista.begin(), chosen - 1);
    while(lista.size() > 1){
        auto loop = [&lista](auto it) { return it == std::end(lista) ? std::begin(lista) : it; };
        show(lista, sword);
        sword = loop(++sword);
        sword = loop(lista.erase(sword));
    }
    show(lista, sword);
}
