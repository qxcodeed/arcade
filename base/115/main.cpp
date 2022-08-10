#include <iostream>
#include <vector>
#include <fstream>
#define XPAINT
#include "xpaint.h"

void create_img(std::vector<std::string> mat) {
    int nl = mat.size();
    int nc = mat[0].size();
    x_open(nc * 30, nl * 30, "lab");
    x_grid_init(30, 1);
    x_color_set(WHITE);
    x_clear();
    for(int l = 0; l < nl; l++) {
        for(int c = 0; c < nc; c++) {
            if(mat[l][c] == '#'){
                x_color_set(BLACK);
                x_grid_square(l, c);
            } else if(mat[l][c] == ' ') {
                x_color_set(WHITE);
                x_grid_square(l, c);
            }
        }
    }
    x_save();
    x_close();
}

std::vector<std::string> load_mat_from_file(std::string path) {
    std::ifstream ifs(path);
    if(!ifs.is_open()) {
        std::cout << "arquivo nao encontrado\n";
        exit(1);
    }
    int nl { 0 }, nc { 0 };
    ifs >> nl >> nc;
    std::vector<std::string> mat(nl, "");
    for (auto& line : mat)
        std::getline(ifs, line);
    return mat;
}

int main(int argc, char * argv[]){

    if(argc == 1) {
        puts("you need pass the path to your lab as argument");
        return 1;
    }

    auto mat = load_mat_from_file(argv[1]);
    create_img(nl, nc, mat);
    return 0;
}
