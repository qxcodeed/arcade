#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
    int last {0};

public:
    SparseMap() {
        // @DROP
        head = new Node(0, 0);
        head->x_next = head;
    }

    string str() {
        // @UNC
        // return "";
        // @DROP
        stringstream ss;
        auto node = head;
        do {
            ss << node->str() << " ";
            node = node->x_next;
        } while (node != head);
        return ss.str();
    }

    void set(int index, int data) {
        (void) index;
        (void) data;
        // @DROP
        auto link = find_link(index);
        auto node = *link;
        if (index > last) {
            last = index;
        }
        if (node->x == index) {
            node->data = data;
        } else {
            *link = new Node(index, data, node);
        }
    }

    int get(int index) {
        // @DROP
        auto link = find_link(index);
        auto node = *link;
        if (node->x == index) {
            return node->data;
        }
        // @KEEP
        return 0;
    }

    vector<int> to_vector() {
        vector<int> output(last + 1, 0);
        for (int i = 0; i < last + 1; i++) {
            output[i] = this->get(i);
        }
        return output;
    }

private:

    //retorna onde ele está ou onde deveria estar
    Node ** find_link(int index) {
        // @UNC
        // (void) index;
        // return nullptr;
        // @DROP
        Node **link = &head;
        while (true) {
            auto node = *link;
            if (node->x == index or node->x > index) {
                return link;
            }
            if (node->x_next == head) {
                return &node->x_next;
            }
            link = &node->x_next;
        };
    }
};

template <typename CONTAINER>
std::string join(CONTAINER container, string sep) {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); it++) {
        ss << (it == container.begin() ? "" : sep) << *it;
    }
    return ss.str();
}

int main() {
    SparseMap list;
    list.set(1, 10);
    list.set(5, 30);
    list.set(0, 4);
    list.set(2, 20);
    list.set(5, 12);
    cout << list.str() << endl; //0:4, 1:10, 2:20, 5:12
    
    cout << "[" << join(list.to_vector(), ", ") << "]" << '\n';

    return 0;
}
