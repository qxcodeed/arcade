

#include "lib.hpp"
#include <sstream> //stringstream

namespace alu {

//==
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
//--

    std::string __torev(int * init, int * end) {
        if (init == end) {
            return "";
        }
        return __torev(init + 1, end) + ", " + std::to_string(*init);
    }

//++1
    std::string torev(int * init, int * end) {
        std::string output = __torev(init, end);
        if (output.size() > 0) { //se tiver pelo menos um elemento
            output = output.substr(2); //remove os dois primeiros caracteres
        }
        return "[" + output + "]";
        //ACT!
        // (void) init;
        // (void) end;
        // return "";
    }

    void reverse(int * init, int * end) {
        if (init + 1 >= end) {
            return;
        }
        std::swap(*init, *(end - 1));
        reverse(init + 1, end - 1);
        //ACT!
        // (void) init;
        // (void) end;
    }

    int sum(int * init, int * end) {
        if (init == end) {
            return 0;
        }
        return *init + sum(init + 1, end);
        //ACT!
        // (void) init;
        // (void) end;
        // return 0;
    };

    int mult(int * init, int * end) {
        if (init == end) {
            return 1;
        }
        return *init * mult(init + 1, end);
        //ACT!
        // (void) init;
        // (void) end;
        // return 0;
    };

//--
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
//++1
    int min(int * init, int * end) {
        auto [ind, value] = __min(init, end);
        return ind;
        //ACT!
        // (void) init;
        // (void) end;
        // return -1;
    };

} // namespace alu

int main() {
    std::vector<int> vet;

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "end") {
            break;
        } else if (args[0] == "read") {
            vet.clear();
            for (size_t i = 1; i < args.size(); i++) {
                vet.push_back(+args[i]);
            }
        } else if (args[0] == "tostr") {
            auto resp = alu::tostr(vet.data(), vet.data() + vet.size());
            fn::write(resp);
        } else if (args[0] == "torev") {
            auto resp = alu::torev(vet.data(), vet.data() + vet.size());
            fn::write(resp);
        } else if (args[0] == "reverse") {
            alu::reverse(vet.data(), vet.data() + vet.size());
        } else if (args[0] == "sum") {
            auto resp = alu::sum(vet.data(), vet.data() + vet.size());
            fn::write(resp);
        } else if (args[0] == "mult") {
            auto resp = alu::mult(vet.data(), vet.data() + vet.size());
            fn::write(resp);
        } else if (args[0] == "min") {
            auto resp = alu::min(vet.data(), vet.data() + vet.size());
            fn::write(resp);
        } else {
            fn::write("fail: comando invalido");
        }
    }
}
