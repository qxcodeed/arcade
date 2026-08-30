#include "lib.h"

int main() {
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar(); //remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for (int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (mat[l][c] == 'I') {
                mat[l][c] = ' ';
                inicio = Pos{ l, c };
            }
            if (mat[l][c] == 'F') {
                mat[l][c] = ' ';
                fim = Pos{ l, c };
            }
        }
    }

    procurar_saida(mat, inicio, fim);

    for (string line : mat) {
        cout << line << endl;
    }
}
