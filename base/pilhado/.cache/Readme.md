# Pilha: Fugindo do labirinto

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/pilhado/cover.jpg)

Você vai tentar fugir do labirinto usando uma pilha no lugar da recursão.

Um labirinto perfeito é um labirinto no qual entre dois quaisquer pontos existe apenas um único caminho.

Leia uma matriz que representa um labirinto perfeito, os pontos de inicio e fim e imprima o labirinto mostrando o caminho entre os pontos.

- Entrada

  - Linha 1: número de linhas e das colunas da matriz
  - Linhas subsequentes: matriz composta por 4 caracteres
    - `#` representa uma parede.
    - ` ` (espaço vazio) representa um corredor por onde se pode andar.
    - `I` representa o início.
    - `F` representa o fim.

- Saída
  - Imprima a matriz utilizando o char `.` para mostrar o caminho entre início e fim

## Algoritmo

- Nosso algorítmo é uma busca em profundidade (DFS) iterativa.
- Vamos utilizar duas pilhas, uma vai armazenar o caminho percorrido até o nó atual e a outra vai armazenar os pontos que identificamos serem becos sem saída.
- Precisamos marcar os pontos visitados para não entrarmos em um loop infinito e também os becos sem saída para remover as marcacões de becos sem saída antes de imprimir o labirinto.
- Você pode utilizar a implementação de pilha que já vem na sua linguagem ou utilizar o modelo embutido no rascunho.

Para achar e marcar o caminho com `.` você pode seguir o seguinte pseudocódigo:

```txt
caminho = pilha()
becos = pilha()
caminho.push(inicio)
enquanto caminho não estiver vazia:
    atual = caminho.top()
    marcamos atual como visitado
    if atual é o fim:
        break
    validos = []
    for cada vizinho de atual:
        if vizinho não é parede e não foi visitado:
            validos.append(vizinho)
    if validos não estiver vazio:
        caminho.push(validos[0])
    else:
        marcamos beco como um beco sem saída
        adiciona posição à pilha de becos
        retira o topo da pilha de caminhos

remove as marcações de becos sem saída
```

## Testes

```txt
>>>>>>>>
10 20
####################
#   # # # #   # ## #
### #     ###      #
##  ## ##   # ### ##
# I##   ### ###    #
# ##### #   #   ## #
# #     ## ### ##  #
# ## ####   #  #  ##
#   F#    #   ## ###
####################
========
####################
#   # # # #   # ## #
### #     ###      #
##  ## ##   # ### ##
#..##   ### ###    #
#.##### #   #   ## #
#.#     ## ### ##  #
#.## ####   #  #  ##
#....#    #   ## ###
####################
<<<<<<<<


>>>>>>>>
10 30
##############################
#  #        ## # # ##       ##
## # ## ## ##    # #  ## ##  #
## ###  #I    ##   ####   ## #
#  ##  ###########   #  #  # #
# ##  ## F # #   ### ####### #
# ## ### ###   #   # ##   #  #
#  # # # #   ##### # #  # # ##
##   #     #     #     ##    #
##############################
========
##############################
#  #        ## # # ##       ##
## # ## ## ##....# #  ## ##  #
## ###  #.....##...####   ## #
#  ##  ###########...#  #  # #
# ##  ##.. # #...###.####### #
# ## ###.###...#...#.##   #  #
#  # # #.#...#####.#.#  # # ##
##   #  ...#     #...  ##    #
##############################
<<<<<<<<
```
