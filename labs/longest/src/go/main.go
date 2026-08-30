package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func longestIncreasingPath(matrix [][]int) int {
	//
	// @UNC
	// _ := matrix
	// return 0
	// @DROP
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}
	ROWS := len(matrix)
	COLS := len(matrix[0])

	dp := make(map[[2]int]int)

	var dfs func(r, c, prevVal int) int
	dfs = func(r, c, prevVal int) int {
		if r < 0 || r >= ROWS || c < 0 || c >= COLS || matrix[r][c] <= prevVal {
			return 0
		}

		key := [2]int{r, c}
		if val, ok := dp[key]; ok {
			return val
		}

		curr := matrix[r][c]
		res := 1
		if tmp := 1 + dfs(r+1, c, curr); tmp > res {
			res = tmp
		}
		if tmp := 1 + dfs(r-1, c, curr); tmp > res {
			res = tmp
		}
		if tmp := 1 + dfs(r, c+1, curr); tmp > res {
			res = tmp
		}
		if tmp := 1 + dfs(r, c-1, curr); tmp > res {
			res = tmp
		}

		dp[key] = res
		return res
	}

	ans := 0
	for r := 0; r < ROWS; r++ {
		for c := 0; c < COLS; c++ {
			if v := dfs(r, c, -1); v > ans {
				ans = v
			}
		}
	}
	return ans
}

// Não modifique a função main
func main() {
	scanner := bufio.NewScanner(os.Stdin)

	if !scanner.Scan() {
		return
	}
	parts := strings.Fields(scanner.Text())
	if len(parts) < 2 {
		return
	}
	nl, _ := strconv.Atoi(parts[0])
	nc, _ := strconv.Atoi(parts[1])

	matrix := make([][]int, nl)
	for i := 0; i < nl; i++ {
		if !scanner.Scan() {
			return
		}
		tokens := strings.Fields(scanner.Text())
		row := make([]int, nc)
		for j := 0; j < nc && j < len(tokens); j++ {
			v, _ := strconv.Atoi(tokens[j])
			row[j] = v
		}
		matrix[i] = row
	}

	fmt.Println(longestIncreasingPath(matrix))
}
