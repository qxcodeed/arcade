# LeetCode 733. Flood Fill

## Intro

Dada uma imagem representada por uma matriz de inteiros 2D, onde `image[i][j]` representa a cor do pixel, implemente um algoritmo de preenchimento de área (flood fill).

Você recebe as coordenadas de um pixel inicial `(sr, sc)` e uma cor `color`.  
Troque a cor do pixel inicial e de todos os pixels conectados a ele (em 4 direções: cima, baixo, esquerda, direita) **que tenham a mesma cor original** pelo novo valor `color`.

## Submission

Aqui, copiamos apenas alguns casos de teste do problema original, ao final, submeta seu código no LeetCode [nesse link](https://leetcode.com/problems/flood-fill/).

## Tests

```txt
>>>>>>>> INSERT Teste 1
3 3
1 1 1
1 1 0
1 0 1
1 1 2
======== EXPECT
2 2 2
2 2 0
2 0 1
<<<<<<<< FINISH


>>>>>>>> INSERT Teste 2
2 3
0 0 0
0 0 0
0 0 0
0 0 0
======== EXPECT
0 0 0
0 0 0
<<<<<<<< FINISH
```

## Constraints

- `m == image.length`
- `n == image[i].length`
- `1 <= m, n <= 50c`
- `0 <= sr < m`
- `0 <= sc < n`