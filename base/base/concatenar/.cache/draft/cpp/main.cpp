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

void printNodesFromHead(Node* current){
    if(current == nullptr) return;

    std::cout << current->info << " ";
    printNodesFromHead(current->next);
}

void printNodesFromTail(Node* current){
    if(current == nullptr) return;

    printNodesFromTail(current->previous);
    std::cout << current->info << " ";
}


// Altere essa funcao.
// Concatena a lista A com a lista B através de seus
// ponteiros 'headA' e 'headB'.
// Apos essa operacao, todos os Nos de B sao adicionados
// apos o final da lista A.
// Pode assumir que nenhuma das duas listas esta vazia
void concatenate(Node *headA, Node *headB){
    // TODO
    (void) headA;
    (void) headB;
}
// Exemplo:
// LA == "A" <-> "B" <-> "C"
// LB == "D" <-> "E" <-> "F"
// concatenate(LA, LB)
// LA == "A" <-> "B" <-> "C" <-> "D" <-> "E" <-> "F"

int main(){
    /*    TESTE 1   */
    // Lista A //
    Node *nodeA1 = new Node("uno", nullptr, nullptr);
    Node *nodeA2 = new Node("dos", nullptr, nullptr);
    Node *nodeA3 = new Node("tres", nullptr, nullptr);

    nodeA1->next = nodeA2;
    nodeA2->next = nodeA3;
    nodeA3->next = nullptr;

    nodeA1->previous = nullptr;
    nodeA2->previous = nodeA1;
    nodeA3->previous = nodeA2;

    std::cout << "Lista A: "; printNodesFromHead(nodeA1); std::cout << std::endl;

    // lista B //

    Node *nodeB1 = new Node("cuatro", nullptr, nullptr);
    Node *nodeB2 = new Node("cinco", nullptr, nullptr);
    Node *nodeB3 = new Node("seis", nullptr, nullptr);
    Node *nodeB4 = new Node("siete", nullptr, nullptr);

    nodeB1->next = nodeB2;
    nodeB2->next = nodeB3;
    nodeB3->next = nodeB4;
    nodeB4->next = nullptr;

    nodeB1->previous = nullptr;
    nodeB2->previous = nodeB1;
    nodeB3->previous = nodeB2;
    nodeB4->previous = nodeB3;

    std::cout << "Lista B: "; printNodesFromHead(nodeB1); std::cout << std::endl;

    std::cout << "Concatena Lista A e Lista B" << std::endl;
    concatenate(nodeA1, nodeB1);
    std::cout << "Lista A (head): "; printNodesFromHead(nodeA1); std::cout << std::endl;
    std::cout << "Lista A (tail): "; printNodesFromTail(nodeB4); std::cout << std::endl;
}
