#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Pos {
    int l;
    int c;
};

vector<Pos> get_vizinhos(Pos p);
void procurar_saida(vector<string>& mat, Pos inicio, Pos fim);
