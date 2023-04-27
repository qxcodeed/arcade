## @005 L1 - vector rec

![_](https://github.com/qxcodeed/arcade/blob/master/base/005/cover.jpg)

Leia um vetor de inteiros e implemente as funções sem utilizar laço para iterar sobre os elementos.

___

- Entrada
  - um vetor de inteiros. O vetor tem no mínimo 1 elemento.
- Saída
  - vet: o vetor
  - rvet: o vetor impresso ao contrário
  - sum: a soma dos elementos
  - mult: a multiplicação dos elementos
  - min: o menor elemento
  - inv: inverte o vetor, depois imprime ele invertido

Todas as funções devem ser recursivas e estão escritas da seguinte forma:

```cpp
// init: aponta para o primeiro elemento do vetor
// end: aponta para uma posição depois do último elemento do vetor
void show(int * init, int * end) {

}

// Exemplo de chamada
int vet[4] = {5, 6, 7, 2};
show(vet, vet + 4);
```

## Arquivos

- Você deve implementar:
  - [student.cpp](https://github.com/qxcodeed/arcade/blob/master/base/005/student.cpp)
    - As funções a serem implementadas.
- Já está implementado:
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/005/main.cpp)
    - Faz a leitura do vetor inicial e chama as funções.
  - [lib.hpp](https://github.com/qxcodeed/arcade/blob/master/base/005/lib.hpp)
    - Apenas os cabeçalhos.

___

## Testes

```txt
>>>>>>>> 01
4
========
vet : [ 4 ]
rvet: [ 4 ]
sum : 4
mult: 4
min : 4
inv : [ 4 ]
<<<<<<<<

>>>>>>>> 02
3 4 2
========
vet : [ 3 4 2 ]
rvet: [ 2 4 3 ]
sum : 9
mult: 24
min : 2
inv : [ 2 4 3 ]
<<<<<<<<

>>>>>>>> 03
1 2 3 4
========
vet : [ 1 2 3 4 ]
rvet: [ 4 3 2 1 ]
sum : 10
mult: 24
min : 1
inv : [ 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 04
1 2 3 4 0
========
vet : [ 1 2 3 4 0 ]
rvet: [ 0 4 3 2 1 ]
sum : 10
mult: 0
min : 0
inv : [ 0 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 05
1 2 3 4 2 3
========
vet : [ 1 2 3 4 2 3 ]
rvet: [ 3 2 4 3 2 1 ]
sum : 15
mult: 144
min : 1
inv : [ 3 2 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 06
1 2 3 4 7 2 9
========
vet : [ 1 2 3 4 7 2 9 ]
rvet: [ 9 2 7 4 3 2 1 ]
sum : 28
mult: 3024
min : 1
inv : [ 9 2 7 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 07
0 1 2 3 -4 -7 -2
========
vet : [ 0 1 2 3 -4 -7 -2 ]
rvet: [ -2 -7 -4 3 2 1 0 ]
sum : -7
mult: 0
min : -7
inv : [ -2 -7 -4 3 2 1 0 ]
<<<<<<<<

```
