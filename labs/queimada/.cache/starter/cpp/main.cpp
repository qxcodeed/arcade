#include <iostream>
#include <vector>

void tocar_fogo(std::vector<std::string> &mat, int l, int c) {
    int nl = mat.size();
    int nc = mat[0].size();
    (void) mat;
    (void) l;
    (void) c;
    (void) nl;
    (void) nc;
    // se estiver fora da matriz, retorne
    // se o elemento atual não for uma arvore, retorne
    // queime a arvore colocando o caractere 'o' na posição atual
    // chame a recursão para todos os 4 vizinhos
}


void show_mat(std::vector<std::string> mat);
void read_mat(std::vector<std::string> &mat, int nl);

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    std::cin >> nl >> nc >> lfire >> cfire;
    std::vector<std::string> mat;
    read_mat(mat, nl);

    tocar_fogo(mat, lfire, cfire);
    show_mat(mat);
}

void show_mat(std::vector<std::string> mat){
    for(int l = 0; l < (int) mat.size(); l++) {
        std::cout << mat[l] << "\n";
    }
}

void read_mat(std::vector<std::string> &mat, int nl){
    for(int l = 0; l < nl; l++) {
        std::string linha;
        std::cin >> linha;
        mat.push_back(linha);
    }
}
