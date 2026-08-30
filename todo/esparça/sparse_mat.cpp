#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
    int y;
    int x;

    int data;
    
    Node* y_next {nullptr};
    Node* x_next {nullptr};

    Node(int y, int x, int data) : y(y), x(x), data(data){}

    Node * set_x_loop() {
        x_next = this;
        return this;
    }
    Node * set_y_loop() {
        y_next = this;
        return this;
    }
    string str() {
        stringstream ss;
        ss << y << ":" << x << ':' << data;
        return ss.str();
    }
};

struct Iter {
    Node ** link;
    Iter(Node ** link): link(link) {}

    void go_x() {
        link = &(*link)->x_next;
    }
    void go_y() {
        link = &(*link)->y_next;
    }

    Iter x_next() {
        return Iter(&(*link)->x_next);
    }

    Iter y_next() {
        return Iter(&(*link)->y_next);
    }
    
    void set(Node * node) {
        *link = node;
    }

    Node * node() {
        return *link;
    }
    int& value() {
        return node()->data;
    }
    int x() {
        return node()->x;
    }
    int y() {
        return node()->y;
    }
};


class SparseMat {
    Node* head;
    int x_size {0};
    int y_size {0};

public:
    SparseMat(int y_size, int x_size): x_size(x_size), y_size(y_size) {
        // @DROP
        head = new Node(0, 0, 0);
        {
            Node * node = head;
            for (int i = 1; i < y_size; i++) { //go down
                node->y_next = (new Node(i, 0, 0))->set_x_loop(); //add new node looking to himself in x
                node = node->y_next; //go down
            }
            node->y_next = head; //loop
        }
        {
            Node * node = head;
            for (int i = 1; i < x_size; i++) {
                node->x_next = (new Node(0, i, 0))->set_y_loop();
                node = node->x_next;
            }
            node->x_next = head; //loop
        }
    }

    Iter it_begin() {
        return Iter(&head);
    }

    string str() {
        stringstream ss;
        Iter it = it_begin();
        while(true) {
            ss << it.node()->str() << ' ';
            if (it.x_next().x() == 0 and it.x_next().y_next().y() == 0) {
                break;
            }
            if (it.x_next().x() == 0) {
                it.go_x();
                it.go_y();
                ss << '\n';
            } else {
                it.go_x();
            }
        }
        return ss.str();
    }

    void set(int y, int x, int data) {
        if (y < 0 or y >= y_size or x < 0 or x >= x_size) {
            cout << "pos invalida\n";
            return;
        }
        auto it = find_link_x(y, x);
        if (it.x() == x and it.y() == y) {
            it.value() = data;
        } else {
            Node * node = new Node(y, x, data);
            node->x_next = it.node();
            it.set(node);

            auto it_down = find_link_y(y, x); //creating link in y
            node->y_next = it_down.node();
            it_down.set(node);
        }
    }

    int get(int y, int x) {
        if (y < 0 or y >= y_size or x < 0 or x >= x_size) {
            cout << "pos invalida\n";
            return 0;
        }
        auto it = find_link_x(y, x);
        if (it.y() == y and it.x() == x) {
            return it.value();
        }
        return 0;
    }

    vector<vector<int>> to_mat() {
        vector<vector<int>> output(y_size, vector<int>(x_size, 0));
        for (int y = 0; y < y_size; y++) {
            for (int x = 0; x < x_size; x++) {
                output[y][x] = this->get(y, x);
            }
        }
        return output;
    }

    vector<int> get_line(int y) {
        Iter it = this->it_begin();
        while (y--) {
            it.go_y();
        }
        vector<int> output(x_size, 0);
        do {
            output[it.x()] = it.value();
            it.go_x();
        } while (it.x() != 0);
        return output;
    }

    vector<int> get_column(int x) {
        Iter it = it_begin();
        while (x--) {
            it.go_x();
        }
        vector<int> output(y_size, 0);
        do {
            output[it.y()] = it.value();
            it.go_y();
        } while (it.y() != 0);
        return output;
    }

private:
    //retorna onde ele está ou onde deveria estar
    Iter find_link_y(int y, int x) {
        Iter it = this->it_begin();
        while(it.x() != x) { //go right
            it.go_x();
        }
        while (true) { //go down
            if (it.y() == y or it.y() > y) {
                return it;
            }
            if (it.y_next().y() == 0) {
                return it.y_next();
            }
            it.go_y();
        };
    }

    Iter find_link_x(int y, int x) {
        Iter it = this->it_begin();
        while(it.y() != y) {
            it.go_y();
        }
        while (true) { //go right
            if (it.x() == x or it.x() > x) {
                return it;
            }
            if (it.x_next().x() == 0) {
                return it.x_next();
            }
            it.go_x();
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
    SparseMat mat(3, 5);
    mat.set(0, 1, 4);
    mat.set(2, 0, 3);
    mat.set(1, 1, 5);
    mat.set(2, 3, 9);
    mat.set(0, 4, 8);

    cout << "matriz como nós\n";
    cout << mat.str() << endl;

    cout << "matriz como matriz\n";
    auto lines = mat.to_mat();
    for (auto line : lines) {
        cout << join(line, ", ") << '\n';
    }

    cout << "navegando na linha 2 : [" << join(mat.get_line(2), ", ") << "]\n";
    cout << "navegando na coluna 1: [" << join(mat.get_column(1), ", ") << "]\n";

    return 0;
}
