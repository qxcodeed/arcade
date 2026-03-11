#include "fn.hpp"
#include <stack>
#include <unordered_map>

using namespace std;

bool isdigit(const string& s) {
    (void) s;
    return false;
}

vector<string> shunting_yard(vector<string> tokens) {
    (void) tokens;
    return {};
}

int main() {
    vector<string> data = fn::input() | fn::SPLIT(' ');
    shunting_yard(data) | fn::JOIN(" ") | fn::WRITE();
    return 0;
}
