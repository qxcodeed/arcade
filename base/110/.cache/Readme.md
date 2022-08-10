## @110 L2 - {human} lab create


Crie um labirinto perfeito. Em um labirinto perfeito, entre dois pontos quaisquer existem apenas um caminho.

Passe os parâmetros de número de linhas e de colunas através dos argumentos do programa.

Leia sobre argc e argv ou use o exemplo abaixo.

```c
int main(int argc, char * argv[]){
    int nl = 10, nc = 30;
    if(argc > 2){
        nl = atoi(argv[1]);
        nc = atoi(argv[2]);
    }
}
```

Exemplo:

```
./gerar_matriz 15 40
15 40
########################################
# #    # #    #       ## #  # # #   #  #
#   # #    # #  #####     #     # #  # #
## #  # ##  #  #    ## ##  # ###   #   #
# #  #    # # # # #    # # #     # ## ##
#  # # ## # # #   # ###     ### # #   ##
##   ##   # #  # # #  # ####   #    #  #
#  ##   ##  # #  #  # # #    #   ###  ##
# ##  ## # # #  # #   #   # # # #   #  #
#    ##    #   #  ## ##### #   #  #   ##
#####   ######  #     #    # #   # # # #
#    # #   #   #  ###   ##    ###   #  #
## ##    ##  ### #   ###  # ##    #   ##
#     ##    #      #     #     # #  #  #
########################################
```

---
## Algoritmo Recursivo

O labirinto pode ser construído de forma recursiva:

```
bool pode_furar(posicao):
    se quantidade de vizinhos com paredes menor que 3
        retorne false
    retorne true

void derrubar_parede(mat, posicao):
    if pode_furar(posicao)
        matriz nessa posicao = ' '
    crie um vetor com os vizinhos
    embaralhe o vetor de vizinho
    chama derrubar_parede para todos os vizinhos

int main():
    criar 'matriz'
    colocar paredes em todas as posicoes da matriz
    derrubar_parede(inicio)

```

