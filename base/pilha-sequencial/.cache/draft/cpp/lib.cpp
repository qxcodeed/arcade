#include <iostream>

// Stack ou Pilha
// Altere somente os campos marcados com TODO
struct Stack {
    int size;  // Quantidade de elementos da pilha
    int capacity;  // Quantidade máxima de elementos permitidos dentro da pilha
    int *Arr; // Ponteiro para array de elementos onde salvamos as informacoes do usuario

    Stack(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->Arr = new int[this->capacity];
    }

    ~Stack() {
        delete[] Arr;
    }

    // Adiciona um elemento no topo da pilha
    // info: informacao do elemento a ser inserido
    void push(int info) {
        // TODO
        //DEL!
        if(this->full()) return;
        this->Arr[this->size] = info;
        this->size++;
        //ACT!
        // (void) info;
        //ADD!
    }


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void pop() {
        // TODO
        //DEL!
        if(this->empty()) return;
        this->size--;
        //ADD!
    }


    // Retorna a informacao do elemento no topo da pilha.
    // Retorna -1, caso a pilha esteja vazia.
    int peek() {
        // TODO
        //DEL!
        if(this->empty()) return -1;
        return this->Arr[this->size-1];
        //ACT!
        // return -1;
        //ADD!
    }


    // Remove todos os elementos da pilha
    void clear() {
        // TODO
        //DEL!
        while(!this->empty()){
            this->pop();
        }
        //ADD!
    }


    // Devolve true se cheia e false caso contrario
    bool empty() {
        // TODO
        //DEL!
        return this->size == 0;
        //ACT!
        // return false;
        //ADD!
    }

    // Devolve true se vazia e false caso contrario
    bool full() {
        // TODO
        //DEL!
        return this->size == this->capacity;
        //ACT!
        // return false;
        //ADD!
    } 

    // Printa as informacoes da lista
    void print() {
        std::cout << "[";
        for(int i = 0; i < this->size; i++) {
            std::cout << this->Arr[i];
            if(i < this->size-1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }    
};

