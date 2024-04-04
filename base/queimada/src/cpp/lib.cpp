#include "fogo.hpp"

void tocar_fogo(std::vector<std::string> &mat, int l, int c) {
    // ==
    int nl = mat.size();
    int nc = mat[0].size();
    // --
    if ( (l < 0) || (l >= nl) || (c < 0) || (c >= nc) ) {
        return;
    }
    if (mat[l][c] != '#') {
        return;
    }
    mat[l][c] = 'o';
    tocar_fogo(mat, l, c + 1);
    tocar_fogo(mat, l, c - 1);
    tocar_fogo(mat, l - 1, c);
    tocar_fogo(mat, l + 1, c);

    // ==
    // se estiver fora da matriz, retorne
    // se o elemento atual não for uma arvore, retorne
    // queime a arvore colocando o caractere 'o' na posição atual
    // chame a recursão para todos os 4 vizinhos
}

