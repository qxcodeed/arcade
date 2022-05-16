#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <optional>
#include <numeric>
#include <functional>
#include <sstream>




bool fit(std::string data, int lim, int index, char value) {
    int size = data.size();
    int inicio = std::max(index - lim    , 0);
    int final  = std::min(index + lim + 1, size);
    for(int i = inicio; i < final; i++)
        if(data[i] == value)
            return false;
    return true;
}

int next_index(std::string data, int index) {
    int size = data.size();
    for (int i = index + 1; i < size; i++)
        if (data[i] == '_')
            return i;
    return size;
}

char dig2char(int dig) {    return dig + '0'; }

bool solve(std::string& data, int lim, int index) {
    if (index == (int) data.size()) //se cheguei no fim, então preenchi tudo
        return true; //deu certo

    if (data[index] != '_') //bora pro próximo
        return solve(data, lim, index + 1);
    
    for (char value = '0'; value <= dig2char(lim); value++) {
        if (fit(data, lim, index, value)) { //consigo colocar esse valor nesse indice
            data[index] = value; //coloco o valor
            if (solve(data, lim, index + 1)) //tento ir pro proximo
                return true; //se algum proximo resolveu o problema, então deu certo
        }
    }
    data[index] = '_'; //se chegou aqui, não achou resposta, desfaz qualquer mudança
    return false; //deu ruim
}


int main() {
    std::string data;
    int lim { };
    std::cin >> data >> lim;
    solve(data, lim, 0);
    std::cout << data << '\n';
}