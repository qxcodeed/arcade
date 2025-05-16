package main

import (
	"bufio"
	"fmt"
	"os"
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
	list := &LList{size: 0}
	list.root = &Node{root: nil}
	list.root.next = list.root
	list.root.prev = list.root
	list.root.root = list.root // nó sentinela aponta pra si mesmo
	return list
}

func (l *LList) Size() int {
	return l.size
}

func (l *LList) Clear() {
	l.root.next = l.root
	l.root.prev = l.root
	l.size = 0
}

func (l *LList) PushFront(value int) {
	l.insertAfter(l.root, value)
}

func (l *LList) PushBack(value int) {
	l.insertBefore(l.root, value)
}

func (l *LList) PopFront() {
	if l.size > 0 {
		l.Remove(l.root.next)
	}
}

func (l *LList) PopBack() {
	if l.size > 0 {
		l.Remove(l.root.prev)
	}
}

func (l *LList) Front() *Node {
	if l.size == 0 {
		return nil
	}
	return l.root.next
}

func (l *LList) Back() *Node {
	if l.size == 0 {
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
	l.size--
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
	l.size++
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
	l.size++
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


func main() {
	scanner := bufio.NewScanner(os.Stdin)
// 	ll := NewLList()

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
		case "show":
			// fmt.Println(ll.String())
		case "size":
			// fmt.Println(ll.Size())
		case "push_back":
			// for _, v := range args[1:] {
			// 	num, _ := strconv.Atoi(v)
			// 	ll.PushBack(num)
			// }
		case "push_front":
			// for _, v := range args[1:] {
			// 	num, _ := strconv.Atoi(v)
			// 	ll.PushFront(num)
			// }
		case "pop_back":
			// ll.PopBack()
		case "pop_front":
			// ll.PopFront()
		case "clear":
			// ll.Clear()
		case "walk":
			// fmt.Print("[ ")
			// for node := ll.Front(); node != nil; node = node.Next() {
			// 	fmt.Printf("%v ", node.Value)
			// }
			// fmt.Print("]\n[ ")
			// for node := ll.Back(); node != nil; node = node.Prev() {
			// 	fmt.Printf("%v ", node.Value)
			// }
			// fmt.Println("]")
		case "replace":
			// oldvalue, _ := strconv.Atoi(args[1])
			// newvalue, _ := strconv.Atoi(args[2])
			// node := ll.Search(oldvalue)
			// if node != nil {
			// 	node.Value = newvalue
			// } else {
			// 	fmt.Println("fail: not found")
			// }
		case "insert":
			// oldvalue, _ := strconv.Atoi(args[1])
			// newvalue, _ := strconv.Atoi(args[2])
			// node := ll.Search(oldvalue)
			// if node != nil {
			// 	ll.Insert(node, newvalue)
			// } else {
			// 	fmt.Println("fail: not found")
			// }
		case "remove":
			// oldvalue, _ := strconv.Atoi(args[1])
			// node := ll.Search(oldvalue)
			// if node != nil {
			// 	ll.Remove(node)
			// } else {
			// 	fmt.Println("fail: not found")
			// }
		case "end":
			return
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
