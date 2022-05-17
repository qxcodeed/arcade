## L2 - {interactive} Algoritmo de criação de labirinto com pilha
## @qxcode


## Criando um labirinto com pilha
```
void create_lab_pilha(mat){
    inicie uma pilha de posições
    fure o primeiro elemento e coloque na pilha

    enquanto a pilha nao estiver fazia faca {
        'topo' eh a posição do topo da pilha
        pegue os vizinhos de 'topo' que podem ser furados
            voce soh pode pegar os vizinhos que tem no máximo um lado aberto
        se existe pelo menos um vizinho valido pra furar
            selecione aleatoriamente um desses vizinhos
            fure e empilhe
        se nao existe
            desempilhe o topo
    }
}
```