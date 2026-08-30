#include <iostream>
#include <vector>
#include <sstream>

// init: aponta para o primeiro elemento do vetor
// end: aponta para uma posição depois do último elemento do vetor
// converte o vetor para texto no formato [1, 2, 3, 4]
std::string tostr(int * init, int * end) {
    (void) init;
    (void) end;
    return "";
}

// converte o vetor para texto, porém ao contrário
std::string torev(int * init, int * end) {
    (void) init;
    (void) end;
    return "";
}
// inverte os elementos do vetor inplace
void reverse(int * init, int * end) {
    (void) init;
    (void) end;
}
int sum(int * init, int * end) {
    (void) init;
    (void) end;
    return 0;
};
// multiplica os elementos do vetor
// retorne 1, se o vetor estiver vazio
int mult(int * init, int * end) {
    if (init == end) {
        return 1;
    }
    return *init * mult(init + 1, end);
    (void) init;
    (void) end;
    return 0;
};

// DESAFIO
// retorne a posição do menor elemento do vetor
// crie uma função auxiliar __min
// que retorne a posição e o valor do menor elemento
// se o vetor estiver vazio, retorne -1
int min(int * init, int * end) {
    (void) init;
    (void) end;
    return -1;
}
int main() {
    std::vector<int> vet;

    while (true) {
        std::string line;
        std::getline(std::cin, line);
        std::cout << "$" << line << std::endl;
        std::istringstream iss(line);
        std::vector<std::string> args;
        std::string arg;
        while (iss >> arg) {
            args.push_back(arg);
        }
        if (args[0] == "end") {
            break;
        } else if (args[0] == "read") {
            vet.clear();
            for (size_t i = 1; i < args.size(); i++) {
                vet.push_back(std::stoi(args[i]));
            }
        } else if (args[0] == "tostr") {
            auto resp = tostr(vet.data(), vet.data() + vet.size());
            std::cout << resp << std::endl;
        } else if (args[0] == "torev") {
            auto resp = torev(vet.data(), vet.data() + vet.size());
            std::cout << resp << std::endl;
        } else if (args[0] == "reverse") {
            reverse(vet.data(), vet.data() + vet.size());
        } else if (args[0] == "sum") {
            auto resp = sum(vet.data(), vet.data() + vet.size());
            std::cout << resp << std::endl;
        } else if (args[0] == "mult") {
            auto resp = mult(vet.data(), vet.data() + vet.size());
            std::cout << resp << std::endl;
        } else if (args[0] == "min") {
            auto resp = min(vet.data(), vet.data() + vet.size());
            std::cout << resp << std::endl;
        } else {
            std::cout << "Comando inválido" << std::endl;
        }
    }
}
