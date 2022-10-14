#include <iostream>
#include <vector>
using namespace std;

struct Pos{
    int l;
    int c;
};

#define get(mat, pos) mat[pos.l][pos.c]

vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool procurar_saida(vector<string> &mat, Pos inicio, Pos fim){
    vector<Pos> pilha;
    pilha.push_back(inicio);
    get(mat, inicio) = '.';
    while(!pilha.empty()){
        Pos topo = pilha.back();
        if(topo.l == fim.l && topo.c == fim.c)
            return true;
        vector<Pos> possiveis;
        for(Pos viz : get_vizinhos(topo))
            if(get(mat, viz) == ' ')
                possiveis.push_back(viz);
        if(possiveis.empty()){
            pilha.pop_back();
            get(mat, topo) = 'x';
        }else{
            pilha.push_back(possiveis.front());
            get(mat, possiveis.front()) = '.';
        }
    }
    return false;
}
void remover_erros(vector<string> &mat){
    int nl = mat.size();
    int nc = mat[0].size();
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            if(mat[l][c] == 'x')
                mat[l][c] = ' ';
}

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }
    procurar_saida(mat, inicio, fim);
    remover_erros(mat);
    for(string line : mat)
        cout << line << endl;
    // cout << "       nl=" << nl << " nc=" << nc << "\n";
    // cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    // cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl;
}