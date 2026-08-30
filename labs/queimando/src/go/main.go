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
	return []Pos{
		{p.l - 1, p.c},
		{p.l + 1, p.c},
		{p.l, p.c - 1},
		{p.l, p.c + 1},
	}
}

func inside(grid [][]rune, p Pos) bool {
	return p.l >= 0 && p.l < len(grid) && p.c >= 0 && p.c < len(grid[0])
}
func match(grid [][]rune, p Pos, value rune) bool {
	return inside(grid, p) && grid[p.l][p.c] == value
}

// @KEEP
func burnTrees(grid [][]rune, l, c int) {
	stack := NewStack[Pos]()
	// @DROP
	stack.Push(Pos{l, c})
	for !stack.IsEmpty() {
		top := stack.Pop()
		if !match(grid, top, '#') {
			continue
		}
		grid[top.l][top.c] = 'o'
		for _, nb := range getNeig(top) {
			stack.Push(nb)
		}
	}

	// @UNC
	//_ , _ , _ = mat, l, c

	// @KEEP
	// Essa função deve usar uma list como pilha
	// e marcar as árvores na matriz como queimados
	// Uma sugestão de como fazer isso é:
	// - adicionar a primeira posição na pilha
	// - enquanto a pilha não estiver vazia:
	//   - retirar o elemento do topo
	//   - se puder ser queimado, queime e adicione seus vizinhos à pilha

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

func showGrid(mat [][]rune) {
	for _, linha := range mat {
		fmt.Println(string(linha))
	}
}
