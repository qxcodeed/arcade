#include <iostream>
#include <vector>
#include <sstream>
#include "lib.hpp"
#include "fn.hpp"

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
