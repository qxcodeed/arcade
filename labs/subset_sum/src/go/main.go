package main

import "fmt"

func backtracking(vet []int, index, soma, alvo int) bool {
	_, _, _, _ = vet, index, soma, alvo
	return false
}

func main() {
	var qtd, soma int
	fmt.Scan(&qtd, &soma)
	vet := make([]int, qtd)
	for i := range qtd {
		fmt.Scan(&vet[i])
	}
	fmt.Println(vet)
}
