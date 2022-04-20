#include <iostream>
#include <sstream>
#include "lib.hpp"
using namespace std;

int main() {
    LinkedList ll;
    while(true) {
        string line, cmd;
        int value;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end") {
            break;
        }else if(cmd == "show") {
            cout << ll << endl;
        }else if(cmd == "push_back") {
            while(ss >> value)
                ll.push_back(value);
        }else if(cmd == "push_front") {
            while(ss >> value)
                ll.push_front(value);
        }else if(cmd == "pop_back") {
            ll.pop_back();
        }else if(cmd == "pop_front") {
            ll.pop_back();
        }else if(cmd == "size") {
            cout << ll.size() << endl;
        }
    }
}

LinkedList::LinkedList() {
}

void destroy(Node * node) {
    if(node == nullptr)
        return;
    else{
        destroy(node->next);
        delete(node);
    }
}

LinkedList::~LinkedList() {
    destroy(head);
}
ostream& operator<<(ostream& os, LinkedList& lista) {
    os << "[ ";
    Node * node = lista.head;
    while(node != nullptr) {
        os << node->value << " ";
        node = node->next;
    }
    os << "]";
    return os;
}