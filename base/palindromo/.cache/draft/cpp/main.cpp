// Arquivo de execucao
#include <iostream>
using std::string;

bool isPalindrome(string word){
    // TODO
    //DEL!
    int n = word.length();
    for(int i = 0; i < n / 2; i++){
        if(word[i] != word[n - i - 1]){
            return false;
        }
    }
    return true;
    //ACT!
    //(void) word;
    //return false;
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
