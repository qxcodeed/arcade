// Arquivo de execucao
#include <iostream>
#include <stack>
using std::stack;

// Altere essa funcao.
// Retorne o menor elemento da pilha
// Pode assumir que a pilha possui pelo menos um elemento
int minStack(stack<int> pilha){
    //TODO: Complexidade O(n), onde n = tamanho da pilha

    // DICA: Voce deve usar a pilha nativa do C++:
    // pilha.top();       // retorna o elemento do topo (equivalente ao nosso 'peek')
    // pilha.push(info);  // adiciona info no topo da pilha
    // pilha.pop();       // remove do topo da pilha
    // pilha.empty();     // retorna se a pilha esta vazia
    ( void ) pilha;
    return -1;
}


// Altere essa funcao.
// Retorne o maior elemento da pilha
// Pode assumir que a pilha possui pelo menos um elemento
int maxStack(stack<int> pilha) {
    //TODO: Complexidade O(n), onde n = tamanho da pilha
    ( void ) pilha;
    return -1;
}


int main() {
    int n;
    stack<int> pilha;

    std::cin >> n;
    for(int i = 0; i < n; i++){
        int el;
        std::cin >> el;
        pilha.push(el);
    }

    int min = minStack(pilha);    
    int max = maxStack(pilha);   

    std::cout << min << " " << max << std::endl;
}
