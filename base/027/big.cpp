#include <iostream>
#include <list>
using namespace std;

struct BigNumber{
    list<int> data;

    BigNumber(string value = ""){
        for(char c : value)
            data.push_front(c - '0');
    }

    ~BigNumber(){
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
