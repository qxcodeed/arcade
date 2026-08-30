package main

import (
	"bufio"
	"fmt"
	"os"
)

// @DROP
type Pos struct {
	x, y int
}

func (p Pos) getNeib() []Pos {
	return []Pos{
		Pos{p.x - 1, p.y}, // L
		Pos{p.x, p.y - 1}, // U
		Pos{p.x + 1, p.y}, // R
		Pos{p.x, p.y + 1}, // D
	}
}

func isInside(grid [][]byte, p Pos) bool {
	nl := len(grid)
	nc := len(grid[0])
	if p.x < 0 || p.x >= nc || p.y < 0 || p.y >= nl {
		return false
	}
	return true
}

func match(grid [][]byte, p Pos, value byte) bool {
	return isInside(grid, p) && grid[p.y][p.x] == value
}

func dfs(grid [][]byte, p Pos) {
	if !match(grid, p, '1') {
		return
	}
	grid[p.y][p.x] = '2'
	for _, v := range p.getNeib() {
		dfs(grid, v)
	}
}

// @KEEP
// Não modifique a assinatura da função numIslands
// Ela é a função que será chamada no LeetCode para resolver o problema
func numIslands(grid [][]byte) int {
	//
	// @UNC
	// _ := grid
	// return 0
	// @DROP
	nl := len(grid)
	nc := len(grid[0])
	count := 0
	for x := range nc {
		for y := range nl {
			if grid[y][x] == '1' {
				count += 1
				dfs(grid, Pos{x: x, y: y})
			}
		}
	}
	return count
}

// Não modifique a função main
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	var nl, nc int
	fmt.Sscanf(line, "%d %d", &nl, &nc)
	grid := make([][]byte, nl)
	for i := 0; i < nl; i++ {
		scanner.Scan()
		grid[i] = []byte(scanner.Text())
	}
	result := numIslands(grid)
	fmt.Println(result)
}
