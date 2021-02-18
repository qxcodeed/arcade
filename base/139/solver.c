#include <stdio.h>
#include "../libs/xpaint.h"
#include "../libs/xvet.h"

int main() {

    x_open(600, 300);

    int vet[15];
    int size = sizeof(vet)/sizeof(int);
    for(int i = 0; i < size; i++) //preenchendo o vetor
        vet[i] = 10 * (i + 1); 

    xs_pivot(vet[4]); //definindo o referencial (red line)
    xs_partition(1, 13); //marcando a partição  (yellow bar below)
    xd_vet(vet, size, "");

    for(int i = 1; i < size - 3; i++)
       xd_vet(vet, size, "rgby", i, i + 1, i + 2, 4);
    x_close();

    return 0;
 }

