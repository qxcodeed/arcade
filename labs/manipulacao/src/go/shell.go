package main

import (
	"bufio"
	"fmt"
	"os"
	"sort" // @DROP
	"strconv"
	"strings"
)

func getMen(vet []int) []int {
	// @DROP
	var unique []int
	for _, elem := range vet {
		if elem > 0 {
			unique = append(unique, elem)
		}
	}
	return unique
	// @UNC
	// _ = vet
	// return nil
}

func getCalmWomen(vet []int) []int {
	// @DROP
	var unique []int
	for _, elem := range vet {
		if elem < 0 && abs(elem) < 10 {
			unique = append(unique, elem)
		}
	}
	return unique
	// @UNC
	// _ = vet
	// return nil
}

func sortVet(vet []int) []int {
	// @DROP
	sort.Ints(vet)
	return vet
	// @UNC
	// _ = vet
	// return nil
}

func sortStress(vet []int) []int {
	// @DROP
	sort.Slice(vet, func(i, j int) bool {
		return abs(vet[i]) < abs(vet[j])
	})
	return vet
	// @UNC
	// _ = vet
	// return nil
}

func reverse(vet []int) []int {
	// @DROP
	other := make([]int, len(vet))
	copy(other, vet)
	i := 0
	j := len(other) - 1
	for i < j {
		other[i], other[j] = other[j], other[i]
		i += 1
		j -= 1
	}
	return other
	// @UNC
	// _ = vet
	// return nil
}

func unique(vet []int) []int {
	// @DROP
	var uniq []int
	for _, elem := range vet {
		if !exists(uniq, elem) {
			uniq = append(uniq, elem)
		}
	}
	return uniq
	// @UNC
	// _ = vet
	// return nil
}

func repeated(vet []int) []int {
	// @DROP
	var uniq []int
	var rep []int
	for _, elem := range vet {
		if !exists(uniq, elem) {
			uniq = append(uniq, elem)
		} else {
			rep = append(rep, elem)
		}
	}
	return rep
	// @UNC
	// _ = vet
	// return nil
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	for {
		if !scanner.Scan() {
			break
		}
		fmt.Print("$")
		line := scanner.Text()
		args := strings.Split(line, " ")
		fmt.Println(line)

		switch args[0] {
		case "get_men":
			printVec(getMen(str2vet(args[1])))
		case "get_calm_women":
			printVec(getCalmWomen(str2vet(args[1])))
		case "sort":
			printVec(sortVet(str2vet(args[1])))
		case "sort_stress":
			printVec(sortStress(str2vet(args[1])))
		case "reverse":
			array := str2vet(args[1])
			other := reverse(array)
			printVec(array)
			printVec(other)
		case "unique":
			printVec(unique(str2vet(args[1])))
		case "repeated":
			printVec(repeated(str2vet(args[1])))
		case "end":
			return
		}
	}
}

func printVec(vet []int) {
	fmt.Print("[")
	for i, val := range vet {
		if i > 0 {
			fmt.Print(", ")
		}
		fmt.Print(val)
	}
	fmt.Println("]")
}

func str2vet(s string) []int {
	if s == "[]" {
		return nil
	}
	s = s[1 : len(s)-1]
	parts := strings.Split(s, ",")
	var vet []int
	for _, part := range parts {
		n, _ := strconv.Atoi(part)
		vet = append(vet, n)
	}
	return vet
}

// @DROP
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func exists(vet []int, value int) bool {
	for _, v := range vet {
		if v == value {
			return true
		}
	}
	return false
}
