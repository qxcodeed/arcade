package main

import (
	"fmt"
)

const EMPTY = '.'

type Problem struct {
	data []rune
	lim  int
}

// verifica se esse valor pode ser utilizado nessa posição
func (p *Problem) fit(index int, value rune) bool {
	_, _ = index, value
	// cuidado para não sair dos limites, nem para o começo, nem para o fim
	return false
}

func (p *Problem) solve(index int) bool {
	// se chegou ao fim, retorne true
	// se não é EMPTY, vá para o próximo
	// se é EMPTY
	//    faça um laço e chame a recursão para cada valor possível
	//    se algum der certo, então retorne verdade
	// se nenhum deu certo, recoloque vazio e retorne falso
	_ = index
	return false
}

func main() {
	var input string
	var lim int
	fmt.Scan(&input, &lim)
	prob := Problem{data: []rune(input), lim: lim}
	prob.solve(0)
	fmt.Println(string(prob.data))
}
