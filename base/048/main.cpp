#include <iostream>
#include <sstream>
#include "lib.hpp"

int main(){
    std::string line;
    std::getline(cin, line);
    BTree bt(line);
    std::cout << bt.in_order() << '\n';
}
