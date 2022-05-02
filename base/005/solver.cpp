#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
using vet_it = std::vector<int>::iterator;

#define PROF

std::string fmt(std::vector<int> vet) {
#ifdef PROF
    std::stringstream ss;

    std::function<void(vet_it, vet_it)>
    fn = [&fn, &ss](vet_it inicio, vet_it fim) {
        if (inicio == fim)
            return;
        ss << *inicio << " ";
        fn(inicio + 1, fim);
    };

    ss << "[ ";
    fn(vet.begin(), vet.end());
    ss << "]";
    return ss.str();
#else
    return "";
#endif
}

std::string fmt_rev(std::vector<int> vet) {
#ifdef PROF
    std::stringstream ss;

    std::function<void(vet_it, vet_it)>
    fn = [&fn, &ss](vet_it inicio, vet_it fim) {
        if (inicio == fim)
            return;
        fn(inicio + 1, fim);
        ss << *inicio << " ";
    };

    ss << "[ ";
    fn(vet.begin(), vet.end());
    ss << "]";
    return ss.str();
#else
    return "";
#endif
}

void reverse(vet_it inicio, vet_it fim) {
#ifdef PROF
    if (std::next(inicio) >= fim) //1 ou nenhum elemento
        return;
    std::swap(*inicio, *std::prev(fim));
    reverse(inicio + 1, fim - 1);
#else
#endif
}


int sum(vet_it inicio, vet_it fim) {
#ifdef PROF
    if (inicio == fim)
        return 0;
    return *inicio + sum(inicio + 1, fim);
#else
    return 0;
#endif
};

int mult(vet_it inicio, vet_it fim) {
#ifdef PROF
    if (inicio == fim)
        return 1;
    return *inicio * mult(inicio + 1, fim);
#else
    return 0;
#endif
};

int menor(vet_it inicio, vet_it fim) {
#ifdef PROF
    if (inicio + 1 == fim)
        return *inicio;
    return std::min(*inicio, menor(inicio + 1, fim));
#else
    return 0;
#endif
};

std::vector<int> parse_vet() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> vet;
    int value { };
    while (ss >> value)
        vet.push_back(value);
    return vet;
}

int main() {

    auto vet = parse_vet();
    std::cout << "vet : " << fmt(vet) << "\n";
    std::cout << "rvet: " << fmt_rev(vet) << "\n";
    std::cout << "sum : " << sum(vet.begin(), vet.end()) << "\n";
    std::cout << "mult: " << mult(vet.begin(), vet.end()) << "\n";
    std::cout << "min : " << menor(vet.begin(), vet.end()) << "\n";
    reverse(vet.begin(), vet.end());
    std::cout << "inv : " << fmt(vet) << "\n";

}

