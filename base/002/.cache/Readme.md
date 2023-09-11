# @002 L2 - triangle

Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/002/Readme.md)

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/002/cover.jpg)

Dado um vetor de inteiros A, imprima um triângulo de números tal que na base do triângulo estejam todos os elementos do vetor original, e tal que, a cada i-ésimo nível acima da base, o número de elementos seja um a menos que no nível inferior e cada elemento do i-ésimo nível seja a soma de dois elementos consecutivos do nível inferior.

- Entrada
  - Os elementos da base.
- Saída
  - O triângulo.

## Dica

Veja a resolução da atividade "Empilhamento da Recursão" para entender como funciona a impressão de trás pra frente.

## Arquivos

- Você deve implementar:
  - [student.cpp](https://github.com/qxcodeed/arcade/blob/master/base/002/student.cpp)
    - escrever a função que processa uma linha do triângulo, chama a recursão e imprime.
- Já está implementado:
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/002/main.cpp)
    - Faz a leitura do vetor inicial e chama a função recursiva.
  - [lib.hpp](https://github.com/qxcodeed/arcade/blob/master/base/002/lib.hpp)
    - Apenas o cabeçalho.

## Testes

```txt

>>>>>>>> 01
1 2 3
========
[ 8 ]
[ 3 5 ]
[ 1 2 3 ]
<<<<<<<<

>>>>>>>> 02
3 2 1
========
[ 8 ]
[ 5 3 ]
[ 3 2 1 ]
<<<<<<<<

>>>>>>>> 03
4 3 2 1
========
[ 20 ]
[ 12 8 ]
[ 7 5 3 ]
[ 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 04
1 1 2 3 5 8
========
[ 89 ]
[ 34 55 ]
[ 13 21 34 ]
[ 5 8 13 21 ]
[ 2 3 5 8 13 ]
[ 1 1 2 3 5 8 ]
<<<<<<<<

>>>>>>>> 05
1 2 4 8 16 32 64
========
[ 729 ]
[ 243 486 ]
[ 81 162 324 ]
[ 27 54 108 216 ]
[ 9 18 36 72 144 ]
[ 3 6 12 24 48 96 ]
[ 1 2 4 8 16 32 64 ]
<<<<<<<<

```
