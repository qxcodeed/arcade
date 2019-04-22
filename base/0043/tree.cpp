#include <memory> //shared_ptr
#include <iostream>
using namespace std;

struct Node{
    int value;
    shared_ptr<Node> next;
    weak_ptr<Node> prev;
    Node(int value = 0){
        cout << "nascendo " << value << "\n";
        this->value = value;
    }
    virtual ~Node(){
        cout << "morrendo " << value << "\n";
    }
};

struct List{
    shared_ptr<Node> head;
    shared_ptr<Node> tail;

    List(){
        head = make_shared<Node>(-1);
        tail = make_shared<Node>(-2);
        head->next = tail;
        tail->prev = head;
    }
    ~List(){

    }

    void insert(shared_ptr<Node>& node, int value){
        auto novo = make_shared<Node>(value);
        novo->next = node;
        novo->prev = node->prev;
        novo->prev.lock()->next = novo;
        node->prev = novo;
    }

    void remove(int value){
        for(auto node = head->next; node != tail; node = node->next){
            if(node->value == value){
                node->prev.lock()->next = node->next;
                node->next->prev = node->prev;
                return;
            }
        }
    }

};

int main(){
    List lista;
    for(int i = 0; i < 10; i++)
        lista.insert(lista.tail, i);

    for(auto node = lista.head->next; node != lista.tail; node = node->next){
        cout << node->value << " ";
    }

    lista.remove(5);
}