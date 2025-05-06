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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	line := scanner.Text()
	var nl, nc, lfire, cfire int
	fmt.Sscanf(line, "%d %d %d %d", &nl, &nc, &lfire, &cfire)

	mat := make([][]rune, 0, nl)
	for range nl {
		scanner.Scan()
		linha := []rune(scanner.Text())
		mat = append(mat, linha)
	}
	tocarFogo(mat, lfire, cfire)
	showMat(mat)
}

func showMat(mat [][]rune) {
	for _, linha := range mat {
		fmt.Println(string(linha))
	}
}
