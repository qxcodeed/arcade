package main

import (
	"bufio"
	"fmt"
	"os"
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


func main() {
	scanner := bufio.NewScanner(os.Stdin)
// 	ll := NewLList[int]()

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
		case "clear":
			// ll.Clear()
		case "forward":
			// search, _ := strconv.Atoi(args[1])
			// steps, _ := strconv.Atoi(args[2])
			// node := ll.Search(search)
			// if node == nil {
			// 	fmt.Println("fail: valor não encontrado")
			// 	continue
			// }
			// collect := []string{}
			// for range steps {
			// 	collect = append(collect, fmt.Sprintf("%v", node.Value))
			// 	node = node.Next()
			// }
			// fmt.Printf("[ %s ]\n", strings.Join(collect, " "))
		case "backward":
			// search, _ := strconv.Atoi(args[1])
			// steps, _ := strconv.Atoi(args[2])
			// node := ll.Search(search)
			// if node == nil {
			// 	fmt.Println("fail: valor não encontrado")
			// 	continue
			// }
			// collect := []string{}
			// for range steps {
			// 	collect = append(collect, fmt.Sprintf("%v", node.Value))
			// 	node = node.Prev()
			// }
			// fmt.Printf("[ %s ]\n", strings.Join(collect, " "))
		case "end":
			return
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
