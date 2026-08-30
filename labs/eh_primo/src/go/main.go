package main

import "fmt"

// x: número que está sendo testado
// div: divisor que está sendo testado
func eh_primo(x int, div int) bool {
	// @DROP
	if x == 0 || x == 1 {
		return false
	}
	if div > x/2 {
		return true
	}
	if x%div == 0 || x == 1 {
		return false
	}
	return eh_primo(x, div+1)
	// @UNC
	// _, _ = x, div
	// return false;
}

func main() {
	var x int
	fmt.Scan(&x)
	if eh_primo(x, 2) {
		fmt.Println("true")
	} else {
		fmt.Println("false")
	}
}
