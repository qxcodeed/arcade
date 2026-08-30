package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func BetterSearch(slice []int, value int) (bool, int) {
	// @UNC
	// _, _ = slice, value
	// return false, 0
	// @DROP
	low, high := 0, len(slice)
	for low <= high {
		mid := (low + high) / 2
		if slice[mid] == value {
			return true, mid
		}
		if slice[mid] < value {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return false, low
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	slice := []int{}
	for _, elem := range parts[1 : len(parts)-1] {
		value, _ := strconv.Atoi(elem)
		slice = append(slice, value)
	}
	scanner.Scan()
	value, _ := strconv.Atoi(scanner.Text())
	found, result := BetterSearch(slice, value)
	if found {
		fmt.Println("V", result)
	} else {
		fmt.Println("F", result)
	}
}
