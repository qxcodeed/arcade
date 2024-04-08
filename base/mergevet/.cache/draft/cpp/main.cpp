#include <iostream>
#include "lib.hpp"

// implementar construtor padrão
// implementar o destrutor
// implementar o len
void teste1() {
    std::cout << "Criando vetor com capacidade 4" << '\n';
    Vetor v(4);
    std::cout << "size: " << v.len() << '\n';
}

// implementar o operador []
// implementar o push_back
// implementar o str
void teste2(){
    Vetor v(4);
    std::cout << "Adicionando 1,2,3,0 usando push back" << '\n';
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(0);

    std::cout << "Esperado: [1,2,3,0]" << '\n';
    std::cout << "Recebido: " << v.str() << '\n';

    std::cout << "Elemento 2: " << v[2] << '\n';
    std::cout << "Mudando elemento 2 para 5" << '\n';
    v[2] = 5;
    std::cout << "Esperado: [1,2,5,0]" << '\n';
    std::cout << "Recebido: " << v.str() << '\n';
}

// implementar o construtor de lista de inicialização
// implementar o construtor de cópia
void teste3(){
    std::cout << "Criando vetor com lista de inicialização {1,2,3}" << '\n';
    Vetor v = {1,2,3};
    std::cout << "Esperado: [1,2,3]" << '\n';
    std::cout << "Recebido: " << v.str() << '\n';

    std::cout << "Criando vetor com cópia do anterior" << '\n';
    Vetor v2 = v;
    std::cout << "Esperado: [1,2,3]" << '\n';
    std::cout << "Recebido: " << v2.str() << '\n';
}

// testando ==
// testando pop_back
void teste4() {
    std::cout << "Criando vetor v1 {4,5,1}" << '\n';
    Vetor v1 = {4,5,1};
    std::cout << "Criando vetor v2 {4,5,1,7}" << '\n';
    Vetor v2 = {4,5,1,7};
    std::cout << "Fazendo v1 == v2" << '\n';
    std::cout << "Esperado: 0" << '\n';
    std::cout << "Recebido: " << (v1 == v2) << '\n';
    std::cout << "Fazendo pop_back em v2" << '\n';
    v2.pop_back();
    std::cout << "Fazendo v1 == v2" << '\n';
    std::cout << "Esperado: 1" << '\n';
    std::cout << "Recebido: " << (v1 == v2) << '\n';
}

void teste5() {
    std::cout << "Inicializando vetores va, vb e vc" << '\n';
    std::cout << "va = {6,8,5}, vb = {3,2,1}, vc = {4,0,9}" << '\n';
    Vetor va = {6,8,5}; // utilizando o construtor da lista de inicialização
    Vetor vb = {3,2,1};
    Vetor vc = {4,0,9};
    Vetor vall[] = {va, vb, vc};

    // na hora que o mergeAll devolve o vetor, ele chama o construtor de cópia
    Vetor received = mergeAll(vall, 3); 
    Vetor expected = {1,2,3,5,8,6,9,0,4};

    std::cout << "Fazendo merge" << '\n';
    std::cout << "Esperado: [1,2,3,5,8,6,9,0,4]" << '\n';
    std::cout << "Recebido: " << received.str() << '\n';

}


int main() {
    int teste_index {};
    std::cin >> teste_index;
    switch (teste_index) {
        case 1: teste1(); break;
        case 2: teste2(); break;
        case 3: teste3(); break;
        case 4: teste4(); break;
        case 5: teste5(); break;
    }
}

