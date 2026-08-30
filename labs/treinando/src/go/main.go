package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// @DROP
func __tostr(vet []int) string {
	if len(vet) == 0 {
		return ""
	}
	return fmt.Sprint(vet[0]) + ", " + __tostr(vet[1:])
}

// @KEEP
func tostr(vet []int) string {
	// @DROP
	data := __tostr(vet)
	if len(data) > 0 {
		data = data[:len(data)-2]
	}
	return "[" + data + "]"
	// @UNC
	// _ = vet
	// return ""
}

// @DROP
func __tostrrev(vet []int) string {
	if len(vet) == 0 {
		return ""
	}
	return __tostrrev(vet[1:]) + ", " + fmt.Sprint(vet[0])
}

// @KEEP
func tostrrev(vet []int) string {
	// @DROP
	data := __tostrrev(vet)
	if len(data) > 0 {
		data = data[2:]
	}
	return "[" + data + "]"
	// @UNC
	// _ = vet
	// return ""
}

// @KEEP
// reverse: inverte os elementos do slice
func reverse(vet []int) {
	// @DROP
	if len(vet) < 2 {
		return
	}
	vet[0], vet[len(vet)-1] = vet[len(vet)-1], vet[0]
	reverse(vet[1 : len(vet)-1])
	// @UNC
	// _ = vet
}

// sum: soma dos elementos do slice
func sum(vet []int) int {
	// @DROP
	if len(vet) == 0 {
		return 0
	}
	return sum(vet[1:]) + vet[0]
	// @UNC
	// _ = vet
	// return 0
}

// mult: produto dos elementos do slice
func mult(vet []int) int {
	// @DROP
	if len(vet) == 0 {
		return 1
	}
	return mult(vet[1:]) * vet[0]
	// @UNC
	// _ = vet
	// return 0
}

// min: retorna o índice e valor do menor valor
// crie uma função recursiva interna do modelo
// var rec func(v []int) (int, int)
// para fazer uma recursão que retorna valor e índice
func min(vet []int) int {
	// @DROP
	var rec func(v []int) (int, int)

	rec = func(v []int) (int, int) {
		if len(v) == 0 {
			return 0, -1
		}
		if len(v) == 1 {
			return v[0], 0
		}
		value, index := rec(v[1:])
		if v[0] < value {
			return v[0], 0
		}
		return value, index + 1
	}
	_, index := rec(vet)
	return index
	// @UNC
	// _ = vet
	// return 0
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
			fmt.Println(min(vet))
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
