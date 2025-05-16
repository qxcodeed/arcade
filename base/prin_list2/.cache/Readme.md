# Princesa2 com lista ligada

[![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/prin_list2/../princesa-lista-2/cover.jpg)](https://www.youtube.com/watch?v=uCsD3ZGzMgE)

Esse jogo é equivalente ao V1 porém com duas diferenças.

- Números positivos e negativos se alternam. Se tivermos 5 participantes e o primeiro for negativo, então nosso vetor será:
  - `[ -1 2 -3 4 -5 ]`
- O valor de F, denominado fase, poderá ter os valor 1 ou -1 e indica se o primeiro participante será positivo ou negativo.
- Se a espada estiver com um participante com número negativo:
  - Ele deverá matar o participantes à sua esquerda.
  - Depois deverá passar a espada para o participante à sua esquerda.
- Se a espada estiver com um participante de número positivo
  - Ele deverá matar o participante à sua direita no vetor.
  - Depois passar a espada para o participante a sua direita.

___

- Entrada:
  - Os valores de **N** e **E** e **F** na primeira linha.
- Saída:
  - Etapa a etapa, os elementos que estão vivos na fila circular.
    - Indicando com um > ou < quem está com a espada dependendo se é positivo ou negativo.

___
Implemente utilizando o algoritmo utilizando a estrutura list do c++.

Testes:

```txt
>>>>>>>> 01
3 1 1
========
[ 1> -2 3 ]
[ 1 3> ]
[ 3> ]
<<<<<<<<

>>>>>>>> 02
3 2 1
========
[ 1 <-2 3 ]
[ -2 3> ]
[ 3> ]
<<<<<<<<

>>>>>>>> 03
3 3 1
========
[ 1 -2 3> ]
[ <-2 3 ]
[ <-2 ]
<<<<<<<<

>>>>>>>> 04
3 1 -1
========
[ <-1 2 -3 ]
[ -1 2> ]
[ 2> ]
<<<<<<<<

>>>>>>>> 05
3 2 -1
========
[ -1 2> -3 ]
[ <-1 2 ]
[ <-1 ]
<<<<<<<<

>>>>>>>> 06
3 3 -1
========
[ -1 2 <-3 ]
[ <-1 -3 ]
[ <-1 ]
<<<<<<<<

>>>>>>>> 07
4 1 1
========
[ 1> -2 3 -4 ]
[ 1 3> -4 ]
[ 1> 3 ]
[ 1> ]
<<<<<<<<

>>>>>>>> 08
4 2 1
========
[ 1 <-2 3 -4 ]
[ -2 3 <-4 ]
[ <-2 -4 ]
[ <-2 ]
<<<<<<<<

>>>>>>>> 09
4 3 1
========
[ 1 -2 3> -4 ]
[ 1> -2 3 ]
[ 1 3> ]
[ 3> ]
<<<<<<<<

>>>>>>>> 10
4 4 1
========
[ 1 -2 3 <-4 ]
[ 1 <-2 -4 ]
[ -2 <-4 ]
[ <-4 ]
<<<<<<<<

>>>>>>>> 11
6 3 -1
========
[ -1 2 <-3 4 -5 6 ]
[ <-1 -3 4 -5 6 ]
[ -1 -3 4 <-5 ]
[ -1 <-3 -5 ]
[ -3 <-5 ]
[ <-5 ]
<<<<<<<<

>>>>>>>> 12
9 9 1
========
[ 1 -2 3 -4 5 -6 7 -8 9> ]
[ <-2 3 -4 5 -6 7 -8 9 ]
[ -2 3 -4 5 -6 7 <-8 ]
[ -2 3 -4 5 <-6 -8 ]
[ -2 3 <-4 -6 -8 ]
[ <-2 -4 -6 -8 ]
[ -2 -4 <-6 ]
[ <-2 -6 ]
[ <-2 ]
<<<<<<<<

>>>>>>>> 13
20 1 1
========
[ 1> -2 3 -4 5 -6 7 -8 9 -10 11 -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3> -4 5 -6 7 -8 9 -10 11 -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3 5> -6 7 -8 9 -10 11 -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3 5 7> -8 9 -10 11 -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3 5 7 9> -10 11 -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3 5 7 9 11> -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3 5 7 9 11 13> -14 15 -16 17 -18 19 -20 ]
[ 1 3 5 7 9 11 13 15> -16 17 -18 19 -20 ]
[ 1 3 5 7 9 11 13 15 17> -18 19 -20 ]
[ 1 3 5 7 9 11 13 15 17 19> -20 ]
[ 1> 3 5 7 9 11 13 15 17 19 ]
[ 1 5> 7 9 11 13 15 17 19 ]
[ 1 5 9> 11 13 15 17 19 ]
[ 1 5 9 13> 15 17 19 ]
[ 1 5 9 13 17> 19 ]
[ 1> 5 9 13 17 ]
[ 1 9> 13 17 ]
[ 1 9 17> ]
[ 9> 17 ]
[ 9> ]
<<<<<<<<



```
