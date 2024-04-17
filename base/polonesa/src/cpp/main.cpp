#include "flow.hpp"
#include <stack>
#include <unordered_map>

using namespace std;
using namespace fw;

// ++
bool isdigit(const string& s) {
    return s.find_first_not_of("0123456789") == string::npos;
    // $$
    // (void) s;
    // return false;
}

vector<string> shunting_yard(vector<string> tokens) {
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
    // $$
    // (void) tokens;
    // return {};
}

int main() {
    vector<string> data = input() | Split(" ");
    shunting_yard(data) | Join(" ") | Write();
    return 0;
}

