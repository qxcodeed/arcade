package main

import (
	"bufio"
	"fmt"
	"os"
)

// DEL!
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

func search(grid [][]rune, startPos Pos, endPos Pos) {
	_, _, _ = grid, startPos, endPos
	// DEL!
	path := Stack[Pos]{}          // vai conter o caminho percorrido
	visited := make(map[Pos]bool) // vai guardar os nós visitados

	path.Push(startPos)
	visited[startPos] = true

	for !path.IsEmpty() {
		pos := path.Top()
		if pos == endPos {
			break
		}
		for _, n := range pos.getNeig() {
			if grid[n.l][n.c] == ' ' && !visited[n] {
				path.Push(n)
				visited[n] = true
				break
			}
		}
		if path.Top() == pos {
			path.Pop()
		}
	}
	for !path.IsEmpty() {
		pos := path.Pop()
		grid[pos.l][pos.c] = '.'
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nl_nc := scanner.Text()
	var nl, nc int
	fmt.Sscanf(nl_nc, "%d %d", &nl, &nc)
	grid := make([][]rune, nl)

	// Lê a grid
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
