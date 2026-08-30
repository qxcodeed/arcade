package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv" // @DROP
	"strings"
)

// @DROP

type Node struct {
	Value int
	next  *Node
	prev  *Node
}

type LList struct {
	root *Node
}

func NewNode(v int) *Node {
	return &Node{Value: v}
}

func NewLList() *LList {
	root := NewNode(0)
	root.next = root
	root.prev = root
	return &LList{
		root: root,
	}
}

func (l *LList) PushBack(value int) {
	n := NewNode(value)
	n.prev = l.root.prev
	n.next = l.root
	l.root.prev.next = n
	l.root.prev = n
}

func (l *LList) PushFront(value int) {
	n := NewNode(value)
	n.next = l.root.next
	n.prev = l.root
	l.root.next.prev = n
	l.root.next = n
}

func (l *LList) PopBack() {
	// !DEL
	if l.root.prev == l.root {
		return
	}
	l.root.prev = l.root.prev.prev
	l.root.prev.next = l.root
}

func (l *LList) PopFront() {
	// !DEL
	if l.root.next == l.root {
		return
	}
	l.root.next = l.root.next.next
	l.root.next.prev = l.root
}

func (l *LList) Clear() {
	// !DEL
	l.root.next = l.root
	l.root.prev = l.root
}

func (l *LList) Size() int {
	// !DEL
	size := 0
	n := l.root.next
	for n != l.root {
		size++
		n = n.next
	}
	return size
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

// @KEEP

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	ll := NewLList() // @COM

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
			// @COM
			fmt.Println(ll.String())
		case "size":
			// @COM
			fmt.Println(ll.Size())
		case "push_back":
			// @COM
			for _, v := range args[1:] {
				num, _ := strconv.Atoi(v)
				ll.PushBack(num)
			}
		case "push_front":
			// @COM
			for _, v := range args[1:] {
				num, _ := strconv.Atoi(v)
				ll.PushFront(num)
			}
		case "pop_back":
			// @COM
			ll.PopBack()
		case "pop_front":
			// @COM
			ll.PopFront()
		case "clear":
			// @COM
			ll.Clear()
		case "end":
			return
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
