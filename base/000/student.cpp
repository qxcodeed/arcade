#include <stdio.h>
#include <stdbool.h>

const int MORTO = 0;

//acha o proximo elemento vivo a partir de inicio + 1
int achar_vivo(int vet[], int size, int inicio){
    int pos = (inicio + 1) % size;
    while(vet[pos] == MORTO)
        pos = (pos + 1) % size;
    return pos;
}

void mostrar_vetor(int vet[], int size, int e){
    printf("[");
    for(int i = 0; i < size; i++){
        if(vet[i] != MORTO)
            printf(" %d", vet[i]);
        if(i == e)
            printf(">");
    }
    printf(" ]\n");
}

int main(){
    int size = 0;
    scanf("%d", &size);
    int vet[size];
    for(int i = 0; i < size; i++)
        vet[i] = i + 1;
    int esc = 0; //o escolhido
    scanf("%d", &esc);
    esc = esc - 1;
    mostrar_vetor(vet, size, esc);
    int qtd = size - 1;
    while(qtd--){
        int vai_morrer = achar_vivo(vet, size, esc);
        vet[vai_morrer] = 0;
        esc = achar_vivo(vet, size, vai_morrer);
        mostrar_vetor(vet, size, esc);
    }
}

