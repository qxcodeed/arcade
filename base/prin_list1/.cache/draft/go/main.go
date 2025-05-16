package main

import (
	"container/list"
	"fmt"
)

// mostra a lista com o elemento sword destacado
func ToStr(l *list.List, sword *list.Element) string {
	return ""
}

// move para frente na lista circular
func Next(l *list.List, it *list.Element) *list.Element {
	return nil
}

func main() {
	var qtd, chosen int
	fmt.Scan(&qtd, &chosen)
	l := list.New()
	for i := 1; i <= qtd; i++ {
		l.PushBack(i)
	}
	sword := l.Front()
	for range chosen - 1 {
		sword = Next(l, sword)
	}
	for range qtd - 1 {
		fmt.Println(ToStr(l, sword))
		l.Remove(Next(l, sword))
		sword = Next(l, sword)
	}
	fmt.Println(ToStr(l, sword))
}
