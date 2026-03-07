# Word Search LeetCode 79

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

## OBS

Lembre de submeter seu código no LeetCode para validar a solução.

## Example 1

![_](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

```txt
- Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
- Output: true
```

## Example 2

"[_](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)

```txt
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

## Example 3

![_](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)

```txt
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

### Constraints

```txt
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
```

Follow up: Could you use search pruning to make your solution faster with a larger board?

## Tests

```txt
>>>>>>>> INSERT
ABCCED
ABCE
SFCS
ADEE
======== EXPECT
true
<<<<<<<< FINISH

>>>>>>>> INSERT
SEE
ABCE
SFCS
ADEE
======== EXPECT
true
<<<<<<<< FINISH

>>>>>>>> INSERT
ABCB
ABCE
SFCS
ADEE
======== EXPECT
false
<<<<<<<< FINISH

>>>>>>>>> INSERT
ABCESEEEFS
ABCE
SFES
ADEE
======== EXPECT
true
<<<<<<<< FINISH
```
