package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func EhVazio(vet []int) bool {
	return fmt.Sprint(vet) == "[]"
}

// não altere a assinatura
func equals(a []int, b []int) bool {
	// não use a função len para ver ou comparar os tamanhos
	// utilize a função EhVazio para ver se o vetor é vazio
	// você só pode consultar o primeiro elemento do vetor
	// e não pode usar nenhum tipo de laço
	// Use recursao para consultar os outros elementos equals(a[1:], b[1:])
	// não altere o protótipo da função nem crie funções auxiliares
	_, _ = a, b
	return false
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	vet1 := str2slice(scanner.Text())
	scanner.Scan()
	vet2 := str2slice(scanner.Text())
	if equals(vet1, vet2) {
		fmt.Println("iguais")
	} else {
		fmt.Println("diferentes")
	}
}

func str2slice(line string) []int {
	parts := strings.Fields(line)
	nums := make([]int, 0)
	for i := 1; i < len(parts)-1; i++ {
		value, _ := strconv.Atoi(parts[i])
		nums = append(nums, value)
	}
	return nums
}
