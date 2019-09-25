## $03_maze  2. Queimada V2 Busca em profundidade      #doing
## @qxcode

![](__capa.jpg)

Busca em profundidade

Refaça o problema da queimada utilizando pilha no lugar da recursão.

Você pode utilizar esse algoritmo.

```
verifique a primeira posição e queime-o
inicie a fila com esse elemento
enquanto a fila não estiver vazia faça
    pegue topo da fila

    faça uma lista com todos os vizinhos de topo que podem ser queimados
    se lista eh vazia
        desempilhe
    senão
        escolha um dos vizinhos
        queime
        empilhe
```


```
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
