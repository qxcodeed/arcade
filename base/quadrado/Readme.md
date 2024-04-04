# L2 - @quadrado - Aragão calculando n ao quadrado

Aragão está profundamente envolvido em seu aprendizado sobre recursão. Recentemente, ele fez uma descoberta fascinante: o cálculo de $n^2$ pode ser expresso de maneira recursiva por meio da seguinte fórmula iterativa: $(n+1)^2 = n^2 + 2n + 1$, começando com $1^2 = 1$ como caso base.

Empolgado com essa revelação, Aragão deseja desenvolver um algoritmo recursivo que não apenas calcule $n^2$, mas também mostre cada passo do processo. No entanto, ele enfrenta algumas dificuldades para elaborar tal algoritmo. É aí que entra a sua ajuda.

## Entrada

A entrada é composta por uma única linha contendo um inteiro $n$

## Saída

A saída é composta por várias linhas mostrando o passo-a-passo do algoritmo recursivo.

## Exemplo de Entrada

```txt
10
```

## Exemplo de Saída

```txt
10^2 = 9^2 + 2*9 + 1 = ?
9^2 = 8^2 + 2*8 + 1 = ?
8^2 = 7^2 + 2*7 + 1 = ?
7^2 = 6^2 + 2*6 + 1 = ?
6^2 = 5^2 + 2*5 + 1 = ?
5^2 = 4^2 + 2*4 + 1 = ?
4^2 = 3^2 + 2*3 + 1 = ?
3^2 = 2^2 + 2*2 + 1 = ?
2^2 = 1^2 + 2*1 + 1 = ?
1^2 = 1
2^2 = 1^2 + 2*1 + 1 = 4
3^2 = 2^2 + 2*2 + 1 = 9
4^2 = 3^2 + 2*3 + 1 = 16
5^2 = 4^2 + 2*4 + 1 = 25
6^2 = 5^2 + 2*5 + 1 = 36
7^2 = 6^2 + 2*6 + 1 = 49
8^2 = 7^2 + 2*7 + 1 = 64
9^2 = 8^2 + 2*8 + 1 = 81
10^2 = 9^2 + 2*9 + 1 = 100
```
