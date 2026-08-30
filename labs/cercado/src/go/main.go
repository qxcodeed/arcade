package main

import (
	"bufio"
	"fmt"
	"os"
)

// DEL!
type Pos struct {
	l, c int
}

// @KEEP
// NÃO ALTERE A ASSINATURA DA FUNÇÃO solve
func solve(board [][]byte) {
	_ = board
	// DEL!
	if len(board) == 0 || len(board[0]) == 0 {
		return
	}
	rows := len(board)
	cols := len(board[0])
	visited := map[Pos]bool{}

	var dfs func(int, int)
	dfs = func(r, c int) {
		if r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O' || visited[Pos{r, c}] {
			return
		}
		visited[Pos{r, c}] = true
		dfs(r, c+1)
		dfs(r, c-1)
		dfs(r+1, c)
		dfs(r-1, c)
	}
	for i := range rows {
		dfs(i, 0)
		dfs(i, cols-1)
	}
	for j := range cols {
		dfs(0, j)
		dfs(rows-1, j)
	}
	for i := range rows {
		for j := range cols {
			if board[i][j] == 'O' && !visited[Pos{i, j}] {
				board[i][j] = 'X'
			}
		}
	}
}

// NÃO ALTERE A MAIN
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	var nrows, ncols int
	fmt.Sscanf(scanner.Text(), "%d %d", &nrows, &ncols)
	board := make([][]byte, nrows)
	for i := 0; i < nrows; i++ {
		scanner.Scan()
		board[i] = []byte(scanner.Text())
	}
	solve(board)
	for _, row := range board {
		fmt.Println(string(row))
	}
}
