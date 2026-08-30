package main

import (
	"bufio"
	"fmt"
	"os"
)

type Pos struct {
	l, c int
}

func getNeig(p Pos) []Pos {
	return []Pos{{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}}
}

func inside(grid [][]rune, p Pos) bool {
	return !(p.l < 0 || p.l >= len(grid) || p.c < 0 || p.c >= len(grid[0]))
}

func match(grid [][]rune, p Pos, value rune) bool {
	return inside(grid, p) && grid[p.l][p.c] == value
}

// @DROP
func __search(grid [][]rune, visited map[Pos]bool, current Pos, endPos Pos) bool {
	if !match(grid, current, ' ') {
		return false
	}
	if visited[current] {
		return false
	}
	visited[current] = true
	if current == endPos {
		grid[current.l][current.c] = '.'
		return true
	}
	for _, n := range getNeig(current) {
		if __search(grid, visited, n, endPos) {
			grid[current.l][current.c] = '.' // marca a posição atual como parte do caminho
			return true
		}
	}
	return false
}

// @KEEP
// Função recursiva que tenta encontrar o caminho do início ao fim
func search(grid [][]rune, startPos, endPos Pos) bool {
	// @UNC
	// _, _, _ = grid, startPos, endPos
	// return false
	// @DROP
	visited := make(map[Pos]bool)
	return __search(grid, visited, startPos, endPos)
}

// @KEEP
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nl_nc := scanner.Text()
	var nl, nc int
	fmt.Sscanf(nl_nc, "%d %d", &nl, &nc)
	grid := make([][]rune, nl)

	// Lê a gridriz
	for i := range nl {
		scanner.Scan()
		grid[i] = []rune(scanner.Text())
	}

	// Procura posições de início e endPos e conserta para _
	var startPos, endPos Pos
	for l := range nl {
		for c := range nc {
			if grid[l][c] == 'I' {
				grid[l][c] = ' '
				startPos = Pos{l, c}
			}
			if grid[l][c] == 'F' {
				grid[l][c] = ' '
				endPos = Pos{l, c}
			}
		}
	}

	search(grid, startPos, endPos)

	// Imprime o labirinto final
	for _, line := range grid {
		fmt.Println(string(line))
	}
}
