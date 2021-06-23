#include <stdio.h>
#include <stdbool.h>

const int MORTO = 0;

int walk(int pos, int size, int dir){
    if(dir == 1)
        return (pos + 1) % size;
    return (pos + size - 1) % size;
}

//acha o proximo elemento vivo a partir de inicio + 1
//dir é 1 ou -1
int achar_vivo(int vet[], int size, int inicio, int dir){
    int pos = walk(inicio, size, dir);
    while(vet[pos] == MORTO)
        pos = walk(pos, size, dir);
    return pos;
}

void mostrar_vetor(int vet[], int size, int e){
    printf("[");
    for(int i = 0; i < size; i++){
        if(vet[i] != MORTO){
            printf(" ");
            if((i == e) && (vet[i] < 0))
                printf("<");
            printf("%d", vet[i]);
            if((i == e) && (vet[i] > 0))
                printf(">");
        }
    }
    printf(" ]\n");
}

int main(){
    int size = 0;
    int esc = 0; //o escolhido
    int fase = 0;
    scanf("%d %d %d", &size, &esc, &fase);
    int vet[size];
    for(int i = 0; i < size; i++){
        vet[i] = (i + 1) * fase;
        fase *= -1;
    }
    esc = esc - 1;
    mostrar_vetor(vet, size, esc);
    int qtd = size - 1;
    while(qtd--){
        int dir = vet[esc] > 0 ? 1 : -1;
        int vai_morrer = achar_vivo(vet, size, esc, dir);
        vet[vai_morrer] = 0;
        esc = achar_vivo(vet, size, vai_morrer, dir);
        mostrar_vetor(vet, size, esc);
    }
}

