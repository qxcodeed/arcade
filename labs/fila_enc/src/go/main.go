package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv" // @DROP
	"strings"
)

// func (q *Queue[T]) Enqueue(value T)
// func (q *Queue[T]) Dequeue() (T, bool)
// func (q *Queue[T]) Peek() (T, bool)
// func (q *Queue[T]) Size() int
// func (q *Queue[T]) IsEmpty() bool
// func (q *Queue[T]) Clear()

type Node[T any] struct {
	Value T
	next  *Node[T]
}

type Queue[T any] struct {
	head *Node[T]
	tail *Node[T]
	size int
}

func NewQueue[T any]() *Queue[T] {
	return &Queue[T]{}
}

// @DROP
func (q *Queue[T]) Enqueue(value T) {
	node := &Node[T]{Value: value}
	if q.tail != nil {
		q.tail.next = node
	}
	q.tail = node
	if q.head == nil {
		q.head = node
	}
	q.size++
}
func (q *Queue[T]) Dequeue() (T, bool) {
	if q.head == nil {
		var zero T
		return zero, false
	}
	value := q.head.Value
	q.head = q.head.next
	if q.head == nil {
		q.tail = nil
	}
	q.size--
	return value, true
}

func (q *Queue[T]) Peek() (T, bool) {
	if q.head == nil {
		var zero T
		return zero, false
	}
	return q.head.Value, true
}

func (q *Queue[T]) Size() int {
	return q.size
}

func (q *Queue[T]) IsEmpty() bool {
	return q.size == 0
}

func (q *Queue[T]) Clear() {
	q.head = nil
	q.tail = nil
	q.size = 0
}

// @KEEP
func (q *Queue[T]) String() string {
	result := "["
	for n := q.head; n != nil; n = n.next {
		if n != q.head {
			result += ", "
		}
		result += fmt.Sprintf("%v", n.Value)
	}
	return result + "]"
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	queue := NewQueue[int]()

	for {
		if !scanner.Scan() {
			break
		}
		line := scanner.Text()
		fmt.Println("$" + line)
		args := strings.Fields(line)
		if len(args) == 0 {
			continue
		}
		switch args[0] {
		case "end":
			break
		case "show":
			fmt.Println(queue)
		case "push":
			// @COM
			for _, arg := range args[1:] {
				value, _ := strconv.Atoi(arg)
				queue.Enqueue(value)
			}
		case "pop":
			// @COM
			if _, ok := queue.Dequeue(); !ok {
				fmt.Println("falha: fila vazia")
			}
		case "peek":
			// @COM
			if value, ok := queue.Peek(); ok {
				fmt.Println(value)
			} else {
				fmt.Println("falha: fila vazia")
			}
		default:
			fmt.Println("Unknown command:", args[0])
		}
	}
}
