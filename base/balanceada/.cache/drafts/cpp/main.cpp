// Arquivo de execucao
#include <iostream>
#include <stack>
using std::stack;
using std::string;

// Altere essa funcao.
// Receba uma string composta de parenteses e colchetes
// e retorna 'true' se essa sequencia esta balanceada
// e retorna 'false' caso contrario.

// Uma sequencia e considerada balanceada se cada simbolo
// de abertura tem um símbolo correspondente de fechamento na ordem correta,
// e os simbolos estao corretamente aninhados.
bool isBalanced(string word){
    // TODO: complexidade O(n)
    (void) word;
    return false;
}

// Exemplos:
// isBalanced("") == true
// isBalanced("()") == true
// isBalanced("(((())))") == true
// isBalanced("()()()()") == true
// isBalanced("[()]") == true
// isBalanced("([])[()]") == true
// isBalanced("((()") == false
// isBalanced(")()") == false
// isBalanced("[(])") == false
// isBalanced("[(][)]") == false


int main() {
    string s;
    std::cin >> s;

    if(isBalanced(s)) {
        std::cout << "balanceado" << std::endl;
    } else {
        std::cout << "nao balanceado" << std::endl;
    }
}
