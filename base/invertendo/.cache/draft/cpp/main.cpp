// Arquivo de execucao //
// Altere somente as funcoes com TODO //

#include <iostream>

struct Node {
    std::string info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista
    Node *previous; // Ponteiro para o elemento anterior da lista

    Node(std::string info, Node *next, Node *previous){
        this->info = info;
        this->next = next;
        this->previous = previous;
    };
};

void printNodes(Node* head){
    std::cout << "[ ";
    Node* temp = head;
    while(temp != nullptr){
        std::cout << temp->info << " ";
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

// Altere essa funcao.
// Inverte a ordem dos elementos de uma lista, alterando
// os valores de 'next' e 'previous' de cada No.
void invert(Node* head){
    // TODO
    (void) head;
}
// Exemplo:
// L == "1" <-> "2" <-> "4" <-> "8" <-> "16"
// invert(L)
// L == "16" <-> "8" <-> "4" <-> "2" <-> "1"

int main(){
    /*    TESTE 1   */
    Node *node1 = new Node("azul", nullptr, nullptr);
    Node *node2 = new Node("branco", nullptr, nullptr);
    Node *node3 = new Node("cinza", nullptr, nullptr);
    Node *node4 = new Node("dourado", nullptr, nullptr);
    Node *node5 = new Node("escarlate", nullptr, nullptr);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node2->previous = node1;
    node3->previous = node2;
    node4->previous = node3;
    node5->previous = node4;

    printNodes(node1);
    invert(node1);
    printNodes(node5);
    invert(node5);
    printNodes(node1);
    invert(node1);
    printNodes(node5);
}
