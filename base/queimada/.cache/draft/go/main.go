package main

import (
	"bufio"
	"fmt"
	"os"
)

func tocarFogo(mat [][]rune, l, c int) {
	nl := len(mat)
	nc := len(mat[0])
	_, _, _, _, _ = mat, l, c, nl, nc
	// se estiver fora da matriz, retorne
	// se o elemento atual não for uma arvore, retorne
	// queime a arvore colocando o caractere 'o' na posição atual
	// chame a recursão para todos os 4 vizinhos
}

func main() {
	var nl, nc, lfire, cfire int
	fmt.Scan(&nl, &nc, &lfire, &cfire)

	mat := readMat(nl)
	tocarFogo(mat, lfire, cfire)
	showMat(mat)
}

func showMat(mat [][]rune) {
	for _, linha := range mat {
		fmt.Println(string(linha))
	}
}

func readMat(nl int) [][]rune {
	scanner := bufio.NewScanner(os.Stdin)
	mat := make([][]rune, 0, nl)
	for range nl {
		scanner.Scan()
		linha := []rune(scanner.Text())
		mat = append(mat, linha)
	}
	return mat
}
