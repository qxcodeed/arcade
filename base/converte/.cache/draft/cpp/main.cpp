// Arquivo de execucao //
// Altere somente as funcoes com TODO //

#include <iostream>

namespace SLinkedList{
    // No de uma lista simplesmente encadeada 
    // Nao altere essa struct
    struct Node {
        std::string info; // Informacao salva pelo usuario na lista
        Node *next; // Ponteiro para o proximo elemento da lista

        Node(std::string info, Node *next){
            this->info = info;
            this->next = next;
        };

        void print(){
            std::cout << info;
            if(this->next != nullptr){
                std::cout << " -> ";
                this->next->print();
            }else{
                std::cout << std::endl;
            }
        }
    };
}

namespace DLinkedList{
    // No de uma lista encadeada dupla
    // Nao altere essa struct
    struct Node {
        std::string info; // Informacao salva pelo usuario na lista
        Node *next; // Ponteiro para o proximo elemento da lista
        Node *previous; // Ponteiro para o elemento anterior da lista

        Node(std::string info, Node *next, Node *previous){
            this->info = info;
            this->next = next;
            this->previous = previous;
        };

        void print(){
            std::cout << info;
            if(this->next != nullptr){
                std::string arrow;
                if(this->next->previous != this ){
                    std::cout << "Ponteiro 'previous' incorreto" << std::endl;
                    return;
                }
                std::cout << " <-> ";
                this->next->print();
            }
            else std::cout << std::endl;
        }
    };
}

// Altere a seguinte funcao:
// Dada uma lista simplesmente encadeada,
// essa funcao faz uma cópia dessa lista,
// mas convertendo-a para uma lista duplamente encadeada.
// A funcao deve retornar um ponteiro para o No cabeca da lista dupla.
//
// OBS: parte da funcao esta implementada, altere o caso com TODO
// OBS: nao e necessario apagar os Nos da lista original
DLinkedList::Node* convertToDouble(SLinkedList::Node *head){
    if(head == nullptr){ // Lista vazia
        return nullptr;
    }else if(head->next == nullptr){ // Lista com apenas um No
        DLinkedList::Node* newHead = new DLinkedList::Node(head->info, nullptr, nullptr);
        return newHead;
    } else { // lista com mais de um No
        // TODO: complete a funcao aqui
        return new DLinkedList::Node("", nullptr, nullptr);
    }
}
// Exemplo:
// L_simples == "A" -> "B" -> "C"
// L_dupla = convertToDouble(L_simples)
// L_dupla == "A" <-> "B" <-> "C"

int main(){
    /*    TESTE 1   */
    // Lista A //
    SLinkedList::Node *sNode1 = new SLinkedList::Node("A", nullptr);
    SLinkedList::Node *sNode2 = new SLinkedList::Node("B", nullptr);
    SLinkedList::Node *sNode3 = new SLinkedList::Node("C", nullptr);
    SLinkedList::Node *sNode4 = new SLinkedList::Node("D", nullptr);

    sNode1->next = sNode2;
    sNode2->next = sNode3;
    sNode3->next = sNode4;
    sNode4->next = nullptr;

    std::cout << "Lista simplesmente ligada: "; sNode1->print();

    DLinkedList::Node *dNode = convertToDouble(sNode1);
    std::cout << "Lista duplamente ligada: "; dNode->print();
}
