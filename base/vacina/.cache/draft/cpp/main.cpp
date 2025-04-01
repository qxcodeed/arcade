#include <iostream>
#include <vector>

//Escolha e implemente um algoritmo de ordenação
void ordenar(std::vector<int>& arr) {
    //DEL!
    for (int i = 0; i < (int) arr.size(); i++) {
        for (int j = 0; j < (int) arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    //ACT!
    // (void) arr;
}

void vacinou(std::vector<int>& vacinas, std::vector<int>& pacientes){
    //DEL!
    for (int i = 0; i < (int) vacinas.size(); i++) {
        if (vacinas[i] < pacientes[i]) {
            std::cout << "No" << std::endl;
            return;
        }
    }

    std::cout << "Yes" << std::endl;
    //ACT!
    // (void) vacinas;
    // (void) pacientes;
}

int main(){
    int n;
    std::cin >> n;
    
    std::vector<int> vacinas(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vacinas[i];
    }

    std::vector<int> pacientes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pacientes[i];
    }

    ordenar(vacinas);
    ordenar(pacientes);

    vacinou(vacinas, pacientes);
}
