#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::string line, cmd;
    
    // // V é criado como ponteiro para não ter problemas com cópias
    // Vector* v = new Vector(0);

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
            // int cap = std::stoi(parts[1]);
            // delete v;
            // v = new Vector(cap);
        } else if (cmd == "push") {
            // for (size_t i = 1; i < parts.size(); i++)
            //     v->push_back(std::stoi(parts[i]));
        } else if (cmd == "show") {
            // std::cout << v->str() << "\n";
        } else if (cmd == "status") {
            // std::cout << v->status() << "\n";
        } else if (cmd == "pop") {
            // if (!v->pop_back())
            //     std::cout << "vector is empty\n";
        } else if (cmd == "insert") {
            // int index = std::stoi(parts[1]);
            // int value = std::stoi(parts[2]);
            // if (!v->insert(index, value))
            //     std::cout << "index out of range\n";
        } else if (cmd == "erase") {
            // int index = std::stoi(parts[1]);
            // if (!v->erase(index))
            //     std::cout << "index out of range\n";
        } else if (cmd == "indexOf") {
            // int value = std::stoi(parts[1]);
            // std::cout << v->index_of(value) << "\n";
        } else if (cmd == "contains") {
            // int value = std::stoi(parts[1]);
            // std::cout << (v->contains(value) ? "true" : "false") << "\n";
        } else if (cmd == "clear") {
            // v->clear();
        } else if (cmd == "capacity") {
            // std::cout << v->get_capaticy() << "\n";
        } else if (cmd == "get") {
            // int index = std::stoi(parts[1]);
            // auto [val, ok] = v->at(index);
            // if (ok)
            //     std::cout << val << "\n";
            // else
            //     std::cout << "index out of range\n";
            // 
        } else if (cmd == "set") {
            // int index = std::stoi(parts[1]);
            // int value = std::stoi(parts[2]);
            // if (!v->set(index, value))
            //     std::cout << "index out of range\n";
        } else if (cmd == "reserve") {
            // int newCap = std::stoi(parts[1]);
            // v->reserve(newCap);
        } else {
            std::cout << "comando invalido\n";
        }
    }
    // delete v;
    return 0;
}
