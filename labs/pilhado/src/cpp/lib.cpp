#include "lib.h"

vector<Pos> get_vizinhos(Pos p) {
    // Essa função deve retornar um vetor
    // com as posições vizinhas da posição p
    // @DROP
    return { {p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c} };
    // @UNC
    // return {}
}

void procurar_saida(vector<string>& mat, Pos inicio, Pos fim) {
    // @UNC
    // (void) mat;
    // (void) inicio;
    // (void) fim;
    // @DROP
    stack<Pos> pilha;
    stack<Pos> dead;
    pilha.push(inicio);
    mat[inicio.l][inicio.c] = '.';
    while (!pilha.empty()) {
        Pos topo = pilha.top();

        if (topo.l == fim.l && topo.c == fim.c) {
            mat[topo.l][topo.c] = '.';
            break;
        }

        std::vector<Pos> vizinhos = get_vizinhos(topo);
        std::vector<Pos> validos;
        for (Pos viz : vizinhos) {
            if (mat[viz.l][viz.c] == ' ') {
                validos.push_back(viz);
                break;
            }
        }
        if (!validos.empty()) {
            pilha.push(validos[0]);
            mat[validos[0].l][validos[0].c] = '.';
        } else {
            mat[topo.l][topo.c] = 'x';
            dead.push(topo);
            pilha.pop();
        }
    }
    while (!dead.empty()) {
        Pos topo = dead.top();
        mat[topo.l][topo.c] = ' ';
        dead.pop();
    }
}
