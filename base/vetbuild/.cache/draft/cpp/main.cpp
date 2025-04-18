/*
Vector representa um array dinâmico que pode crescer conforme necessário.
Ele fornece métodos para manipular o array, como adicionar, remover e acessar elementos.

class Vector {
- int* data;          // Guarda os elementos do vetor
- int size;           // Guarda o número atual de elementos
- int capacity;       // Guarda a capacidade atual do vetor
__
+ Vector(int capacity);                // Cria um novo vetor com a capacidade inicial especificada
+ void reserve(int newCapacity);      // Redimensiona a capacidade do vetor para pelo menos o valor especificado
+ void pushBack(int value);           // Adiciona um valor ao final do vetor, redimensionando se necessário
+ int getSize();                      // Retorna o número atual de elementos no vetor
__
+ bool popBack();                     // Remove o último elemento do vetor. Retorna false se o vetor estiver vazio
+ int getCapacity();                  // Retorna a capacidade atual do vetor
+ std::string status();              // Retorna o tamanho e a capacidade do vetor
+ std::string str();                 // Retorna uma representação em string dos elementos do vetor
__
+ int get(int index);                         // Retorna o elemento no índice especificado sem verificação de limites
+ std::pair<int, bool> at(int index);        // Retorna o elemento no índice especificado com verificação de limites. Retorna false se o índice estiver fora dos limites
+ bool set(int index, int value);            // Define o valor no índice especificado. Retorna false se o índice estiver fora dos limites
+ void clear();                              // Limpa todos os elementos do vetor
__
+ bool insert(int index, int value);         // Insere um valor no índice especificado, deslocando os elementos conforme necessário. Retorna false se o índice estiver fora dos limites
+ bool erase(int index);                     // Remove o elemento no índice especificado, deslocando os elementos conforme necessário. Retorna false se o índice estiver fora dos limites
__
+ int indexOf(int value);                    // Retorna o índice da primeira ocorrência do valor especificado, ou -1 se não for encontrado
+ bool contains(int value);                  // Verifica se o valor especificado existe no vetor
+ void reverse();                            // Inverte a ordem dos elementos no vetor
+ void sort();                               // Ordena os elementos do vetor em ordem crescente
+ std::vector<int> sorted();                 // Retorna uma cópia ordenada dos elementos do vetor
};
*/


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
        } else if (cmd == "sort") {
            // v->sort();
        } else if (cmd == "sorted") {
            // auto sorted = v->sorted();
            // std::cout << "[";
            // for (size_t i = 0; i < sorted.size(); i++) {
            //     std::cout << sorted[i];
            //     if (i + 1 < sorted.size()) std::cout << ", ";
            // }
            // std::cout << "]\n";
        } else if (cmd == "reverse") {
            // v->reverse();
        } else {
            std::cout << "comando invalido\n";
        }
    }
    // delete v;
    return 0;
}
