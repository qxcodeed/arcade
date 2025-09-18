# LeetCode 329. Longest Increasing Path in a Matrix

## Intro

Dada uma matriz de inteiros de tamanho `m x n`, retorne o comprimento do caminho crescente mais longo presente na matriz.  

A partir de cada célula, é possível mover em **quatro direções**: esquerda, direita, cima ou baixo.  
Não é permitido mover na diagonal nem sair dos limites da matriz.

## Submission

Aqui, copiamos apenas alguns casos de teste do problema original, ao final, submeta seu código no LeetCode [nesse link](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/).

## Tests

```txt
>>>>>>>> INSERT Teste 1
3 3
9 9 4
6 6 8
2 1 1
======== EXPECT
4
<<<<<<<< FINISH


>>>>>>>> INSERT Teste 2
3 3
3 4 5
3 2 6
2 2 1
======== EXPECT
4
<<<<<<<< FINISH


>>>>>>>> INSERT Teste 3
1 1
1
======== EXPECT
1
<<<<<<<< FINISH
```

## Constraints

- `m == matrix.length`

- `n == matrix[i].length`

- `1 <= m, n <= 200`

- `0 <= matrix[i][j] <= 2³¹ - 1`