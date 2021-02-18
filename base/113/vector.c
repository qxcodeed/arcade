#include <stdio.h>
#include <stdbool.h>

const long MORTO = 0;

//acha o proximo elemento vivo a partir de inicio + 1
int achar_vivo(long vet[], long size, long inicio){
    long pos = (inicio + 1) % size;
    while(vet[pos] == MORTO)
        pos = (pos + 1) % size;
    return pos;
}

void mostrar_vetor(long vet[], long size, long e){
    printf("[");
    for(long i = 0; i < size; i++){
        if(vet[i] != MORTO)
            printf(" %ld", vet[i]);
        if(i == e)
            printf(">");
    }
    printf(" ]\n");
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
        long vai_morrer = achar_vivo(vet, size, esc);
        vet[vai_morrer] = 0;
        esc = achar_vivo(vet, size, vai_morrer);
        //mostrar_vetor(vet, size, esc);
    }
    mostrar_vetor(vet, size, esc);   
    free(vet);
}

