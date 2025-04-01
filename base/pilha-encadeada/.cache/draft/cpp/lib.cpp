#include <iostream>

// Node: classe utilizada para representar um No
// NAO ALTERE ESSA CLASSE
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(); // Construtor
    Node(int info, Node *next=nullptr); // Construtor
    
    ~Node(); // Destrutor
};

// Stack ou Pilha
// Altere somente os campos marcados com TODO
struct Stack {
    Node *top; // Ponteiro para a cabeca da lista (primeiro No)
    int size;  // Quantidade de elementos da pilha (salvar esse valor permite sua consulta em O(1))

    Stack(){
        top = nullptr;
        size = 0;
    }

    ~Stack(){
        clear();
    }


    // Adiciona um elemento no topo da pilha
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO
        //DEL!
        Node* newNode = new Node(info, this->top);
        this->top = newNode;
        this->size++;
        //ACT!
        // (void) info;
        //ADD!
    }


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void pop(){
        // TODO
        //DEL!
        if(this->empty()) return;
        Node* node = this->top;
        this->top = this->top->next;
        delete node;
        this->size--;
        //ADD!
    }


    // Retorna a informacao do elemento no topo da pilha.
    // Retorna -1, caso a pilha esteja vazia.
    int peek(){
        // TODO
        //DEL!
        if(this->empty()) return -1;
        return this->top->info;
        //ACT!
        // return -1;
        //ADD!
    }


    // Remove todos os elementos da pilha
    void clear(){
        // TODO
        //DEL!
        while(!this->empty()){
            this->pop();
        }
        //ADD!
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        return top == nullptr;
    }


    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = top; node != nullptr; node = node->next){
            std::cout << node->info;
            if(node->next != nullptr)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};

