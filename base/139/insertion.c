#include <stdio.h>
#include "../libs/xpaint.h"
#include "xvet.h"

void insertion(int * vet, int size){
    for(int i = 1; i < size; i++){
        xs_partition(0, i);
        xs_pivot(vet[i]);
        xd_vet(vet, size, "r", i);
        int j;
        for(j = i; j > 0; j--){
            if(vet[j] < vet[j - 1]){
                X_SWAP(vet[j], vet[j - 1], int);
                xd_vet(vet, size, "y", j - 1);
            }else
                break;
        }
        xd_vet(vet, size, "g", j);
    }
    xd_vet(vet, size, NULL);
}

void verify(int * vet, int size){
    int i = 0;
    for(i = 0;i < size - 1; i++){  
        if(vet[i] <= vet[i + 1])
            xd_vet(vet, size, "gg", i, i + 1);
        else{
            xd_vet(vet, size, "rr", i, i + 1);
            break;
        }
    }
}

int main() {

    x_open(600, 300);
    xs_log("imgs/");
    srand(2); 

    int vet[30];
    int size = sizeof(vet)/sizeof(int);
    int i;
    for(i = 0; i < size; i++)
        vet[i] = rand() % 200 + 1; 

    insertion(vet, size);
    verify(vet, size);
    xs_jump(1); //interativo
    xd_vet(vet, size, "");
    x_close();

    return 0;
 }

