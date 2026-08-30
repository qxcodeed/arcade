#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// @DROP
using namespace std;

void gerarPermutacoes(const string& restante, string construida, vector<string>& resultado) {
    if (restante.empty()) {
        resultado.push_back(construida);
        return;
    }

    for (size_t i = 0; i < restante.size(); i++) {
        string proxima = construida + restante[i];
        string novo_restante = restante.substr(0, i) + restante.substr(i + 1);
        gerarPermutacoes(novo_restante, proxima, resultado);
    }
}

// @KEEP
int main() {
    // @DROP
    string entrada;
    cin >> entrada;

    vector<string> permutacoes;

    gerarPermutacoes(entrada, "", permutacoes);

    sort(permutacoes.begin(), permutacoes.end()); // garante ordem lexicográfica

    for (const string& p : permutacoes) {
        cout << p << endl;
    }

    // @KEEP

    return 0;
}
