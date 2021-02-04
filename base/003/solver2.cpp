#include <iostream>
#include <vector>
using namespace std;

#define PROF
#ifdef PROF
const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.'; 
#else
#endif

void show(vector<string> mat){
    for(int l = 0; l < (int) mat.size(); l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(vector<string> &mat, int l, int c){
    int nl = mat.size();
    int nc = mat[0].size();
#ifdef PROF
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return;
    if(mat[l][c] != TREE)
        return;
    mat[l][c] = FIRE;
    tocar_fogo(mat, l, c + 1);
    tocar_fogo(mat, l, c - 1);
    tocar_fogo(mat, l - 1, c);
    tocar_fogo(mat, l + 1, c);
#else
    //TODO faca seu codigo aqui
#endif
}

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &lfire, &cfire);
    vector<string> mat;
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        mat.push_back(line);
    }
    tocar_fogo(mat, lfire, cfire);
    show(mat);
}
