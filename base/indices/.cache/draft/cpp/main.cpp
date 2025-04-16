#include <iostream>
#include <vector>

//Escolha e implemente um algoritmo de ordenação
std::vector<int> ordenar(std::vector<int> arr) {
    (void) arr;
    return arr;
}

std::vector<int> originalIndices(std::vector<int>& arr, std::vector<int>& arrOrdenado) {
    (void) arr;
    (void) arrOrdenado;
    return std::vector<int> {};
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> arrOrdenado = ordenar(arr);
    std::vector<int> indices = originalIndices(arr, arrOrdenado);

    for (int i = 0; i < (int) indices.size(); i++) {
        if (i != 0) {
            std:: cout << " ";
        }
        std::cout << indices[i];
    }

    std::cout << std::endl;

    return 0;
}
