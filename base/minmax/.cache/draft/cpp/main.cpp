#include <iostream>

void minMax(int V[], int n, int *min, int *max){
    //TODO
    //DEL!
    *min = V[0];
    *max = V[0];
    for(int i = 1; i < n; i++){
        if(V[i] < *min){
            *min = V[i];
        }
        if(V[i] > *max){
            *max = V[i];
        }
    }
    //ACT!
    //(void) V;
    //(void) n;
    //(void) min;
    //(void) max;
}

int main(){
    int *V = new int[100];
    int n, min, max;

    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> V[i];
    }
    minMax(V, n, &min, &max);    
    std::cout << min << " " << max << std::endl;
}
