/*       QUESTIONARIO (RESPONDA COM HONESTIDADE)

Q1 - Voce resolveu esse problema em grupo? Se sim, indique com quem fez.



Q2 - Quanto tempo você demorou para resolve-lo?



Q3 - Voce considera o problema facil, medio ou dificil? Qual maior dificuldade encontrada?



*/

/*       ATIVIDADE        */
#include <iostream>

// Node: classe utilizada para representar um No
// Nao altere essa classe
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(); // Construtor
    Node(int info, Node *next=nullptr); // Construtor
    ~Node(); // Destrutor
};

// Singly Linked List ou
// Lista Simplesmente Encadeada
// Altere somente os campos marcados com TODO
struct SLinkedList {
    Node *head;   // Ponteiro para a cabeca da lista (primeiro No)

    SLinkedList(){
    }

    ~SLinkedList(){ // Destrutor
        // TODO
        // dica: implemente o metodo clear e apenas o chame
    }

    // Retorna true se uma informacao pertence a lista, false caso contrario
    // index: posicao do elemento
    bool hasInfo(int info){
        // TODO: Complexidade O(n)

    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.hasInfo(20) == true
    // L.hasInfo(100) == false

    // Retorna a informacao dada uma posicao
    // index: posicao do elemento
    int get(int index){
        // TODO: Complexidade O(n)
        
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.get(0) == 10
    // L.get(1) == 20
    // L.get(2) == 15


    // operador[] sobrecarregado. Retorna a 
    // informacao do elemento na posicao 'index'
    int operator[](int index){
        return get(index);
    }


    // Adiciona um elemento no inicio da lista
    // info: informacao do elemento a ser inserido
    void push_front(int info){
        Node* newNode = new Node(info, nullptr);
        newNode->next = head;
        head = newNode;
        // Ou simplesmente
        // head = new Node(info, head);
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 30 -> 10 -> 20 -> 15 -> 50


    // Adiciona um elemento ao final da lista
    // info: informacao do elemento a ser inserido
    void push_back(int info){
        // TODO: Complexidade O(n)
        

        (void) info;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 10 -> 20 -> 15 -> 50 -> 30


    // Remove o primeiro elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_front(){
        // TODO: Complexidade O(1)
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_front()
    // L == 20 -> 15 -> 50


    // Remove o ultimo elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_back(){
        // TODO: Complexidade O(n)
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_back()
    // L == 10 -> 20 -> 15


    // Deixa a lista vazia, com zero elementos
    void clear(){
        // TODO: Complexidade O(n)
        // dica: voce pode usar os metodos pop_front e empty
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.clear()
    // L == []


    // Retorna o numero de elementos da lista
    int length(){
        // TODO: Complexidade O(n)

    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.length() == 4


    // Devolve true se cheia e false caso contrario
    bool empty(){
        // TODO

        return false;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.empty() == false
    // L == ''
    // L.empty() == true


    // Dado um no, retorna o proximo no da lista
    // Retorna NULL caso nao exista
    Node* successor(Node* node){
        return node->next;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.successor(No 20) == No 15
    // L.successor(No 50) == NULL


    // Dado um No, retorna o proximo No da lista
    // Retorna NULL caso nao exista
    Node* predecessor(Node* node){
        // TODO: complexidade O(n)
        //--
        if(node == head){
            return nullptr;
        }
        for(Node* n = head; n != nullptr; n = n->next){
            if(n->next == node){
                return n;
            }
        }
        return nullptr;
        (void) node;
        return nullptr;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.predecessor([20]) == [10]
    // L.predecessor([10]) == NULL

    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = head; node != nullptr; node = node->next){
            std::cout << node->info;
            if(node->next != nullptr)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};