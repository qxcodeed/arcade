//==
#include <iostream>
#include <vector>
#include "main.hpp"

using namespace std;

#define get(mat, pos) mat[pos.l][pos.c]

//++0

//retorna um vetor com todos os vizinhos de pos
//left, up, right, down
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

//função recursiva que verifica se pos atual eh o fim
//e retorna se o caminho é valido para chegar no fim
bool procurar_saida(vector<string> &mat, Pos atual, Pos fim){
    if(atual.l == fim.l && atual.c == fim.c){
        get(mat, atual) = '.';
        return true;
    }
    if(get(mat, atual) != '_')
        return false; //parede ou ja foi visitado
    get(mat, atual) = '.';
    for(Pos viz : get_vizinhos(atual)){
        if(procurar_saida(mat, viz, fim)){
            return true;
        }
    }
    get(mat, atual) = 'x';
    return false;
}
//==
int main(){
    lib::rodar_testes();
    return 0;
}
