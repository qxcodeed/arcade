#include <iostream>
#include <vector>

//Escolha e implemente um algoritmo de ordenação
void ordenar(std::vector<int>& arr) {
    (void) arr;
}

void vacinou(std::vector<int>& vacinas, std::vector<int>& pacientes){
    (void) vacinas;
    (void) pacientes;
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
