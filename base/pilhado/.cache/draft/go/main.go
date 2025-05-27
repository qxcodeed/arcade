package main

import (
	"bufio"
	"fmt"
	"os"
)

// Pos representa uma posição (linha, coluna) na matriz.
// Equivalente à struct Pos em C++
type Pos struct {
	l int
	c int
}

func (p Pos) pegarVizinhos() []Pos {
	// Retorna as posições vizinhas (cima, baixo, esquerda, direita)
	return nil
}

// procurarSaida é uma função placeholder. Você precisará implementar a lógica
// equivalente à sua função procurar_saida em C++.
// Assumimos que ela modifica a matriz in-place.
func procurarSaida(mat [][]rune, inicio Pos, fim Pos) {
	_, _, _ = mat, inicio, fim
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	var nl, nc int
	scanner.Scan()
	line := scanner.Text()
	fmt.Sscanf(line, "%d %d", &nl, &nc)
	mat := make([][]rune, nl) // Inicializa a matriz de runes

	// Carregando matriz
	for i := range nl {
		scanner.Scan()
		line := scanner.Text()
		mat[i] = []rune(line)
	}

	var inicio, fim Pos

	// Procurando inicio e fim e colocando ' ' nas posições iniciais
	for l := range nl {
		for c := range nc {
			if mat[l][c] == 'I' {
				mat[l][c] = ' '
				inicio = Pos{l, c}
			}
			if mat[l][c] == 'F' {
				mat[l][c] = ' '
				fim = Pos{l, c}
			}
		}
	}

	procurarSaida(mat, inicio, fim)

	for _, line := range mat {
		fmt.Println(string(line)) // Converte o slice de runes de volta para string para imprimir
	}
}
