#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
using vet_it = std::vector<int>::iterator;


std::string fmt(std::vector<int> vet) {
    return "";
}

std::string fmt_rev(std::vector<int> vet) {
    return "";
}

void reverse(vet_it inicio, vet_it fim) {
}


int sum(vet_it inicio, vet_it fim) {
    return 0;
};

int mult(vet_it inicio, vet_it fim) {
    return 0;
};

int menor(vet_it inicio, vet_it fim) {
    return 0;
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

