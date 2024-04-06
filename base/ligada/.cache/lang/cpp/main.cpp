#include <iostream>
#include <sstream>
#include "list.hpp"
#include "fn.hpp"
using namespace std;
using namespace fn;

int main() {
    LinkedList ll;

    while(true) {
        auto line = std::cin | INPUT();
        auto args = line | SPLIT(' ');
        fn::write("$" + line);
        auto cmd = args[0];

        if      (cmd == "end"       ) { break;                                               }
        else if (cmd == "show"      ) { ll.str()   | WRITE();                                }
        else if (cmd == "size"      ) { ll.size()  | WRITE();                                }
        else if (cmd == "push_back" ) { for (auto v : args | SLICE(1)) { ll.push_back(+v); } }
        else if (cmd == "push_front") { for (auto v : args | SLICE(1)) { ll.push_front(+v); }}
        else if (cmd == "pop_back"  ) { ll.pop_back();                                       }
        else if (cmd == "pop_front" ) { ll.pop_front();                                      }
        else if (cmd == "clear"     ) { ll.clear();                                          }
        else                          { "fail: comando invalido" | WRITE(); }
    }
}
