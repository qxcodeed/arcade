## L3 - slide

![](cover.jpg)

**Descrição da função**

Nesse problema, você recebe uma grade quadrada com algumas células abertas (.) e outras bloqueadas (X).

Sua peça de jogo pode se mover ao longo de qualquer linha ou coluna até atingir a borda da grade ou uma célula bloqueada. 

Ela não pode parar no meio do caminho, ela deverá seguir em linha reta até encontrar um obstáculo OU encontrar o objetivo.

Dada uma grade, uma posição inicial e uma posição final, determine o número de movimentos necessários para chegar à posição final.

Por exemplo, você recebe uma grade com os lados n = 3 descritos a seguir:

```
...
.X.
...
```
- As posições são pares linha e coluna no formato (l,c).
- Se posição inicial para começar no canto superior esquerdo é (startL,startC)=(0,0) e posição final é (goalL,goalC)=(1,2).
- Teríamos essa configuração sendo `s` para start e `g` para goal, as seguintes posições de linha e coluna. 
```
s..
.Xg
...
```
- O caminho é (0,0)->(0,2)->(1,2). É preciso 2 movimentos para chegar ao objetivo.
- Lembre que a peça não move as posições uma a uma, mas salta até o limite.

**Formato de entrada**

A primeira linha contém um inteiro n, o tamanho do vetor grade.

Cada uma das seguintes n linhas contém uma string de tamanho n.

A última linha contém quatro números inteiros separados por espaço, startL, startC, goalL, goalC.


**Formato de saída**

Imprima um número inteiro indicando o número mínimo de etapas necessárias para mover o castelo para a posição do objetivo.


## Testes

```
>>>>>>>> 01
3
.X.
.X.
...
0 0 0 2
========
3
<<<<<<<<

>>>>>>>> 02
3
...
.X.
.X.
2 0 0 2
========
2
<<<<<<<<

>>>>>>>> 03
3
...
.X.
.X.
2 0 2 2
========
3
<<<<<<<<

>>>>>>>> 04
40
...X......XX.X...........XX....X.XX.....
.X..............X...XX..X...X........X.X
......X....X....X.........X...........X.
.X.X.X..X........X.....X.X...X.....X..X.
....X.X.X...X..........X..........X.....
..X......X....X....X...X....X.X.X....XX.
...X....X.......X..XXX.......X.X.....X..
...X.X.........X.X....X...X.........X...
XXXX..X......X.XX......X.X......XX.X..XX
.X........X....X.X......X..X....XX....X.
...X.X..X.X.....X...X....X..X....X......
....XX.X.....X.XX.X...X.X.....X.X.......
.X.X.X..............X.....XX..X.........
..X...............X......X........XX...X
.X......X...X.XXXX.....XX...........X..X
...X....XX....X...XX.X..X..X..X.....X..X
...X...X.X.....X.....X.....XXXX.........
X.....XX..X.............X.XX.X.XXX......
.....X.X..X..........X.X..X...X.X......X
...X.....X..X.............X......X..X..X
........X.....................X....X.X..
..........X.....XXX...XX.X..............
........X..X..........X.XXXX..X.........
..X..X...X.......XX...X.....X...XXX..X..
.X.......X..............X....X...X....X.
.................X.....X......X.....X...
.......X.X.XX..X.XXX.X.....X..........X.
X..X......X..............X..X.X.......X.
X........X.....X.....X....XX.......XX...
X.....X.................X.....X..X...XXX
XXX..X..X.X.XX..X....X.....XXX..X......X
..........X.....X.....XX................
..X.........X..X.........X...X.....X....
.X.X....X...XX....X...............X.....
.X....X....XX.XX........X..X............
X...X.X................XX......X..X.....
..X.X.......X.X..X.....XX.........X..X..
........................X..X.XX..X......
........X..X.X.....X.....X......X.......
.X..X....X.X......XX....................
34 28 16 8
========
9
<<<<<<<<
```