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
        //DEL!
        if(this->full()) return;

        int back = (this->front + this->size) % this->capacity;
        this->Arr[back] = info;
        this->size++;
        //ACT!
        // (void) info;
        //ADD!
    }


    // Remove um elemento do topo da fila.
    // Nao faz nada caso a fila esteja vazia.
    void pop(){
        // TODO
        //DEL!
        if(this->empty()) return;

        this->front = (this->front + 1) % this->capacity;
        this->size--;
        //ADD!
    }


    // Retorna a informacao do elemento no topo da fila.
    // Retorna -1, caso a fila esteja vazia.
    int peek(){
        // TODO
        //DEL!
        if(this->empty()) return -1;

        return this->Arr[this->front];
        //ACT!
        // return -1;
        //ADD!
    }


    // Remove todos os elementos da fila
    void clear(){
        // TODO
        //DEL!
        while(!this->empty())
            this->pop();
        //ADD!
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        // TODO
        //DEL!
        return this->size == 0;
        //ACT!
        // return false;
        //ADD!
    }

    // Devolve true se vazia e false caso contrario
    bool full(){
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
        for(int i = 0; i < size; i++) {
            std::cout << Arr[(front+i)%capacity];
            if(i < size-1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }    
};

