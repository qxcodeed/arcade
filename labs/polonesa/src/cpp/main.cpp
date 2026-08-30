#include "fn.hpp"
#include <stack>
#include <unordered_map>

using namespace std;

bool isdigit(const string& s) {
    // @DROP
    return s.find_first_not_of("0123456789") == string::npos;
    // @UNC
    // (void) s;
    // return false;
}

vector<string> shunting_yard(vector<string> tokens) {
    // @DROP
    unordered_map<string, int> precedencia = {{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"^", 3}};
    stack<string> pilha;
    string token;

    vector<string> postfix;
    
    for (const string& token : tokens) {
        if (isdigit(token)) {
            postfix.push_back(token);
            continue;
        }
        while (!pilha.empty() && precedencia[pilha.top()] >= precedencia[token]) {
            postfix.push_back(pilha.top());
            pilha.pop();
        }
        pilha.push(token);
    }

    while (!pilha.empty()) {
        postfix.push_back(pilha.top());
        pilha.pop();
    }
    
    return postfix;
    // @UNC
    // (void) tokens;
    // return {};
}

int main() {
    vector<string> data = fn::input() | fn::SPLIT(' ');
    shunting_yard(data) | fn::JOIN(" ") | fn::WRITE();
    return 0;
}
