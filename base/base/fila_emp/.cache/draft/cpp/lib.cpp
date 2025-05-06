#include <iostream>
#include <queue>
#include <stack>

// Stacked ou Fila empilhada
// Altere somente os campos marcados com TODO
struct StackedQueue {
    std::stack<int> stack;     // Pilha para salvar elementos

    StackedQueue(){}

    // Adiciona um elemento no topo da fila
    // info: informacao do elemento a ser inserido
    void push(int info) {
        // TODO: complexidade O(1)
        // Utilize somente a pilha 'stack'
        (void) info;
    }


    // Remove um elemento do topo da fila.
    // Nao faz nada caso a fila esteja vazia.
    void pop() {
        if(stack.empty()) {
            return;
        }
        std::stack<int> aux; // Pilha auxiliar para acessar o elemento do 'fundo' da pilha
        // TODO: complexidade O(n)
        // Utilize a pilha 'stack' e a pilha 'aux'
    }


    // Retorna a informacao do elemento na frente da fila.
    // Retorna -1, caso a fila esteja vazia.
    int peek() {
        if(stack.empty()) { // caso base fila vazia
            return -1;
        }
        std::stack<int> aux; // Pilha auxiliar para acessar o elemento do 'fundo' da pilha
        // TODO: complexidade O(n)
        // Utilize a pilha 'stack' e a pilha 'aux'
        return -1;
    }


    // Remove todos os elementos da fila
    void clear() {
        // TODO: complexidade O(n)
    }


    // Devolve true se cheia e false caso contrario
    bool empty() {
        return stack.empty();
    }

    // Printa as informacoes da lista
    void print() {
        std::queue<int> q;

        while(!empty()) {
            q.push(peek());
            pop();
        }

        std::cout << "[";
        while(!q.empty()) {
            std::cout << q.front();
            push(q.front());
            q.pop();
            if(!q.empty()) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }    
};
