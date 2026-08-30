package main

import (
	"container/list"
	"fmt"
)

// mostra a lista com o elemento sword destacado
func ToStr(l *list.List, sword *list.Element) string {
	// @DROP
	var str string = "" //fmt.Sprint(sword.Value.(int))
	str += "[ "
	for e := l.Front(); e != nil; e = e.Next() {
		if e == sword {
			if e.Value.(int) > 0 {
				str += fmt.Sprintf("%v> ", e.Value)
			} else {
				str += fmt.Sprintf("<%v ", e.Value)
			}
		} else {
			str += fmt.Sprintf("%v ", e.Value)
		}
	}
	return str + "]"
	// @UNC
	// return ""
}

// move para frente na lista circular
func Next(l *list.List, it *list.Element) *list.Element {
	// @DROP
	it = it.Next()
	if it == nil {
		it = l.Front()
	}
	return it
	// @UNC
	// return nil
}

// move para tras na lista circular
func Prev(l *list.List, it *list.Element) *list.Element {
	// @DROP
	it = it.Prev()
	if it == nil {
		it = l.Back()
	}
	return it
	// @UNC
	// return l.Front()
}

func main() {
	var qtd, chosen, fase int
	fmt.Scan(&qtd, &chosen, &fase)
	l := list.New()
	for i := 1; i <= qtd; i++ {
		l.PushBack(i * fase)
		fase = -fase
	}
	sword := l.Front()
	for range chosen - 1 {
		sword = Next(l, sword)
	}
	for range qtd - 1 {
		fmt.Println(ToStr(l, sword))
		if sword.Value.(int) > 0 {
			l.Remove(Next(l, sword))
			sword = Next(l, sword)
		} else {
			l.Remove(Prev(l, sword))
			sword = Prev(l, sword)
		}
	}
	fmt.Println(ToStr(l, sword))
}
