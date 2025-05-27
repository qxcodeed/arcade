# Pilha: Queimando árvores

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/queimando/cover.jpg)

- Seja uma matriz de caracteres que representa um mapa de uma floresta.
- Cada caractere representa um espaço vazio ou uma árvore.
- O espaço vazio é representado por um ponto `.` e a árvore por uma hashtag `#`.
- O fogo começa em um ponto inicial e se espalha para os vizinhos até que não haja mais árvores para queimar.

Dado a matriz da floresta e o ponto inicial onde começa o fogo, queime as árvores. O fogo não se espalha nas diagonais, apenas nas 4 direções cardeais.

## Entrada

- 1a linha: `nl, nc, l, c`:
  - Número de linhas e colunas da matriz, linha e coluna onde começa o fogo.
- Nas linhas subsequentes a matriz da floresta sendo que
  - '\#' representa uma árvore
  - '.' representa um espaço vazio

## Saída

- A matriz após a queimada acontecer colocando 'o' para cada árvore queimada.

## Rascunhos

<!-- links .cache/draft -->
- go
  - [main.go](https://github.com/qxcodeed/arcade/blob/master/base/queimando/.cache/draft/go/main.go)
  - [pilha.go](https://github.com/qxcodeed/arcade/blob/master/base/queimando/.cache/draft/go/pilha.go)
<!-- links -->

## Testes

```txt
>>>>>>>> 01
2 3 1 1
#.#
.##
========
#.o
.oo
<<<<<<<<

>>>>>>>> 02
5 5 0 0
#..#.
#...#
###..
..#.#
..###
========
o..#.
o...#
ooo..
..o.o
..ooo
<<<<<<<<

>>>>>>>> 03
5 7 2 0
#..#.#.
#..####
###...#
..#.###
#.###..
========
o..o.o.
o..oooo
ooo...o
..o.ooo
#.ooo..
<<<<<<<<

>>>>>>>> 04
5 5 0 0
...#.
#...#
###..
..#.#
..###
========
...#.
#...#
###..
..#.#
..###
<<<<<<<<

>>>>>>>> 05
10 40 0 3
..####..##.##.#..#.#####.##.####.#.#.###
.##.####..#####.##..##.#.###...##.#.#.#.
.#....#..##.#...#.#.#..#.##.#.###.#.###.
.###.#.##.##.######.###..##..#####.#..##
.##########.##########.########.######.#
.########.#####.###.########.#..##.####.
###.###..##.#..###.#.##.##.###..####.###
..######..#.#..#.###.##......####..#.###
######.##.##.#.####.####.##############.
##.##.#.###.###........###.##.####.###..
========
..oooo..##.oo.o..o.ooooo.oo.oooo.#.#.###
.oo.oooo..ooooo.oo..oo.o.ooo...oo.#.#.#.
.o....o..oo.o...o.o.o..o.oo.#.ooo.#.###.
.ooo.o.oo.oo.oooooo.ooo..oo..ooooo.o..##
.oooooooooo.oooooooooo.oooooooo.oooooo.#
.oooooooo.ooooo.ooo.oooooooo.o..oo.oooo.
ooo.ooo..oo.o..ooo.o.oo.oo.ooo..oooo.ooo
..oooooo..o.o..o.ooo.oo......oooo..o.ooo
oooooo.oo.oo.#.oooo.oooo.oooooooooooooo.
oo.oo.#.ooo.###........ooo.oo.oooo.ooo..
<<<<<<<<

```
