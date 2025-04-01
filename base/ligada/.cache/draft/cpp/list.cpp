#include "list.hpp"
#include <iostream>

//DEL!
Node* __push_back(Node * node, int value) {
    if(node == nullptr)
        return new Node(value);
    node->next = __push_back(node->next, value);
    return node;
}

// método recursivo invocado pelo clear
void __clear(Node * node) {
    if (node == nullptr) {
        return;
    }
    __clear(node->next);
    delete(node);
}

Node * __pop_back(Node * node) {
    if(node == nullptr)
        return nullptr;
    if(node->next == nullptr) {
        delete node;
        return nullptr;
    }
    node->next = __pop_back(node->next);
    return node;
}

//ADD!
void LinkedList::clear() {
    //DEL!
    __clear(this->head);
    this->head = nullptr;
}

void LinkedList::push_back(int value) {
    //DEL!
    this->head = __push_back(this->head, value);
    //ACT!
    // (void) value;
}

void LinkedList::push_front(int value) {
    //DEL!
    if(this->head == nullptr) {
        this->head = new Node(value);
    } else {
        this->head = new Node(value, this->head);
    }
    //ACT!
    // (void) value;
}

void LinkedList::pop_back() {
    //DEL!
    this->head = __pop_back(this->head);
}


void LinkedList::pop_front() {
    //DEL!
    if(head == nullptr) {
        return;
    }
    Node * node = head;
    head = head->next;
    delete node;
}


int  LinkedList::size() const {
    //DEL!
    Node * node = head;
    int cont = 0;
    while(node != nullptr) {
        cont += 1;
        node = node->next;
    }
    return cont;
    //ACT!
    // return 0;
}
