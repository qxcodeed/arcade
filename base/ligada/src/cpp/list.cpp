#include "list.hpp"
#include <iostream>

// --
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

// ++
void LinkedList::clear() {
    __clear(this->head);
    this->head = nullptr;
}

void LinkedList::push_back(int value) {
    this->head = __push_back(this->head, value);
    // $$
    // (void) value;
}

void LinkedList::push_front(int value) {
    if(this->head == nullptr) {
        this->head = new Node(value);
    } else {
        this->head = new Node(value, this->head);
    }
    // $$
    // (void) value;
}


// ++
void LinkedList::pop_back() {
    this->head = __pop_back(this->head);
}


void LinkedList::pop_front() {
    if(head == nullptr) {
        return;
    }
    Node * node = head;
    head = head->next;
    delete node;
}


int  LinkedList::size() const {
    Node * node = head;
    int cont = 0;
    while(node != nullptr) {
        cont += 1;
        node = node->next;
    }
    return cont;
    // $$
    // return 0;
}