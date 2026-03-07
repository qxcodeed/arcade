# Escapando do labirinto

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/labirinto/cover.jpg)

Um labirinto perfeito é um labirinto no qual entre dois quaisquer pontos existe apenas um único caminho.

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
