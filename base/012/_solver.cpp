#include <iostream>
#include <sstream>
#include <memory>
#include <iomanip>
#include <aux.hpp>


int main() {
    std::cout << (aux::STREAM() | std::setw(10) | "hello " | 5 | '\n' | aux::COLLECT());
    std::cout << (aux::STREAM() | "world " | 5 | '\n' | aux::COLLECT());
}