#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node * next;
    int value;
};

struct List{
    Node * head;
};

Node * list_push_front(Node * head, int value){
    Node * node = new Node();
    node->value = value;
    node->next = head;
    return node;
}


List * list_create();

void   list_show(List * ll);

int main(){
    List * ll = list_create();
    int size;
    cin >> size;
    while(size--){
        int value;
        cin >> value;
        ll->head = list_push_front(ll->head, value);
    }
    list_show(ll);
}

List * list_create(){
    List * ll = new List();
    ll->head = nullptr;
    return ll;
}

void list_show(List * ll){
    Node * node = ll->head;
    cout << "[ ";
    while(node != nullptr){
        cout << node->value << " ";
        node = node->next;
    }
    cout << "]\n";
}
