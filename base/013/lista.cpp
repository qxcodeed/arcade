#include <iostream>
#include <list>
using namespace std;


struct Node{
    int value;
    Node * next;
    Node * prev;
    Node(int value, Node * next, Node * prev){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

struct Lista{
    Node * ref;
    Lista(){
        ref = new Node(0, nullptr, nullptr);
        ref->next = ref;
        ref->prev = ref;
    }

    Node * goNext(Node * node){
        if(node == ref)
            return ref;
        if(node->next == ref)
            return ref->next;
        return node->next;
    }

    void show(Node * sword){
        cout << "[";
        Node * node = ref->next;
        while(node != ref){
            cout << " " << node->value;
            if(node == sword)
                cout << ">";
        }
        cout << " ]\n";
    }
};





int main(){
    int qtd = 0;
    int esc = 0;
    cin >> qtd >> esc; 
    list<int> lista;
    for(int i = 1; i <= qtd; i++)
        lista.push_back(i);

    auto it = lista.begin();
    std::advance(it, esc - 1);
    
    while(lista.size() > 1){
        show(lista, it);
        it++;
        if(it == lista.end()) it = lista.begin();
        it = lista.erase(it);
        if(it == lista.end()) it = lista.begin();
    }
    show(lista, it);
}
