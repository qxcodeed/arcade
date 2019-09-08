#include <stdio.h>
//#include "../libs/xpaint.h"
//#include "../libs/xvet.h"


#define SUAPI(a, b, tipo)\
do{\
    tipo SUAPI = a;\
    a = b;\
    b = SUAPI;\
}while(0)


//encontra o menor [inicio, fim[
int find_imenor(int vet[], int inicio, int fim){
    int imenor = inicio;
    for(int i = inicio + 1; i < fim; i++)
        if(vet[i] < vet[imenor])
            imenor = i;
    return imenor;
}

/* int selection(int vet[], int size){
    do{

    }while(0)
} */

int main() {

    int aux = 4;
    int y = 7;
    SUAPI(aux, y, int);
    printf("%d %d\n", aux, y);

    float f1 = 5.6;
    float f2 = 4.5;
    SUAPI(f1, f2, float);
    printf("%f %f\n", f1, f2);

    char * c1 = "banana";
    char * c2 = "maca";
    SUAPI(c1, c2, char *);
    printf("%s %s\n", c1, c2);

    return 0;
}

