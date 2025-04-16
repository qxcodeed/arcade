package main

import (
	"fmt"
)

func mdc(a, b int) int {
	if b == 0 {
		return a
	}
	return mdc(b, a%b)
	return 0
}

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	fmt.Println(mdc(a, b))
}
