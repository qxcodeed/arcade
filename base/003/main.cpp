#include <iostream>
#include <vector>
#include "lib.hpp"
using namespace std;


void show(vector<string> mat){
    for(int l = 0; l < (int) mat.size(); l++)
        cout << mat[l] << "\n";
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