// Arquivo de execucao
#include <iostream>
using std::string;

bool isPalindrome(string word){
    // TODO
    (void) word;
    return false;
}

int main(){
    string w;
    std::cin >> w;
    if(isPalindrome(w)){
        std::cout << "palindromo" << std::endl;
    }else{
        std::cout << "nao palindromo" << std::endl;
    }
}
