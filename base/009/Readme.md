## #maze CasteloGrade

![](__capa.jpg)
**Descrição da função**

Você recebe uma grade quadrada com algumas células abertas (.) e outras bloqueadas (X). Sua peça de jogo pode se mover ao longo de qualquer linha ou coluna até atingir a borda da grade ou uma célula bloqueada. Dada uma grade, uma posição inicial e uma posição final, determine o número de movimentos necessários para chegar à posição final.<br>

Por examplo, você recebe uma grade com os lados n = 3 descritos a seguir:<br>

...<br>
.X.<br>
...<br>

Sua posição inicial para começar no canto superior esquerdo é (startX,startY)=(0,0). A posição final é (goalX,goalY)=(1,2). O caminho é (0,0)->(0,2)->(1,2). É preciso 2 movimentos para chegar ao objetivo.<br>

**Formato de entrada**

A primeira linha contém um inteiro n, o tamanho do vetor grade.<br>
Cada uma das seguintes n linhas contém uma string de tamanho n.<br>
A última linha contém quatro números inteiros separados por espaço, startX, startY, goalX, goalY.<br>

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