//tk main.cpp
#include "lib.hpp"
#include <iostream>
#include <functional>

template <typename T>
using def = std::function<T>;

void LinkedList::push_back(int value) {

    def <Node* (Node*, int)>
    fn = [&fn](Node * node, int value) {
        if(node == nullptr)
            return new Node(value);
        node->next = fn(node->next, value);
        return node;
    };


    this->head = fn(this->head, value);
}

void LinkedList::push_front(int value) {
    if(this->head == nullptr)
        this->head = new Node(value);
    else
        this->head = new Node(value, this->head);
}



void LinkedList::pop_back() {
    def <Node* (Node*)> _pop_back = [&](Node * node) -> Node *{
        if(node == nullptr)
            return nullptr;
        if(node->next == nullptr) {
            delete node;
            return nullptr;
        }
        node->next = _pop_back(node->next);
        return node;
    };

    this->head = (this->head);
}
void LinkedList::pop_front() {
    if(head == nullptr)
        return;
    Node * node = head;
    head = head->next;
    delete node;
}

int  LinkedList::size() {
    Node * node = head;
    int cont = 0;
    while(node != nullptr) {
        cont += 1;
        node = node->next;
    }
    return cont;
}