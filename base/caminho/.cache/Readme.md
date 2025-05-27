# Fila: Menor caminho entre dois pontos

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/caminho/cover.jpg)

Dessa vez, o labirinto não é perfeito e existem múltiplos caminhos que podem levar ao destino. Seu objetivo é implementar o algoritmo de floodfill pathfinding.

Leia uma matriz que representa um labirinto perfeito, os pontos de inicio e fim e imprima o labirinto mostrando o caminho entre os pontos.

- Entrada
  - Linha 1: número de linhas e das colunas da matriz
  - Linhas subsequentes: matriz composta por 4 caracteres
    - `#` representa uma parede
    - ` ` representa um corredor por onde se pode andar
    - `I` representa o início
    - `F` representa o fim

- Saída
  - Imprima a matriz utilizando o char `.` para mostrar o caminho entre início e fim

## Explicação

- Nos algorítmos de queimada e fuga, utilizamos uma busca em profundidade (Depth-First Search, DFS) para encontrar um caminho. No entanto, isso não garante que o caminho encontrado seja o mais curto. No DFS, a gente explora um caminho o mais longe possível antes de retroceder. É bom para encontrar qualquer caminho, mas não necessariamente o mais curto. Usava uma pilha.
- Para garantir que encontramos o caminho mais curto, utilizamos uma busca em largura (Breadth-First Search, BFS). A BFS explora todos os vizinhos de um nó antes de avançar para o próximo nível. Isso garante que encontraremos o menor caminho em termos de número de passos em um grafo não ponderado (como um labirinto onde cada passo custa o mesmo). E por isso usamos uma fila.
- A BFS funciona da seguinte forma:
  - Começamos na posição inicial e marcamos essa posição como visitada.
  - Colocamos a posição inicial em uma fila.
  - Enquanto a fila não estiver vazia, fazemos o seguinte:
    - Pegamos a posição da frente da fila.
    - Verificamos todos os vizinhos dessa posição (cima, baixo, esquerda, direita).
    - Se um vizinho não for uma parede e ainda não tiver sido visitado, marcamos esse vizinho como visitado, adicionamos à fila e atualizamos a matriz de distâncias.
    - Se encontrarmos o destino, podemos parar.

## Sugestão do algoritmo

```go
crie uma fila queue
empilhe o ponto inicial na fila
crie um mapa para marcar os nós visitados
marque o ponto inicial como visitado
crie um mapa caminho<Pos, Pos> para guardar quem é o anterior de cada nó
enquanto a fila não estiver vazia:
    desempilhe o nó atual da fila
    se o nó atual for o destino:
        pare
    para cada vizinho do nó atual:
        se o vizinho não foi visitado e não é uma parede:
            marque o vizinho como visitado
            adicione o vizinho na fila
            registre o nó atual como anterior do vizinho no mapa caminho
utilize o mapa caminho para reconstruir o caminho
```

## Testes

```txt
>>>>>>>>
10 20
####################
#   # # # #   # ## #
###       ###      #
##  ## ##     ### ##
# I##   ### ###    #
# ##### #   #   ## #
# #     ## ### ##  #
# ## ####   #  #  ##
#   F     #   ## ###
####################
========
####################
#   # # # #   # ## #
###       ###      #
##  ## ##     ### ##
#..##   ### ###    #
#.##### #   #   ## #
#.#     ## ### ##  #
#.## ####   #  #  ##
#....     #   ## ###
####################
<<<<<<<<


>>>>>>>>
10 30
##############################
#           ## # # ##       ##
## # ## ## ##    # #  ## ##  #
## ###  #I    ##   ####   ## #
#  ##  ##### ### #   #  #  # #
# ##  ## F ###   ### ####### #
# ## ### # #   #   # ##   #  #
#  #   # #   ##### # #  # # ##
##   #     #     #     ##    #
##############################
========
##############################
#           ## # # ##       ##
## # ## ## ##....# #  ## ##  #
## ###  #.....##.  ####   ## #
#  ##  ##### ###.#   #  #  # #
# ##  ## ..###...### ####### #
# ## ### #.#...#   # ##   #  #
#  #   # #...##### # #  # # ##
##   #     #     #     ##    #
##############################
<<<<<<<<
```
