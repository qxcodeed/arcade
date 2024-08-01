#include <iostream>
#include <vector>

//Realiza as viradas na pilha de tapiocas
void flip(std::vector<int>& tapiocas, int i) {
    (void) tapiocas;
    (void) i;
}

//Retorna o indice do maior elemento da sequência
int findMax(std::vector<int>& tapiocas, int n) {
    (void) tapiocas;
    (void) n;
    return 0;
}

std::vector<int> tapiocaSort(std::vector<int>& tapiocas, int n) {


    (void) tapiocas;
    (void) n;
    return std::vector<int> {};
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
