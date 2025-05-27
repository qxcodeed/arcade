#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Pos{
    int l;
    int c;
};

#define get(mat, pos) mat[pos.l][pos.c]

vector<Pos> get_vizinhos(Pos p){
    vector<Pos> vet = {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

//refaz o caminho de volta colocando . no menor caminho
void go_back(vector<string> &mat, vector<vector<int>> &dist, Pos pos, int value){
    if(get(mat, pos) != 'x' || get(dist, pos) != value) //nao eh o vizinho certo
        return;
    get(mat, pos) = '.';
    for(Pos viz : get_vizinhos(pos))
        go_back(mat, dist, viz, value - 1); //procurando pelo proximo
}

bool procurar_saida(vector<string> &mat, Pos inicio, Pos fim){
    int nl = mat.size();
    int nc = mat[0].size();
    vector<vector<int>> dist(nl, vector<int>(nc, -1));
    list<Pos> fila;
    fila.push_back(inicio);
    get(mat, inicio) = 'x';
    get(dist, inicio) = 0;
    while(!fila.empty()){
        Pos frente = fila.front();
        if(frente.l == fim.l && frente.c == fim.c)
            return true;
        for(Pos viz : get_vizinhos(frente))
            if(get(mat, viz) == ' '){
                fila.push_back(viz);
                get(mat, viz) = 'x';
                get(dist, viz) = get(dist, frente) + 1;
                if(viz.l == fim.l && viz.c == fim.c){
                    go_back(mat, dist, fim, get(dist, frente) + 1);
                    return true;
                }
            }
        fila.pop_front();
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
