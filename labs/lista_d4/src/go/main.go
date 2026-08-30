package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv" // @DROP
	"strings"
)

type Node[T comparable] struct {
	Value T
	next  *Node[T]
	prev  *Node[T]
	root  *Node[T]
}

type LList[T comparable] struct {
	root *Node[T]
	size int
}

func NewLList[T comparable]() *LList[T] {
	root := &Node[T]{}
	root.next = root
	root.prev = root
	root.root = root
	return &LList[T]{root: root, size: 0}
}

func (n *Node[T]) Next() *Node[T] {
	if n.next == n.root {
		return n.root.next
	}
	return n.next
}

func (l *LList[T]) PushBack(value T) {
	l.insertBefore(l.root, value)
}

func (l *LList[T]) insertBefore(mark *Node[T], value T) {
	n := &Node[T]{Value: value, root: l.root}
	n.prev = mark.prev
	n.next = mark
	mark.prev.next = n
	mark.prev = n
	l.size++
}

func (l *LList[T]) String() string {
	values := []string{}
	for n := l.root.next; n != l.root; n = n.next {
		values = append(values, fmt.Sprint(n.Value))
	}
	return "[" + strings.Join(values, ", ") + "]"
}

// @DROP

func (l *LList[T]) Search(value T) *Node[T] {
	for n := l.root.next; n != l.root; n = n.next {
		if n.Value == value {
			return n
		}
	}
	return nil
}

func (n *Node[T]) Prev() *Node[T] {
	if n.prev == nil {
		return nil
	}
	if n.prev == n.root {
		return n.root.prev
	}
	return n.prev
}

func (l *LList[T]) Size() int {
	return l.size
}

func (l *LList[T]) Clear() {
	l.root.next = l.root
	l.root.prev = l.root
	l.size = 0
}

func (l *LList[T]) Front() *Node[T] {
	if l.size == 0 {
		return nil
	}
	return l.root.next
}

func (l *LList[T]) Back() *Node[T] {
	if l.size == 0 {
		return nil
	}
	return l.root.prev
}

// @KEEP

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	ll := NewLList[int]() // @COM

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
		case "clear":
			// @COM
			ll.Clear()
		case "forward":
			// @COM
			search, _ := strconv.Atoi(args[1])
			steps, _ := strconv.Atoi(args[2])
			node := ll.Search(search)
			if node == nil {
				fmt.Println("fail: valor não encontrado")
				continue
			}
			collect := []string{}
			for range steps {
				collect = append(collect, fmt.Sprintf("%v", node.Value))
				node = node.Next()
			}
			fmt.Printf("[ %s ]\n", strings.Join(collect, " "))
		case "backward":
			// @COM
			search, _ := strconv.Atoi(args[1])
			steps, _ := strconv.Atoi(args[2])
			node := ll.Search(search)
			if node == nil {
				fmt.Println("fail: valor não encontrado")
				continue
			}
			collect := []string{}
			for range steps {
				collect = append(collect, fmt.Sprintf("%v", node.Value))
				node = node.Prev()
			}
			fmt.Printf("[ %s ]\n", strings.Join(collect, " "))
		case "end":
			return
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
