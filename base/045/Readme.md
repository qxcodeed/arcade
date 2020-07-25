## #tree 3. Tree Altura e Nível
## @qxcode

![](__capa.jpg)

- Entrada
    - linha 1: o serial de uma árvore
    - linha 2: uma lista de valores de nó
- Saída
    - Para cada nó da lista, um nó por linha, altura e profundidade do nó ou -1 se o nó não for encontrado

![](__altura.jpg)

```
>>>>>>>> 01 um
4 # # 
4
========
1 1
<<<<<<<<

>>>>>>>> 02 dois
1 # 0 # # 
0 1
========
1 2
2 1
<<<<<<<<

>>>>>>>> 03 tres
4 # 8 2 # # # 
2 8 4
========
1 3
2 2
3 1
<<<<<<<<

>>>>>>>> 04 quatro
0 9 4 # # # 5 # # 
5 4 3 0 9
========
1 2
1 3
0 0
3 1
2 2
<<<<<<<<

>>>>>>>> 05 cinco
8 4 # # 2 0 # # 3 # # 
0 4 8 2 3 7
========
1 3
1 2
3 1
2 2
1 3
0 0
<<<<<<<<

>>>>>>>> 06 seis
2 1 0 # # # 3 # 7 # 9 # # 
9 7 3 6 1 2 0
========
1 4
2 3
3 2
0 0
2 2
4 1
1 3
<<<<<<<<

>>>>>>>> 07 dez
1 8 7 # # 4 # 6 # # 5 0 # # 9 # 3 2 # # # 
1 2 3 4 5 6 7 8 9
========
5 1
1 5
2 4
2 3
4 2
1 4
1 3
3 2
3 3
<<<<<<<<

```
