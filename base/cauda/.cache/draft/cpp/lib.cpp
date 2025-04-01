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
    Node *tail;   // Ponteiro para a cauda da lista (ultimo No)

    SLinkedList(){
        head = tail = nullptr;
    }

    ~SLinkedList(){ // Destrutor
        clear();
    }

    // Retorna true se uma informacao pertence a lista
    // index: posicao do elemento
    bool hasInfo(int info){
        // TODO: Complexidade O(n)
        //DEL!
        for(Node* node = head; node != nullptr; node = node->next){
            if(node->info == info)
                return true;
        }
        return false;

        //ACT!
        // (void) info;
        // return false;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.hasInfo(20) == true
    // L.hasInfo(100) == false

    // Adiciona um elemento no inicio da lista
    // info: informacao do elemento a ser inserido
    void push_front(int info){
        // TODO: Complexidade O(1)
        //DEL!
        if(head == nullptr){ // lista vazia
            head = tail = new Node(info, head);
        }else{
            head = new Node(info, head);
        }

        //ACT!
        // (void) info;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 30 -> 10 -> 20 -> 15 -> 50


    // Adiciona um elemento ao final da lista
    // info: informacao do elemento a ser inserido
    void push_back(int info){
        // TODO: Complexidade O(1)
        //DEL!
        if(head == nullptr){ // lista vazia
            head = tail = new Node(info, head);
        }else{
            tail->next = new Node(info);
            tail = tail->next;
        }

        //ACT!
        // (void) info;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 10 -> 20 -> 15 -> 50 -> 30


    // Remove o primeiro elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_front(){
        // TODO: Complexidade O(1)
        //DEL!
        if(head == nullptr) return;
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_front()
    // L == 20 -> 15 -> 50


    // Remove o ultimo elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_back(){
        // TODO: Complexidade O(n)
        //DEL!
        if(head == nullptr) return;
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_back()
    // L == 10 -> 20 -> 15


    // Deixa a lista vazia, com zero elementos
    void clear(){
        while(!empty()){
            pop_back();
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.clear()
    // L == []

    // Retorna o numero de elementos da lista
    int length(){
        int count = 0;
        for(Node* node = head; node != nullptr; node = node->next){
            count++;
        }
        return count;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.length() == 4

    // Devolve true se cheia e false caso contrario
    bool empty(){
        return head == nullptr;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.empty() == false
    // L == ''
    // L.empty() == true


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

