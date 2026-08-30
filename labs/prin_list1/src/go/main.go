package main

import (
	"fmt"
	"strings"
)

// mostra a lista com o elemento sword destacado
func ToStr(l *DList[int], sword *DNode[int]) string {
	// @DROP
	var str strings.Builder
	str.WriteString("[ ")
	for it := l.Front(); it != l.End(); it = it.Next() {
		if it == sword {
			fmt.Fprintf(&str, "%v> ", it.Value)
		} else {
			fmt.Fprintf(&str, "%v ", it.Value)
		}
	}
	return str.String() + "]"
	// @UNC
	// return ""
}

// move para frente na lista circular
func Next(l *DList[int], it *DNode[int]) *DNode[int] {
	// @DROP
	it = it.Next()
	if it == l.End() {
		it = l.Front()
	}
	return it
	// @UNC
	// return nil
}

func main() {
	var qtd, chosen int
	fmt.Scan(&qtd, &chosen)
	fmt.Println(qtd, chosen)
	l := NewDList[int]()
	for i := 1; i <= qtd; i++ {
		l.PushBack(i)
	}
	sword := l.Front()
	for range chosen - 1 {
		sword = Next(l, sword)
	}
	for range qtd - 1 {
		fmt.Println(ToStr(l, sword))
		l.Erase(Next(l, sword))
		sword = Next(l, sword)
	}
	fmt.Println(ToStr(l, sword))
}
