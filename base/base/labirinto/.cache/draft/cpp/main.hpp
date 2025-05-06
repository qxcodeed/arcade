#include <iostream>
#include <vector>

struct Pos{
    int l;
    int c;
};

bool procurar_saida(std::vector<std::string> &mat, Pos atual, Pos fim);

namespace lib {
    void remover_erros(std::vector<std::string> &mat){
        int nl = mat.size();
        int nc = mat[0].size();
        for(int l = 0; l < nl; l++)
            for(int c = 0; c < nc; c++)
                if(mat[l][c] == 'x')
                    mat[l][c] = '_';
    }

    void rodar_testes(){
        int nl = 0, nc = 0;
        std::cin >> nl >> nc;
        std::vector<std::string> mat(nl, ""); //começa com nl strings ""
        getchar();//remove \n after nc
        Pos inicio, fim;

        //carregando matriz
        for(int i = 0; i < nl; i++)
            std::getline(std::cin, mat[i]);

        //procurando inicio e fim e colocando ' ' nas posições iniciais
        for(int l = 0; l < nl; l++){
            for(int c = 0; c < nc; c++){
                if(mat[l][c] == 'I'){
                    mat[l][c] = '_';
                    inicio = Pos {l, c};
                }
                if(mat[l][c] == 'F'){
                    mat[l][c] = '_';
                    fim = Pos {l, c};
                }
            }
        }
        procurar_saida(mat, inicio, fim);
        remover_erros(mat);
        for(std::string line : mat)
            std::cout << line << '\n';
    }
}
