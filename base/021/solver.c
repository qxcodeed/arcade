#include <stdio.h>
#include "../libs/xpaint.h"
#include "xvet.h"

void insertion(int * vet, int size){
    int i, j;
    //insertion sort
    for(i = 1; i < size; i++){
        xd_vet(vet, size, "r", i);
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

//quick [C, F]
void quick(int * vet, int size, int C, int F){
    xs_partition(C, F);  
    if(F <= C)
        return;
    int i = C + 1, j = F; /*guardar o pivo no C */
    int pivo = vet[C]; /* pivo como C nao é uma boa opção pro algoritmo, mas facilita a visualização */
    xs_pivot(pivo);
    while(1){
        xd_vet(vet, size, "gycm", i, j, C, F);
        while((vet[i] < pivo) && (i <= F)){ 
            i++;
            xd_vet(vet, size, "gycm", i, j, C, F); 
        }
        while((vet[j] > pivo) && (j >= C)){
            xd_vet(vet, size, "gycm", i, j, C, F); 
            j--;
        }
        if(i > j)
            break;
        xd_vet(vet, size, "rrcm", i, j, C, F);
        X_SWAP(vet[i], vet[j], int);
        xd_vet(vet, size, "gycm", i, j, C, F);
        i++;
        j--;
    }
    xd_vet(vet, size, "gycm", i, j, C, F);
    X_SWAP(vet[C], vet[j], int);
    xd_vet(vet, size, "gcym", i, j, C, F);
    quick(vet, size, C, j - 1);
    quick(vet, size, j + 1, F);
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

    quick(vet, size, 0, size - 1);
    xs_pivot(0);
    verify(vet, size);
    xs_jump(1); //interativo
    xd_vet(vet, size, "");
    x_close();

    return 0;
 }

