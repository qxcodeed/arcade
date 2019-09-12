#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _print(int vet[], int size){
    if(size == 0)
        return;
    printf(" %d", vet[0]);
    _print(vet + 1, size - 1);
}

void print(int vet[], int size){
    printf("[");
    _print(vet, size);
    printf(" ]\n");
}

void _rprint(int vet[], int size){
    if(size == 0)
        return;
    _rprint(vet + 1, size - 1);
    printf(" %d", vet[0]);
}

void rprint(int vet[], int size){
    printf("[");
    _rprint(vet, size);
    printf(" ]\n");
}

int sum(int vet[], int size){
    if(size == 0)
        return 0;
    return vet[size - 1] + sum(vet, size - 1);
}

int mult(int vet[], int size){
    if(size == 0)
        return 1;
    return vet[size - 1] * mult(vet, size - 1);
}

int menor(int vet[], int size){
    if(size == 0)
        return 9999999;
    int menor_outros = menor(vet, size - 1);
    return vet[size - 1] < menor_outros ? vet[size - 1] : menor_outros;
}

void inverter(int vet[], int size){
    if(size < 2)
        return;
    int c = vet[0];
    vet[0] = vet[size - 1];
    vet[size - 1] = c;
    inverter(vet + 1, size - 2); 
}

int main(){
    int vet[1000];
    int size = 0;
    int value = 0;
    while(scanf("%d", &value) > 0)
        vet[size++] = value;

    printf("vet : "); print(vet, size);
    printf("rvet: "); rprint(vet, size);
    printf("sum : %d\n", sum(vet, size));
    printf("mult: %d\n", mult(vet, size));
    printf("min : %d\n", menor(vet, size));
    inverter(vet, size);
    printf("inv : "); print(vet, size);

} 