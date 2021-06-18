#include <iostream>
#include <sstream>
#include "lib.hpp"

using namespace std;

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show_in_order();
}
