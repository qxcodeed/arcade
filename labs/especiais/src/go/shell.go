package main

import (
	"bufio"
	"fmt"
	"os"
	"slices" // @DROP
	"strconv"
	"strings"
)

type Pair struct {
	One int
	Two int
}

func occurr(vet []int) []Pair {
	_ = vet
	// @DROP

	abs := func(value int) int {
		if value > 0 {
			return value
		}
		return -value
	}

	m := make(map[int]int)
	for _, x := range vet {
		m[abs(x)]++
	}
	var result []Pair
	for k, v := range m {
		result = append(result, Pair{k, v})
	}
	slices.SortFunc(result, func(a, b Pair) int {
		return a.One - b.One
	})
	return result
	// @UNC
	// return nil
}

func teams(vet []int) []Pair {
	_ = vet
	// @DROP
	if len(vet) == 0 {
		return nil
	}
	var output []Pair
	output = append(output, Pair{vet[0], 1})
	for i := 1; i < len(vet); i++ {
		if output[len(output)-1].One == vet[i] {
			output[len(output)-1].Two++
		} else {
			output = append(output, Pair{vet[i], 1})
		}
	}
	return output
	// @UNC
	// return nil
}

func mnext(vet []int) []int {
	_ = vet
	// @DROP
	size := len(vet)
	hasWoman := func(index int) bool {
		return index >= 0 && index < size && vet[index] < 0
	}
	var output []int
	for i := 0; i < size; i++ {
		if vet[i] > 0 && (hasWoman(i-1) || hasWoman(i+1)) {
			output = append(output, 1)
		} else {
			output = append(output, 0)
		}
	}
	return output
	// @UNC
	// return nil
}

func alone(vet []int) []int {
	_ = vet
	// @DROP
	size := len(vet)
	hasWoman := func(index int) bool {
		return index >= 0 && index < size && vet[index] < 0
	}
	var output []int
	for i := range size {
		if vet[i] > 0 && (!hasWoman(i-1) && !hasWoman(i+1)) {
			output = append(output, 1)
		} else {
			output = append(output, 0)
		}
	}
	return output
	// @UNC
	// return nil
}

func couple(vet []int) int {
	_ = vet
	// @DROP
	qtd := 0
	for i := range len(vet) {
		for j := i + 1; j < len(vet); j++ {
			if vet[i] != 0 && vet[j] != 0 && vet[i] == -vet[j] {
				vet[i], vet[j] = 0, 0
				qtd++
			}
		}
	}
	return qtd
	// @UNC
	// return 0
}

func hasSubseq(vet []int, seq []int, pos int) bool {
	_ = vet
	_ = seq
	_ = pos
	// @DROP
	for i := range seq {
		if pos+i >= len(vet) || vet[pos+i] != seq[i] {
			return false
		}
	}
	return true
	// @UNC
	// return false
}

func subseq(vet []int, seq []int) int {
	_ = vet
	_ = seq
	// @DROP
	for i := range vet {
		if hasSubseq(vet, seq, i) {
			return i
		}
	}
	return -1
	// @UNC
	// return -1
}

func erase(vet []int, posList []int) []int {
	_ = vet
	_ = posList
	// @DROP
	var output []int
	for i := range vet {
		if !slices.Contains(posList, i) {
			output = append(output, vet[i])
		}
	}
	return output
	// @UNC
	// return nil
}

func clear(vet []int, value int) []int {
	_ = vet
	_ = value
	// @DROP
	var output []int
	for _, v := range vet {
		if v != value {
			output = append(output, v)
		}
	}
	return output
	// @UNC
	// return nil
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for {
		fmt.Print("$")
		if !scanner.Scan() {
			break
		}
		line := scanner.Text()
		args := strings.Split(line, " ")
		fmt.Println(line)

		switch args[0] {
		case "occurr":
			printSlice(occurr(str2vet(args[1])))
		case "teams":
			printSlice(teams(str2vet(args[1])))
		case "mnext":
			printSlice(mnext(str2vet(args[1])))
		case "alone":
			printSlice(alone(str2vet(args[1])))
		case "erase":
			printSlice(erase(str2vet(args[1]), str2vet(args[2])))
		case "clear":
			val, _ := strconv.Atoi(args[2])
			printSlice(clear(str2vet(args[1]), val))
		case "subseq":
			fmt.Println(subseq(str2vet(args[1]), str2vet(args[2])))
		case "couple":
			fmt.Println(couple(str2vet(args[1])))
		case "end":
			return
		default:
			fmt.Println("Invalid command")
		}
	}
}

// Funções auxiliares

func str2vet(str string) []int {
	if str == "[]" {
		return nil
	}
	str = str[1 : len(str)-1]
	parts := strings.Split(str, ",")
	var vet []int
	for _, part := range parts {
		num, _ := strconv.Atoi(strings.TrimSpace(part))
		vet = append(vet, num)
	}
	return vet
}

func printSlice[T any](vet []T) {
	fmt.Print("[")
	for i, x := range vet {
		if i > 0 {
			fmt.Print(", ")
		}
		fmt.Print(x)
	}
	fmt.Println("]")
}

func (p Pair) String() string {
	return fmt.Sprintf("(%v, %v)", p.One, p.Two)
}
