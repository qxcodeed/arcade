#include <iostream>
#include <vector>

//Realiza as viradas na pilha de tapiocas
void flip(std::vector<int>& tapiocas, int i) {
    //DEL!
    int temp;
    for (int start = 0; start <= i; start++, i--) {
        temp = tapiocas[start];
        tapiocas[start] = tapiocas[i];
        tapiocas[i] = temp;
    }
    //ACT!
    // (void) tapiocas;
    // (void) i;
}

//Retorna o indice do maior elemento da sequência
int findMax(std::vector<int>& tapiocas, int n) {
    //DEL!
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (tapiocas[i] > tapiocas[max]) {
            max = i;
        }
    }
    return max;
    //ACT!
    // (void) tapiocas;
    // (void) n;
    // return 0;
}

std::vector<int> tapiocaSort(std::vector<int>& tapiocas, int n) {
    //DEL!
    std::vector<int> viradas;

    int tamanho = tapiocas.size();
    
    while(tamanho > 1){
        int max =  findMax(tapiocas, tamanho);
        if (max == tamanho-1) {
            tamanho--;
        }
        else if (max == 0){
            flip(tapiocas, n - (n - tamanho + 1));
            viradas.push_back(n - tamanho + 1);
            tamanho--;
        }
        else{
            flip(tapiocas, max);
            viradas.push_back(n - max);
        }
    }

    viradas.push_back(0);
    return viradas;
    //ACT!
    // (void) tapiocas;
    // (void) n;
    // return std::vector<int> {};
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> tapiocas(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tapiocas[i];
    }
    std::vector<int> viradas = tapiocaSort(tapiocas, n);

    for (int i = 0; i < (int) viradas.size(); i++){
        if(i != 0) {
            std:: cout << " ";
        }
        std::cout << viradas[i];
    }
    std::cout << std::endl;

    return 0;
}
