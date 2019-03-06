## [vet][QE0002] L4 - Cabeças vão Rolar v3

[![](logo.jpg)](https://www.youtube.com/watch?v=uCsD3ZGzMgE)


Esse jogo é equivalente ao V2 porém com duas diferenças.
- Após matar, a espada salta um número de vezes igual ao último que utilizou a espada. Se o elemento que matou é positivo, a espada salta para direita, se não, salta para esquerda.

---
- Entrada:
    - Os valores de **N** e **E** e **F** na primeira linha.
- Saída:
    - Etapa a etapa, os elementos que estão vivos na fila circular.
        - Indicando com um > ou < quem está com a espada dependendo se é positivo ou negativo.

---

- Implemente esse problemas utilizando as seguintes abordagens:
    - utilizando um vetor
        - marcando os elementos que morrem.
        - retirando os elementos que morrem e diminuindo o tamanho do vetor.
    - utilizando um lista circular **dupla**  sem nós de marcação. 


Testes:

```
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
[ <-2 3 ]
[ <-2 ]
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
[ -1 2> ]
[ 2> ]
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
[ -2 3> -4 ]
[ <-2 3 ]
[ <-2 ]
<<<<<<<<

>>>>>>>> 09
4 3 1
========
[ 1 -2 3> -4 ]
[ 1 -2 3> ]
[ <-2 3 ]
[ <-2 ]
<<<<<<<<

>>>>>>>> 10
4 4 1
========
[ 1 -2 3 <-4 ]
[ 1 <-2 -4 ]
[ <-2 -4 ]
[ <-2 ]
<<<<<<<<

>>>>>>>> 11
6 3 -1
========
[ -1 2 <-3 4 -5 6 ]
[ -1 -3 4 <-5 6 ]
[ -1 <-3 -5 6 ]
[ <-3 -5 6 ]
[ -3 <-5 ]
[ <-5 ]
<<<<<<<<

>>>>>>>> 12
9 9 1
========
[ 1 -2 3 -4 5 -6 7 -8 9> ]
[ <-2 3 -4 5 -6 7 -8 9 ]
[ -2 3 -4 5 -6 7> -8 ]
[ <-2 3 -4 5 -6 7 ]
[ -2 3 -4 5> -6 ]
[ <-2 3 -4 5 ]
[ -2 3> -4 ]
[ <-2 3 ]
[ <-2 ]
<<<<<<<<

>>>>>>>> 13
20 1 1
========
[ 1> -2 3 -4 5 -6 7 -8 9 -10 11 -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3> -4 5 -6 7 -8 9 -10 11 -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3 5 -6 7> -8 9 -10 11 -12 13 -14 15 -16 17 -18 19 -20 ]
[ 1 3 5 -6 7 9 -10 11 -12 13 -14 15> -16 17 -18 19 -20 ]
[ 1 3 5 -6 7 9 -10 11 -12 13 <-14 15 17 -18 19 -20 ]
[ 1 3 5 -6 7 9 -10 11 -12 -14 15> 17 -18 19 -20 ]
[ 1 3 5 -6 7 9 -10 11 -12 -14 15 <-18 19 -20 ]
[ 1 3 5 -6 7 9> -10 11 -12 -14 -18 19 -20 ]
[ 1 3 5> -6 7 9 11 -12 -14 -18 19 -20 ]
[ 1 3 5 7 9 11 -12 <-14 -18 19 -20 ]
[ 1 3 5> 7 9 11 -14 -18 19 -20 ]
[ 1 3 5 9 11 -14 -18 19> -20 ]
[ 1 3 5> 9 11 -14 -18 19 ]
[ 1> 3 5 11 -14 -18 19 ]
[ 1 5> 11 -14 -18 19 ]
[ 1 5> -14 -18 19 ]
[ 1 5 <-18 19 ]
[ 1 <-18 19 ]
[ <-18 19 ]
[ <-18 ]
<<<<<<<<



```


