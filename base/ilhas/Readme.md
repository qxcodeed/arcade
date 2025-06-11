# LeetCode 200. Number os islands

## Intro

Dado um mapa 2D de ilhas e água, conte o número de ilhas. Uma ilha é formada por células adjacentes de terra (representadas por '1') conectadas horizontal ou verticalmente, enquanto a água é representada por '0'.

Uma ilha é cercada por água e é formada por conectar terras adjacentes horizontal ou verticalmente. Você pode assumir que todas as quatro bordas da grade estão cercadas por água.

## Submission

Aqui, copiamos apenas os dois primeiros casos de teste do problema original, ao final, submeta seu código no LeetCode [nesse link](https://leetcode.com/problems/number-of-islands/).

## Tests

```txt
>>>>>>>> INSERT Teste 1
4 5
11110
11010
11000
00000
======== EXPECT
1
<<<<<<<< FINISH


>>>>>>>> INSERT Teste 2
4 5
11000
11000
00100
00011
======== EXPECT
3
<<<<<<<< FINISH
```

### Constraints

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j] is '0' or '1'`
