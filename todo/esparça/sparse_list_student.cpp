#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int x;
    int data;
    Node* x_next;
    Node(int index, int data, Node* next = nullptr) : x(index), data(data), x_next(next) {}
    string str() {
        stringstream ss;
        ss << x << ":" << data;
        return ss.str();
    }
};

class SparseMap {
    Node* head;

public:
    SparseMap() {
    }

    string str() {
        return "";
    }

    void set(int index, int data) {
        (void) index;
        (void) data;
    }

    int get(int index) {
        return 0;
    }

private:

    //retorna onde ele está ou onde deveria estar
    Node ** find_link(int index) {
        (void) index;
        return nullptr;
    }
};

int main() {
    SparseMap list;
    list.set(1, 10);
    list.set(5, 30);
    list.set(0, 4);
    list.set(2, 20);
    list.set(5, 12);
    cout << list.str() << endl; //0:4, 1:10, 2:20, 5:12
    return 0;
}
