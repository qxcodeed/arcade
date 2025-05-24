# Rotacoes em uma lista

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/rotacoes/cover.jpg)

Uma rotação desloca os elementos do vetor em uma determinada direção. Uma rotação à direita equivale a pegar o último elemento e inserir na primeira posição.

Implemente a operação de rotação. Observe que calculando as posições finais corretamente você fará uma única operação de transposição das posições do vetor.

- Entrada
  - Linha 1: tamanho do vetor `T` e número de elementos rotacionados `R`
  - Linha 2: elementos do vetor
- Saída
  - Vetor rotacionado

O custo do algorítmo deve ser O(N).

```txt
>>>>>>>>
5 0
1 2 3 4 5
========
[ 1 2 3 4 5 ]
<<<<<<<<

>>>>>>>>
5 1
1 2 3 4 5
========
[ 5 1 2 3 4 ]
<<<<<<<<

>>>>>>>>
5 4
1 2 3 4 5
========
[ 2 3 4 5 1 ]
<<<<<<<<

>>>>>>>>
5 9
1 2 3 4 5
========
[ 2 3 4 5 1 ]
<<<<<<<<


```
