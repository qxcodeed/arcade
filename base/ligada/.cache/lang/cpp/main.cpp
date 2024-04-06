#include "list.hpp"
#include "fn.hpp"
using namespace std;
using namespace fn;

int main() {
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    std::cout << ll << std::endl;
}
