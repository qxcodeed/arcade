#include <stdio.h>
#include <stdbool.h>

void mostrar_vetor(long vet[], long size, long e){
    printf("[");
    for(long i = 0; i < size; i++){
        printf(" %ld", vet[i]);
        if(i == e)
            printf(">");
    }
    printf(" ]\n");
}

void kill(long vet[], long *size, long *e){
    long todie = (*e + 1) % *size;
    for(long i = todie; i < *size - 1; i++)
        vet[i] = vet[i + 1];
    if(todie < *e)
        *e =- 1;
    *size -= 1;
}

#include <stdlib.h>
int main(int argc, char * argv[]){
    if(argc == 1){
        puts("passe parametro de tamanho da instancia");
        return 1;
    }
    long size = 0;
    size = atol(argv[1]);
    //scanf("%d", &size);
    long * vet = (long *) malloc(size * sizeof(long));
    for(long i = 0; i < size; i++)
        vet[i] = i + 1;
    long esc = 1; //o escolhido
    esc = esc - 1;
    //mostrar_vetor(vet, size, esc);
    long qtd = size - 1;
    while(qtd--){
        kill(vet, &size, &esc);
        esc = (esc + 1) % size;
        //mostrar_vetor(vet, size, esc);
    }
    mostrar_vetor(vet, size, esc);   
    free(vet);
}

