package main

import (
	"fmt"
	"math/rand"
	"time"
)

const interval = 150 * time.Millisecond

// ----------------------- CREATE MAZE -----------------------

func dig(matrix *Matrix, pos Pos, wall, path, hole rune) {
	//count how many neighbors are 'w' or are outside the matrix
	count := 0
	neibs := pos.GetHexNeighbors()
	for _, n := range neibs {
		if !matrix.Contains(n) {
			count++
		} else if matrix.Get(n) == hole || matrix.Get(n) == path {
			count++
		}
	}
	if count == 0 || count == 1 {
		matrix.Set(pos, path)
		matrix.SaveHexGrid("grid.svg")
		time.Sleep(interval)
		for _, n := range Shuffle(pos.GetHexNeighbors()) {
			dig(matrix, n, wall, path, hole)
		}
		matrix.Set(pos, hole)
		matrix.SaveHexGrid("grid.svg")
		time.Sleep(interval)
	}
}

func createPerfectMaze(nl, nc int) *Matrix {
	matrix := NewMatrix(nl, nc, 'b')
	dig(matrix, Pos{1, 1}, 'c', 'y', 'w')
	return matrix
}

// ----------------------- BURNING -----------------------

func Burn(matrix *Matrix, pos Pos) {
	if !matrix.Contains(pos) {
		return
	}
	if matrix.Get(pos) != 'g' {
		return
	}
	matrix.Set(pos, 'r') //queimando
	matrix.SaveHexGrid("grid.svg")
	//wait for 1 second
	time.Sleep(interval)
	//wait hit enter
	// fmt.Scanln()

	neibs := pos.GetHexNeighbors()

	for _, n := range neibs {
		Burn(matrix, n)
	}
	matrix.Set(pos, 'o') // burned
	matrix.SaveHexGrid("grid.svg")
	time.Sleep(interval)
	// fmt.Scanln()
}

func RandomPaint(matrix *Matrix, color rune, prob int) {
	for l := range matrix.NL {
		for c := range matrix.NC {
			if rand.Intn(100) < prob {
				matrix.Info[l][c] = color
			}
		}
	}
}

func createRandAndBurn(nl, nc int) {
	matrix := NewMatrix(nl, nc, 'w')
	RandomPaint(matrix, 'g', 70)
	Burn(matrix, NewPos(0, 0))
	matrix.SaveHexGrid("grid.svg")

	fmt.Println("SVG file created successfully.")
}

func main() {
	option := "maze"
	if option == "burn" {
		createRandAndBurn(10, 10)
	}
	if option == "maze" {
		createPerfectMaze(15, 15)
	}
}
