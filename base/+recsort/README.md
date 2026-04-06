# Algoritmos de Ordenação Recursiva: Merge Sort e Quick Sort

## MergeSort

O Merge Sort é um algoritmo de ordenação baseado na técnica de Divisão e Conquista. A ideia principal é dividir a lista em duas metades, ordenar cada metade recursivamente e, em seguida, combinar (merge) as duas metades ordenadas em uma única lista ordenada.

### Passos do Merge Sort

1. Divida a lista ao meio.
2. Ordene recursivamente cada metade.
3. Intercale (merge) as duas metades ordenadas para obter a lista final ordenada.

### Funcionamento do Merge

![Gif MergeSort](./assets/merge.gif)

### Implementação do Merge em C++

<!-- load assets/merge.cpp fenced -->

```cpp
#include <iostream>
#include <vector>

// Função para mesclar dois subvetores ordenados
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Função principal do MergeSort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Vetor original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, n - 1);

    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

<!-- load -->

## QuickSort

O Quick Sort é outro algoritmo de ordenação baseado na técnica de Divisão e Conquista. A principal ideia do Quick Sort é escolher um elemento como pivô, particionar a lista de modo que todos os elementos menores que o pivô fiquem à esquerda e todos os elementos maiores que o pivô fiquem à direita, e então ordenar as sublistas recursivamente.

### Passos do Quick Sort

1. Escolha um elemento como pivô.
2. Particione a lista em duas sublistas: uma contendo elementos menores que o pivô e outra contendo elementos maiores que o pivô.
3. Ordene recursivamente as sublistas.

### Funcionamento do Quick

![Gif do QuickSort](./assets/quick.gif)

### Implementação do Quick em C++

<!-- load ./assets/merge.cpp fenced -->

```cpp
#include <iostream>
#include <vector>

// Função para mesclar dois subvetores ordenados
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Função principal do MergeSort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Vetor original: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, n - 1);

    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

<!-- load -->
