//lib.hpp
#pragma once
#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

struct LinkedList{
    Node * head {nullptr};

    //================================================================
    // Esses métodos são pra você implementar no arquivo .cpp
    //================================================================
    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    void clear();
    int  size() const;

    //================================================================
    // Os métodos abaixo já estão implementados no fim desse header
    //================================================================
    LinkedList() = default; // implementação padrão
    ~LinkedList();          // destrutor
    std::string str() const;// toString
};

// destrutor padrão
inline LinkedList::~LinkedList() {
    this->clear();
}

// gera a string da lista
inline std::string LinkedList::str() const {
    if (this->head == nullptr) {
        return "[]";
    }
    std::stringstream ss;
    Node * node = this->head;
    while(node != nullptr) {
        ss << ", " << node->value;
        node = node->next;
    }
    return "[" + ss.str().substr(2) + "]"; //retira primeiro ", "
}

// sobrecarga que permite enviar a lista diretamente para ostream
// std::cout << lista;
inline ostream& operator<<(ostream& os, const LinkedList& lista) {
    return (os << lista.str());
}
