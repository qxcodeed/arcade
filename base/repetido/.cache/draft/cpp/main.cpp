// Arquivo de execucao
#include <iostream>

bool repetido(int V[], int n){
    //TODO
    //DEL!
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(V[i] == V[j]){
                return true;
            }
        }
    }
    return false;
    //ACT!
    //(void) V;
    //(void) n;
    //return false;
}

int main(){
    int *V = new int[100];
    int n;

    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> V[i];
    }
    
    if(repetido(V, n)){
        std::cout << "repete" << std::endl;
    } else {
        std::cout << "unico" << std::endl;
    }
}
