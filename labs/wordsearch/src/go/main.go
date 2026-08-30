package main

import (
	"bufio"
	"fmt"
	"os"
)

// @DROP
type Pos struct {
	l int
	c int
}

func (p Pos) getNeig() []Pos {
	return []Pos{
		{p.l - 1, p.c}, // Cima
		{p.l + 1, p.c}, // Baixo
		{p.l, p.c - 1}, // Esquerda
		{p.l, p.c + 1}, // Direita
	}
}

func inside(pos Pos, grid [][]byte) bool {
	return pos.l >= 0 && pos.l < len(grid) && pos.c >= 0 && pos.c < len(grid[pos.l])
}

func match(pos Pos, grid [][]byte, value byte) bool {
	return inside(pos, grid) && grid[pos.l][pos.c] == value
}

func __search(grid [][]byte, pos Pos, visited map[Pos]bool, suffix string) bool {
	if len(suffix) == 0 {
		return true
	}
	if !match(pos, grid, suffix[0]) || visited[pos] {
		return false
	}
	visited[pos] = true
	for _, n := range pos.getNeig() {
		if __search(grid, n, visited, suffix[1:]) {
			return true
		}
	}
	delete(visited, pos)
	return false
}

// @KEEP
// Não mude a assinatura desta função, ela é a função chamada pelo LeetCode
func exist(grid [][]byte, word string) bool {
	// @UNC
	// _, _ = grid, word
	// return false
	// @DROP
	for l := range grid {
		for c := range grid[l] {
			if grid[l][c] == word[0] {
				visited := make(map[Pos]bool)
				if __search(grid, Pos{l, c}, visited, word) {
					return true
				}
			}
		}
	}
	return false
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	var word string
	fmt.Sscanf(scanner.Text(), "%s", &word)
	grid := make([][]byte, 0)
	for scanner.Scan() {
		grid = append(grid, []byte(scanner.Text()))
	}
	if exist(grid, word) {
		fmt.Println("true")
	} else {
		fmt.Println("false")
	}
}
