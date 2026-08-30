#include <iostream>
#include <vector>
#include <sstream>

// @DROP
std::string __tostr(int * init, int * end) {
    if (init == end) {
        return "";
    }
    if (init + 1 == end) {
        return std::to_string(*init);
    }
    return std::to_string(*init) + ", " + __tostr(init + 1, end);
}
// @KEEP
// init: aponta para o primeiro elemento do vetor
// end: aponta para uma posição depois do último elemento do vetor
// converte o vetor para texto no formato [1, 2, 3, 4]
std::string tostr(int * init, int * end) {
    // @DROP
    std::string output = __tostr(init, end);
    return "[" + output + "]";
    // @UNC
    // (void) init;
    // (void) end;
    // return "";
}

// @DROP
std::string __torev(int * init, int * end) {
    if (init == end) {
        return "";
    }
    if (init + 1 == end) {
        return std::to_string(*init);
    }
    return __torev(init + 1, end) + ", " + std::to_string(*init);
}
// @KEEP
// converte o vetor para texto, porém ao contrário
std::string torev(int * init, int * end) {
    // @DROP
    std::string output = __torev(init, end);
    return "[" + output + "]";
    // @UNC
    // (void) init;
    // (void) end;
    // return "";
}
// @KEEP
// inverte os elementos do vetor inplace
void reverse(int * init, int * end) {
    // @DROP
    if (init + 1 >= end) {
        return;
    }
    std::swap(*init, *(end - 1));
    reverse(init + 1, end - 1);
    // @UNC
    // (void) init;
    // (void) end;
}
// @KEEP
int sum(int * init, int * end) {
    // @DROP
    if (init == end) {
        return 0;
    }
    return *init + sum(init + 1, end);
    // @UNC
    // (void) init;
    // (void) end;
    // return 0;
};
// @KEEP
// multiplica os elementos do vetor
// retorne 1, se o vetor estiver vazio
int mult(int * init, int * end) {
    if (init == end) {
        return 1;
    }
    return *init * mult(init + 1, end);
    // @UNC
    // (void) init;
    // (void) end;
    // return 0;
};

// @DROP
std::pair<int, int> __min(int * init, int * end) {
    if (init == end) {
        return std::make_pair(-1, 0);
    }
    auto [ind, value] = __min(init + 1, end);

    // eu sou o último
    if (ind == -1) {
        return {0, *init};
    }

    // eu não sou menor
    if (*init >= value) {
        return {ind + 1, value};
    }
    // eu sou menor
    return {0, *init};

};
// @KEEP
// DESAFIO
// retorne a posição do menor elemento do vetor
// crie uma função auxiliar __min
// que retorne a posição e o valor do menor elemento
// se o vetor estiver vazio, retorne -1
int min(int * init, int * end) {
    // @DROP
    auto [ind, value] = __min(init, end);
    return ind;
    // @UNC
    // (void) init;
    // (void) end;
    // return -1;
}
// @KEEP
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
