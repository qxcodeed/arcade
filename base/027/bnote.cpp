#include <iostream>
#include <list>
using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr):
        value(value), next(next){
    }
};

Node * node_push_back(Node * node, int value){
    if(node == nullptr)
        return new Node(value);
    node->next = node_push_back(node->next, value);
    return node;
}

Node * node_push_front(Node * node, int value){
    return new Node(value, node);
}


void node_destroy(Node * node){
    if(node == nullptr)
        return;
    node_destroy(node->next);
    delete(node);
}

Node * node_clone(Node * node){
    if(node == nullptr)
        return nullptr;
    return new Node(node->value, node_clone(node->next));
}

struct BigNumber{
    Node * data {nullptr};

    BigNumber& operator=(const BigNumber &other){
        if (this == &other)
            return *this;
        node_destroy(this->data);
        this->data = node_clone(other.data);
        return *this; 
    }

    BigNumber(const BigNumber &other){
        *this = other;
    }

    BigNumber(string value = ""){
        for(int i = value.size() - 1; i >= 0; i--)
            data = node_push_back(data, value[i] - '0');
    }

    ~BigNumber(){
        node_destroy(data);
    }

    int soma(Node * one, Node * two) const{
        int sum = 0;
        if(one != nullptr)
            sum += one->value;
        if(two != nullptr)
            sum += two->value;
        return sum;
    }

    Node * next(Node * node) const {
        if(node == nullptr)
            return nullptr;
        return node->next;
    }

    BigNumber operator+(BigNumber &other) const{
        Node * one = data;      
        Node * two = other.data;
        BigNumber bg;
        int carry = 0;
        for(; one != nullptr || two != nullptr || carry != 0; one = next(one), two = next(two)){
            int value = soma(one, two) + carry;
            bg.data = node_push_back(bg.data, value % 10);
            carry = value / 10;
        }
        return bg;
    }

    int getValue(Node * node) const {
        if(node == nullptr)
            return 0;
        return node->value;
    }

    BigNumber operator*(int num) const{
        BigNumber bg;
        int carry = 0;
        for(Node * one = data; one != nullptr || carry != 0; one = next(one)){
            int value = getValue(one) * num + carry;
            bg.data = node_push_back(bg.data, value % 10);
            carry = value / 10;
        }
        if(carry != 0)
            bg.data = node_push_back(bg.data, carry);
        return bg;
    }

    BigNumber& addZeros(int qtd){
        for(int i = 0; i < qtd; i++)
            this->data = new Node(0, this->data);
        return *this;
    }

    BigNumber operator*(BigNumber &other) const{   
        BigNumber final;
        int casa = 0;
        for(Node * two = other.data; two != nullptr; two = next(two), casa += 1){
            BigNumber parcial = *this * two->value;
            final = final + parcial.addZeros(casa);
        }
        return final;
    }

    friend ostream& operator<<(ostream &os, const BigNumber& bn) {
        Node * node = bn.data;
        list<int> result; //invertendo lista
        while(node != nullptr){
            result.push_front(node->value);
            node = node->next;
        }
        for(int value : result)
            os << value;
        return os;
    }
};

int main()
{
    long n1 = 9;
    long n2 = 9;
    BigNumber bn1(to_string(n1));
    BigNumber bn2(to_string(n2));
    cout << (bn1 + bn2) << endl;
    cout << (n1 + n2) << endl;
    return 0;
}
