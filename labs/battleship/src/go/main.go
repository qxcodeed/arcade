package main

import (
	"bufio"
	"fmt"
	"os"
)

// Função que será chamada no LeetCode
func countBattleships(board [][]byte) int {
	//
	// @UNC
	// _ := board
	// return 0
	// @DROP
	nrows := len(board)
	ncols := len(board[0])

	if nrows == 0 {
		return 0
	}

	counter := 0

	var dfs func(r, c int)
	dfs = func(r, c int) {
		if r < 0 || r >= nrows || c < 0 || c >= ncols || board[r][c] != 'X' {
			return
		}

		board[r][c] = 'V'

		dfs(r+1, c)
		dfs(r-1, c)
		dfs(r, c+1)
		dfs(r, c-1)
	}

	for i := 0; i < nrows; i++ {
		for j := 0; j < ncols; j++ {
			if board[i][j] == 'X' {
				counter++
				dfs(i, j)
			}
		}
	}
	return counter
}

// Não modifique a função main
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	var nl, nc int
	fmt.Sscanf(line, "%d %d", &nl, &nc)

	board := make([][]byte, nl)
	for i := 0; i < nl; i++ {
		scanner.Scan()
		board[i] = []byte(scanner.Text())
	}

	result := countBattleships(board)
	fmt.Println(result)
}
