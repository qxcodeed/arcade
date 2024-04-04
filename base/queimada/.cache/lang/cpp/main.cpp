#include <iostream>
#include <vector>
#include "fogo.hpp"

void show_mat(std::vector<std::string> mat);
void read_mat(std::vector<std::string> &mat, int nl, int nc);

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    std::cin >> nl >> nc >> lfire >> cfire;
    std::vector<std::string> mat;
    read_mat(mat, nl, nc);

    tocar_fogo(mat, lfire, cfire);
    
    show_mat(mat);
}

void show_mat(std::vector<std::string> mat){
    for(int l = 0; l < (int) mat.size(); l++) {
        std::cout << mat[l] << "\n";
    }
}

void read_mat(std::vector<std::string> &mat, int nl, int nc){
    for(int l = 0; l < nl; l++) {
        std::string linha;
        std::cin >> linha;
        mat.push_back(linha);
    }
}