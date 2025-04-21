package main

import (
	"bufio"
	"fmt"
	"os"
)

type Pos struct {
	l, c int
}

// compara duas posições
func (p Pos) equals(other Pos) bool {
	return p.l == other.l && p.c == other.c
}

func (p Pos) getNeighbors() []Pos {
	return []Pos{
		{p.l, p.c - 1},
		{p.l - 1, p.c},
		{p.l, p.c + 1},
		{p.l + 1, p.c},
	}
}

// Função recursiva que tenta encontrar o caminho do início ao fim
func procurarSaida(mat [][]rune, atual, fim Pos) bool {
	_, _, _ = mat, atual, fim
	// se posição não existir ou não for caminho retorne falso
	// se posição for o fim retorne verdadeiro
	// marca a posição atual como possivel caminho usando .
	// para cada vizinho, chama a função recursivamente
	// se algum dos meus vizinho for caminho, eu sou caminho
	// se nenhum vizinho for caminho, eu sou erro
	// marca a posição atual como erro usando x
	// retorna falso
	return false

}

func removerErros(mat [][]rune) {
	for l := range mat {
		for c := range mat[0] {
			if mat[l][c] == 'x' {
				mat[l][c] = '_'
			}
		}
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nl_nc := scanner.Text()
	var nl, nc int
	fmt.Sscanf(nl_nc, "%d %d", &nl, &nc)
	mat := make([][]rune, nl)

	// Lê a matriz
	for i := range nl {
		scanner.Scan()
		mat[i] = []rune(scanner.Text())
	}

	// Procura posições de início e fim e conserta para _
	inicio, fim := procurarPosicoes(mat)
	procurarSaida(mat, inicio, fim)
	removerErros(mat)

	// Imprime o labirinto final
	for _, line := range mat {
		fmt.Println(string(line))
	}
}

// procura as posições de início e fim do labirinto
// depois, as substitui por '_'
func procurarPosicoes(mat [][]rune) (Pos, Pos) {
	nl := len(mat)
	nc := len(mat[0])
	inicio := Pos{}
	fim := Pos{}
	for l := range nl {
		for c := range nc {
			switch mat[l][c] {
			case 'I':
				mat[l][c] = '_'
				inicio = Pos{l, c}
			case 'F':
				mat[l][c] = '_'
				fim = Pos{l, c}
			}
		}
	}
	return inicio, fim
}
