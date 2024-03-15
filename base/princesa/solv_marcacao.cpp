#include <iostream>
#include <vector>

//find the next alive element from start + 1
int find_alive(std::vector<bool> vet, int pos) {
    do {
        pos = (pos + 1) % vet.size();
    } while (vet[pos] == false);
    return pos;
}

//print the vector showing who has the sword
void show_vector(std::vector<bool> vet, int sword) {
    std::cout << "[";
    for (int i = 0; i < (int) vet.size(); i++) {
        if (vet[i])
            std::cout << " " << (i + 1);
        if(i == sword)
            std::cout << ">";
    }
    std::cout << " ]\n";
}

int main(){
    int size { };
    std::cin >> size;
    std::vector<bool> vet(size, true);
    int sword { }; //chosen one
    std::cin >> sword;
    sword = sword - 1;
    show_vector(vet, sword);
    int qtd = size - 1;
    while(qtd--) {
        int to_die {find_alive(vet, sword)};
        vet[to_die] = false;
        sword = find_alive(vet, to_die);
        show_vector(vet, sword);
    }
}
