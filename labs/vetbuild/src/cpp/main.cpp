#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Vector {
    private:
    int* data;
    int size;
    int capacity;
    bool is_view; // indica se é uma view (slice) ou um vetor independente
    
// @DROP
public:
    Vector(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
        this->is_view = false;
    }

    ~Vector() {
        if (!is_view) {
            delete[] data;
        }
    }

    void reserve(int newCapacity) {
        if (newCapacity > capacity) {
            int* newData = new int[newCapacity];
            for (int i = 0; i < size; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
    }

    void push_back(int value) {
        if (size == capacity)
            reserve(std::max(1, capacity * 2));
        data[size++] = value;
    }

    bool pop_back() {
        if (size == 0)
            return false;
        size--;
        return true;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > size)
            return false;
        if (size == capacity)
            reserve(std::max(1, capacity * 2));
        for (int i = size; i > index; i--)
            data[i] = data[i - 1];
        data[index] = value;
        size++;
        return true;
    }

    bool erase(int index) {
        if (index < 0 || index >= size)
            return false;
        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
        return true;
    }

    int index_of(int value) {
        for (int i = 0; i < size; i++)
            if (data[i] == value)
                return i;
        return -1;
    }

    bool contains(int value) {
        return index_of(value) != -1;
    }

    int get_size() {
        return size;
    }

    int get_capaticy() {
        return capacity;
    }

    std::string status() {
        return "size:" + std::to_string(size) + " capacity:" + std::to_string(capacity);
    }

    std::string str() {
        std::string res = "[";
        for (int i = 0; i < size; i++) {
            res += std::to_string(data[i]);
            if (i < size - 1)
                res += ", ";
        }
        res += "]";
        return res;
    }

    int get(int index) {
        return data[index];
    }

    std::pair<int, bool> at(int index) {
        if (index < 0 || index >= size)
            return {0, false};
        return {data[index], true};
    }

    bool set(int index, int value) {
        if (index < 0 || index >= size)
            return false;
        data[index] = value;
        return true;
    }

    void clear() {
        size = 0;
    }

    Vector slice(int start, int end) {
        if (start < 0)
            start = size + start;
        if (end < 0)
            end = size + end;
        if (start < 0)
            start = 0;
        if (end > size)
            end = size;
        if (start > end)
            start = end;
        Vector other(end - start);
        other.size = end - start;
        other.data = this->data + start;
        other.is_view = true;
        return other;
    }
// @KEEP
};

int main() {
    std::string line, cmd;
    
    // @COM
    // V é criado como ponteiro para não ter problemas com cópias
    Vector* v = new Vector(0);
    // @KEEP

    while (true) {
        std::cout << "$";
        if (!std::getline(std::cin, line)) break;

        std::cout << line << "\n";
        std::istringstream iss(line);
        std::vector<std::string> parts;
        std::string word;
        while (iss >> word) parts.push_back(word);
        if (parts.empty()) continue;
        cmd = parts[0];

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            // @COM
            int cap = std::stoi(parts[1]);
            delete v;
            v = new Vector(cap);
        } else if (cmd == "push") {
            // @COM
            for (size_t i = 1; i < parts.size(); i++)
                v->push_back(std::stoi(parts[i]));
        } else if (cmd == "show") {
            // @COM
            std::cout << v->str() << "\n";
        } else if (cmd == "status") {
            // @COM
            std::cout << v->status() << "\n";
        } else if (cmd == "pop") {
            // @COM
            if (!v->pop_back())
                std::cout << "vector is empty\n";
        } else if (cmd == "insert") {
            // @COM
            int index = std::stoi(parts[1]);
            int value = std::stoi(parts[2]);
            if (!v->insert(index, value))
                std::cout << "index out of range\n";
        } else if (cmd == "erase") {
            // @COM
            int index = std::stoi(parts[1]);
            if (!v->erase(index))
                std::cout << "index out of range\n";
        } else if (cmd == "indexOf") {
            // @COM
            int value = std::stoi(parts[1]);
            std::cout << v->index_of(value) << "\n";
        } else if (cmd == "contains") {
            // @COM
            int value = std::stoi(parts[1]);
            std::cout << (v->contains(value) ? "true" : "false") << "\n";
        } else if (cmd == "clear") {
            // @COM
            v->clear();
        } else if (cmd == "capacity") {
            // @COM
            std::cout << v->get_capaticy() << "\n";
        } else if (cmd == "get") {
            // @COM
            int index = std::stoi(parts[1]);
            auto [val, ok] = v->at(index);
            if (ok)
                std::cout << val << "\n";
            else
                std::cout << "index out of range\n";

        } else if (cmd == "set") {
            // @COM
            int index = std::stoi(parts[1]);
            int value = std::stoi(parts[2]);
            if (!v->set(index, value))
                std::cout << "index out of range\n";
        } else if (cmd == "reserve") {
            // @COM
            int newCap = std::stoi(parts[1]);
            v->reserve(newCap);
        } else if (cmd == "slice") {
            // @COM
            int start = std::stoi(parts[1]);
            int end = std::stoi(parts[2]);
            Vector slice = v->slice(start, end);
            std::cout << slice.str() << "\n";
        } else {
            std::cout << "comando invalido\n";
        }
    }
    // @COM
    delete v;
    // @KEEP
    return 0;
}
