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

func getNeig(p Pos) []Pos {
	return []Pos{{p.l - 1, p.c}, {p.l + 1, p.c}, {p.l, p.c - 1}, {p.l, p.c + 1}}
}

func inside(grid [][]rune, p Pos) bool {
	return p.l >= 0 && p.l < len(grid) && p.c >= 0 && p.c < len(grid[0])
}

func match(grid [][]rune, p Pos, value rune) bool {
	return inside(grid, p) && grid[p.l][p.c] == value
}

// @KEEP
func burnTrees(grid [][]rune, l, c int) {
	_, _, _ = grid, l, c
	// nl := len(grid)
	// nc := len(grid[0])
	// _, _ = nl, nc
	// @DROP
	if !match(grid, Pos{l, c}, '#') {
		return
	}
	grid[l][c] = 'o'
	for _, nb := range getNeig(Pos{l, c}) {
		burnTrees(grid, nb.l, nb.c)
	}
	// @KEEP
	// se estiver fora da matriz, retorne
	// se o elemento atual não for uma arvore, retorne
	// queime a arvore colocando o caractere 'o' na posição atual
	// chame a recursão para todos os 4 vizinhos
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	var nl, nc, lfire, cfire int
	fmt.Sscanf(line, "%d %d %d %d", &nl, &nc, &lfire, &cfire)

	grid := make([][]rune, 0, nl)
	for range nl {
		scanner.Scan()
		line := []rune(scanner.Text())
		grid = append(grid, line)
	}
	burnTrees(grid, lfire, cfire)
	showGrid(grid)
}

func showGrid(grid [][]rune) {
	for _, line := range grid {
		fmt.Println(string(line))
	}
}
