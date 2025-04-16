#include <iostream>

// Node: classe utilizada para representar um No
// NAO ALTERE ESSA CLASSE
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(); // Construtor
    Node(int info, Node *next = nullptr); // Construtor
    
    ~Node(); // Destrutor
};

// Queue ou Pilha
// Altere somente os campos marcados com TODO
struct LinkedQueue {
    Node *front; // Ponteiro para a cabeca da lista (primeiro No)
    Node *back;  // Ponteiro para a cauda da lista (ultimo No)
    int size;    // Quantidade de elementos da fila (salvar esse valor permite sua consulta em O(1))

    LinkedQueue() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    ~LinkedQueue(){
        clear();
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


    // Retorna a informacao do elemento na frente da fila.
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
        return front == nullptr;
    }


    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = front; node != NULL; node = node->next){
            std::cout << node->info;
            if(node->next != NULL)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};
