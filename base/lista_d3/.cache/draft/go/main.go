package main

import (
	"bufio"
	"fmt"
	"strconv"
	"strings"
)

type Node struct {
	Value int
	next  *Node
	prev  *Node
	root  *Node
}

func (n *Node) Next() *Node {
	if n.next == nil || n.next == n.root {
		return nil
	}
	return n.next
}

func (n *Node) Prev() *Node {
	if n.prev == nil || n.prev == n.root {
		return nil
	}
	return n.prev
}

type LList struct {
	root *Node
	size int
}

func NewLList() *LList {
	list := &LList{}
	list.root = &Node{root: nil}
	list.root.next = list.root
	list.root.prev = list.root
	list.root.root = list.root // nó sentinela aponta pra si mesmo
	return list
}

func (l *LList) Size() int {
	size := 0
	for n := l.root.next; n != l.root; n = n.next {
		size++
	}
	return size
}

func (l *LList) Clear() {
	l.root.next = l.root
	l.root.prev = l.root
}

func (l *LList) PushFront(value int) {
	l.insertAfter(l.root, value)
}

func (l *LList) PushBack(value int) {
	l.insertBefore(l.root, value)
}

func (l *LList) PopFront() {
	if l.Size() > 0 {
		l.Remove(l.root.next)
	}
}

func (l *LList) PopBack() {
	if l.Size() > 0 {
		l.Remove(l.root.prev)
	}
}

func (l *LList) Front() *Node {
	if l.Size() == 0 {
		return nil
	}
	return l.root.next
}

func (l *LList) Back() *Node {
	if l.Size() == 0 {
		return nil
	}
	return l.root.prev
}

func (l *LList) Search(value int) *Node {
	for n := l.root.next; n != l.root; n = n.next {
		if n.Value == value {
			return n
		}
	}
	return nil
}

func (l *LList) Insert(node *Node, value int) {
	if node == nil || node.root != l.root {
		return
	}
	l.insertBefore(node, value)
}

func (l *LList) Remove(node *Node) *Node {
	if node == nil || node == l.root || node.root != l.root {
		return nil
	}
	node.prev.next = node.next
	node.next.prev = node.prev
	next := node.next
	return next
}

func (l *LList) insertBefore(mark *Node, value int) {
	n := &Node{
		Value: value,
		root:  l.root,
	}
	n.prev = mark.prev
	n.next = mark
	mark.prev.next = n
	mark.prev = n
}

func (l *LList) insertAfter(mark *Node, value int) {
	n := &Node{
		Value: value,
		root:  l.root,
	}
	n.next = mark.next
	n.prev = mark
	mark.next.prev = n
	mark.next = n
}

func (l *LList) String() string {
	values := []string{}
	n := l.root.next
	for n != l.root {
		values = append(values, fmt.Sprint(n.Value))
		n = n.next
	}
	return "[" + strings.Join(values, ", ") + "]"
}

func equals(a, b *LList) bool {
	if a.Size() != b.Size() {
		return false
	}
	na := a.Front()
	nb := b.Front()
	for {
		if na == nil && nb == nil {
			return true
		}
		if na == nil || nb == nil {
			return false
		}
		if na.Value != nb.Value {
			return false
		}
		na = na.Next()
		nb = nb.Next()
	}
}

func addsorted(l *LList, value int) {
	// Adiciona o valor na lista de forma ordenada
	if l.Size() == 0 {
		l.PushFront(value)
		return
	}

	n := l.Front()
	for n != nil {
		if value < n.Value {
			l.insertBefore(n, value)
			return
		}
		n = n.Next()
	}
	l.PushBack(value)
}

func reverse(l *LList) {
	// Inverte a lista
	if l.Size() < 2 {
		return
	}

	i := l.Front()
	j := l.Back()
	for range l.Size() / 2 {
		i.Value, j.Value = j.Value, i.Value
		i = i.Next()
		j = j.Prev()
	}
}

// merge two sorted lists into one sorted list
func merge(a, b *LList) *LList {
	result := NewLList()
	na := a.Front()
	nb := b.Front()
	for na != nil && nb != nil {
		if na.Value < nb.Value {
			result.PushBack(na.Value)
			na = na.Next()
		} else {
			result.PushBack(nb.Value)
			nb = nb.Next()
		}
	}
	for na != nil {
		result.PushBack(na.Value)
		na = na.Next()
	}
	for nb != nil {
		result.PushBack(nb.Value)
		nb = nb.Next()
	}
	return result
}


func str2list(serial string) *LList {
	serial = serial[1 : len(serial)-1]
	ll := NewLList()
	if serial == "" {
		return ll
	}
	for p := range strings.SplitSeq(serial, ",") {
		value, _ := strconv.Atoi(p)
		ll.PushBack(value)
	}
	return ll
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	for {
		fmt.Print("$")
		if !scanner.Scan() {
			break
		}
		line := scanner.Text()
		fmt.Println(line)
		args := strings.Fields(line)

		if len(args) == 0 {
			continue
		}

		cmd := args[0]

		switch cmd {
		case "compare":
			lla := str2list(args[1])
			llb := str2list(args[2])
			if equals(lla, llb) {
				fmt.Println("iguais")
			} else {
				fmt.Println("diferentes")
			}
		case "addsorted":
			lla := NewLList()
			for i := 1; i < len(args); i++ {
				value, _ := strconv.Atoi(args[i])
				addsorted(lla, value)
			}
			fmt.Println(lla)
		case "reverse":
			lla := str2list(args[1])
			reverse(lla)
			fmt.Println(lla)
		case "merge":
			lla := str2list(args[1])
			llb := str2list(args[2])
			merged := merge(lla, llb)
			fmt.Println(merged)
		case "end":
			return
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
