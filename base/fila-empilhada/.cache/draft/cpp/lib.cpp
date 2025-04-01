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
        //DEL!
        this->stack.push(info);
        //ACT!
        // (void) info;
        //ADD!
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
        //DEL!
        while(!this->stack.empty()) {
            aux.push(this->stack.top());
            this->stack.pop();
        }

        aux.pop();

        while(!aux.empty()) {
            this->stack.push(aux.top());
            aux.pop();
        }
        //ADD!
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
        //DEL!
        while(!this->stack.empty()) {
            aux.push(this->stack.top());
            this->stack.pop();
        }

        int top = aux.top();

        while(!aux.empty()) {
            this->stack.push(aux.top());
            aux.pop();
        }

        return top;
        //ACT!
        // return -1;
        //ADD!
    }


    // Remove todos os elementos da fila
    void clear() {
        // TODO: complexidade O(n)
        //DEL!
        while(!this->stack.empty()) {
            this->stack.pop();
        }
        //ADD!
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

