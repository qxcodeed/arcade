#include <iostream>

// SequentialQueue ou Pilha Sequencial
// Altere somente os campos marcados com TODO
struct SequentialQueue {
    int front;     // Indice do elemento na frente da fila
    int size;      // Quantidade de elementos da fila
    int capacity;  // Quantidade máxima de elementos permitidos dentro da fila
    int *Arr;      // Ponteiro para array de elementos onde salvamos as informacoes do usuario

    SequentialQueue(int capacity) {
        size = 0;
        front = 0;
        this->capacity = capacity;
        Arr = new int[capacity];
    }

    ~SequentialQueue() {
        delete[] Arr;
    }


    // Adiciona um elemento no topo da fila
    // info: informacao do elemento a ser inserido
    void push(int info) {
        // TODO
        (void) info;
    }


    // Remove um elemento do topo da fila.
    // Nao faz nada caso a fila esteja vazia.
    void pop(){
        // TODO
    }


    // Retorna a informacao do elemento no topo da fila.
    // Retorna -1, caso a fila esteja vazia.
    int peek(){
        // TODO
        return -1;
    }


    // Remove todos os elementos da fila
    void clear(){
        // TODO
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        // TODO
        return false;
    }

    // Devolve true se vazia e false caso contrario
    bool full(){
        // TODO
        return false;
    }

    // Printa as informacoes da lista
    void print() {
        std::cout << "[";
        for(int i = 0; i < size; i++) {
            std::cout << Arr[(front+i)%capacity];
            if(i < size-1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }    
};
