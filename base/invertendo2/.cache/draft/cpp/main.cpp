#include <iostream>
#include <stack>
using std::stack;

// Altere essa funcao.
// Utilizando apenas a pilhaA, e duas pilhas vazias pilhaB e pilhaC
// inverta os elementos da pilhaA.
void invertStack(stack<int> &pilhaA, stack<int> &pilhaB, stack<int> &pilhaC){
    //TODO: Complexidade tempo O(n), onde n = tamanho da pilha
    //      Complexidade de memoria O(1)

    // OBS: Nao e permitido alocar qualquer outra estrutura auxiliar
    //      como vetor. Utilize somente as 3 pilhas recebidas nos parametros.

    // OBS2: No parametro (stack<int> &pilha) utilizamos
    //      o "&pilha" para receber a variavel como referencia
    //      dessa forma, alteramos a pilha original sem
    //      utilizar ponteiros explicitamente.

    // DICA: Voce deve usar somente os metodos de pilha nativa do C++:
    // pilha.top();       // retorna o elemento do topo (equivalente ao nosso 'peek')
    // pilha.push(info);  // adiciona info no topo da pilha
    // pilha.pop();       // remove do topo da pilha
    // pilha.empty();     // retorna se a pilha esta vazia
    // pilha.clear();     // remove todos os elementos da pilha
    //DEL!
    while(!pilhaA.empty()) {
        int n = pilhaA.top();
        pilhaA.pop();
        pilhaB.push(n);
    }

    while(!pilhaB.empty()) {
        int n = pilhaB.top();
        pilhaB.pop();
        pilhaC.push(n);
    }

    while(!pilhaC.empty()) {
        int n = pilhaC.top();
        pilhaC.pop();
        pilhaA.push(n);
    }
    //ACT!
    // (void) pilhaA;
    // (void) pilhaB;
    // (void) pilhaC;
    //ADD!

}
// Exemplo:
// pilhaA: [10,20,30,40]
// pilhaB: []
// pilhaC: []
// invertStack(pilhaA, pilhaB, pilhaC)
// pilhaA: [40,30,20,10]
// pilhaB: []
// pilhaC: []


void printStackRec(stack<int> &pilha){
    if(!pilha.empty()){
        int el = pilha.top();
        pilha.pop();
        printStackRec(pilha);
        std::cout << el << " ";
    }
}

void printStack(stack<int> pilha){
    std::cout << "Pilha: [ ";
    printStackRec(pilha);
    std::cout << "]" << std::endl;
}

int main(){
    int n;
    stack<int> pilha;

    std::cin >> n;
    for(int i = 0; i < n; i++){
        int el;
        std::cin >> el;
        pilha.push(el);
    }

    stack<int> pb, pc;
    printStack(pilha);
    std::cout << "invert" << std::endl; invertStack(pilha, pb, pc);
    printStack(pilha);
}
