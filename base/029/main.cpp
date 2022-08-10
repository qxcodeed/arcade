#include <iostream>
#include <vector>
#include "mat.h"

struct Test {
    int cont = 0;
    int total = 0;
    void open(std::string label) {
        static bool first = true;
        if (first) {
            first = false;
        } else {
            std::cout << "\n";
        }
        std::cout << "@case " << label << ": ";
    }
    void test (bool value) {
        total += 1;
        cont += value ? 1 : 0;
        std::cout << value << ' ';
    }
    void finish() {
        std::cout << "\nacertos: " << cont << "/" << total << '\n';
    };
};
Test t;

int main() {
    {
        t.open("matriz de inteiros");
        matrix<int> m(3, 4, 5);
        std::string expected = "5 5 5 5\n5 5 5 5\n5 5 5 5\n";
        t.test(m.str() == expected);
    }
    {
        t.open("matriz de char");
        matrix<char> m(3, 4, 'a');
        std::string expected = "aaaa\naaaa\naaaa\n";
        t.test(m.str() == expected);
    }
    {
        t.open("inicialização");
        matrix<int> m({{1,2,3}, {4, 5, 6}});
    }
    {
        t.open("acesso");
        matrix<int> m(3, 4);
        m[0][0] = 1; //acesso via vetor secundário
        m[{2, 2}] = 2; //acesso via posicao
        std::string expected = "1 0 0 0\n0 0 0 0\n0 0 2 0\n";
        t.test(m.str() == expected);

        t.open("check");
        t.test(m.inside({-1, 2}) == false);
        t.test(m.is_value({2, 2}, 2) == true);
        t.test(m.is_value({-1, 2}, 0) == false);
    }
    t.finish();
}