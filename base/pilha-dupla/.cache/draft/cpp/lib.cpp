#include <iostream>
#include <stack>

// Pilha Dupla
// Classe implementa duas pilhas sequenciais A e B que
// compartilham o mesmo Array de elementos
// Altere somente os campos marcados com "TODO"
struct DoubleStack {
    int sizeA;  // Quantidade de elementos da pilha A
    int sizeB;  // Quantidade de elementos da pilha B
    int capacity;  // Quantidade máxima de elementos permitidos dentro da pilha
    int *Arr; // Array onde sao salvas ambas informacoes da pilha A e pilha B

    DoubleStack(int capacity){
        sizeA = 0;
        sizeB = 0;
        this->capacity = capacity;
        Arr = new int[capacity];
    }

    ~DoubleStack() {
        delete[] Arr;
    }


    bool full() {
        return sizeA + sizeB == capacity;
    }

    ////              PILHA A             ////

    // Adiciona um elemento no topo da pilha A.
    // Nao faz nada caso a pilha esteja cheia.
    // info: informacao do elemento a ser inserido
    void pushA(int info) {
        if(!full()) {
            Arr[sizeA] = info;
            sizeA++;
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // pushA(10)
    // Pilha A:[1,2,3,10]
    // Pilha B:[4,5]


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void popA() {
        // TODO: Complexidade O(1)
        //DEL!
        if(this->emptyA()) return;
        this->sizeA--;
        //ADD!
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // popA()
    // Pilha A:[1,2]
    // Pilha B:[4,5]


    // Retorna a informacao do elemento no topo da pilha A.
    // Retorna -1, caso a pilha A esteja vazia.
    int peekA() {
        // TODO: Complexidade O(1)
        //DEL!
        if(this->emptyA()) return -1;
        return this->Arr[this->sizeA-1];
        //ACT!
        // return -1;
        //ADD!

    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // peekA() == 3


    // Remove todos os elementos da pilha
    void clearA() {
        // TODO: Complexidade O(1)
        //DEL!
        this->sizeA = 0;
        //ADD!
    }
    // Exemplo:
    // Pilha A:[]
    // Pilha B:[4,5]
    // peekA() == 3


    // Devolve true se vazia e false caso contrario
    bool emptyA() {
        // TODO: Complexidade O(1)
        //DEL!
        return this->sizeA == 0;
        //ACT!
        // return false;
        //ADD!
    }
    // Exemplo:
    // Pilha A:[]
    // Pilha B:[4,5]
    // emptyA() == true


    // Devolve true se cheia e false caso contrario
    // Considere o tamanho da Pilha A e Pilha B

    ///        PILHA B        ///

    // Adiciona um elemento no topo da pilha A.
    // Nao faz nada caso a pilha esteja cheia.
    // info: informacao do elemento a ser inserido
    void pushB(int info) {
        // TODO: Complexidade O(1)
        //DEL!
        if(!this->full()) {
            this->Arr[this->capacity - this->sizeB - 1] = info;
            this->sizeB++;
        }
        //ACT!
        // (void) info;
        //ADD!
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // pushB(10)
    // Pilha A:[1,2,3]
    // Pilha B:[4,5,10]


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void popB() {
        // TODO: Complexidade O(1)
        //DEL!
        if(!this->emptyB()){
            this->sizeB--;
        }
        //ADD!

    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // popB()
    // Pilha A:[1,2,3]
    // Pilha B:[4]


    // Retorna a informacao do elemento no topo da pilha A.
    // Retorna -1, caso a pilha A esteja vazia.
    int peekB() {
        // TODO: Complexidade O(1)
        //DEL!
        if (this->emptyB()) return -1;
        return this->Arr[this->capacity - this->sizeB];
        //ACT!
        // return -1;
        //ADD!
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // peekB() == 5


    // Remove todos os elementos da pilha
    void clearB() {
        // TODO: Complexidade O(1)
        //DEL!
        this->sizeB = 0;
        //ADD!
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // clearB()
    // Pilha A:[1,2,3]
    // Pilha B:[]


    // Devolve true se vazia e false caso contrario
    bool emptyB() {
        // TODO: Complexidade O(1)
        //DEL!
        return this->sizeB == 0;
        //ACT!
        // return false;
        //ADD!
    }


    // Printa as informacoes da lista
    void print() {
        std::cout << "Pilha A: [";
        for (int i = 0; i < sizeA; i++) {
            std::cout << Arr[i];
            if (i < sizeA - 1) std::cout << ", ";
        }
        std::cout << "]\n";

        std::cout << "Pilha B: [";
        for (int i = capacity - 1; i >= capacity - sizeB; i--) {
            std::cout << Arr[i];
            if (i > capacity - sizeB) std::cout << ", ";
        }
        std::cout << "]\n";
    }


};

