# LeetCode 419. Battleships in a Board

## Intro

Dado um tabuleiro 2D onde cada célula é representada por `'X'` (parte de um navio) ou `'.'` (água), conte o número de navios de batalha no tabuleiro.  

Os navios podem estar apenas em duas formas:  
- Horizontal: uma sequência contínua de `'X'` na mesma linha.  
- Vertical: uma sequência contínua de `'X'` na mesma coluna.  

**Restrições importantes:**  
- Não há navios adjacentes, ou seja, não existe dois navios diferentes que toquem um ao outro (nem na diagonal).  

## Submission

Aqui, copiamos apenas alguns casos de teste do problema original, ao final, submeta seu código no LeetCode [nesse link](https://leetcode.com/problems/battleships-in-a-board/).

## Tests

```txt
>>>>>>>> INSERT Teste 1
3 4
X..X
...X
...X
======== EXPECT
2
<<<<<<<< FINISH


>>>>>>>> INSERT Teste 2
1 1
.
======== EXPECT
0
<<<<<<<< FINISH
```

## Constraints

- `m == board.length`

- `n == board[i].length`

- `1 <= m, n <= 200`

- `board[i][j] is '.' ou 'X'`
