package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func tostr(vet []int) string {
	_ = vet
	return ""
}

func tostrrev(vet []int) string {
	_ = vet
	return ""
}

// reverse: inverte os elementos do slice
func reverse(vet []int) {
	_ = vet
}

// sum: soma dos elementos do slice
func sum(vet []int) int {
	_ = vet
	return 0
}

// mult: produto dos elementos do slice
func mult(vet []int) int {
	_ = vet
	return 0
}

// min: retorna o índice e valor do menor valor
func min(vet []int) (int, int) {
	_ = vet
	return 0, 0
}

func main() {
	var vet []int
	scanner := bufio.NewScanner(os.Stdin)
	for {
		if !scanner.Scan() {
			break
		}
		line := scanner.Text()
		args := strings.Fields(line)
		fmt.Println("$" + line)

		switch args[0] {
		case "end":
			return
		case "read":
			vet = nil
			for _, arg := range args[1:] {
				if val, err := strconv.Atoi(arg); err == nil {
					vet = append(vet, val)
				}
			}
		case "tostr":
			fmt.Println(tostr(vet))
		case "torev":
			fmt.Println(tostrrev(vet))
		case "reverse":
			reverse(vet)
		case "sum":
			fmt.Println(sum(vet))
		case "mult":
			fmt.Println(mult(vet))
		case "min":
			_, index := min(vet)
			fmt.Println(index)
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
