#include "lib.hpp"
#include <sstream> //stringstream

namespace alu {

    std::string __tostr(int * init, int * end) {
        if (init == end) {
            return "";
        }
        return std::to_string(*init) + ", " + __tostr(init + 1, end);
    }

    std::string tostr(int * init, int * end) {
        std::string output = __tostr(init, end);

        if (output.size() > 0) { //se tiver pelo menos um elemento
            output.pop_back();   //remove o ultimo espaço
            output.pop_back();   //remove a ultima virgula
        }

        return "[" + output + "]";
    }
    std::string torev(int * init, int * end) {
    }

    void reverse(int * init, int * end) {
    }

    int sum(int * init, int * end) {
    };

    int mult(int * init, int * end) {
    };

    int min(int * init, int * end) {
    };

} // namespace alu