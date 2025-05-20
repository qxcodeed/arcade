package main

import (
	"strings"
)

type Node[T any] struct {
	Value T
	next  *Node[T]
	prev  *Node[T]
	root  *Node[T]
}

type List[T any] struct {
	root *Node[T]
	size int
}

func NewList[T any]() *List[T] {
	root := &Node[T]{}
	root.next = root
	root.prev = root
	root.root = root
	return &List[T]{root: root, size: 0}
}

func (n *Node[T]) Next() *Node[T] {
	return n.next
}

func (l *List[T]) PushBack(value T) {
	l.Insert(l.root, value)
}

func (l *List[T]) Insert(mark *Node[T], value T) *Node[T] {
	n := &Node[T]{Value: value, root: l.root}
	n.prev = mark.prev
	n.next = mark
	mark.prev.next = n
	mark.prev = n
	l.size++
	return n
}

func (l *List[T]) String() string {
	values := []string{}
	for n := l.root.next; n != l.root; n = n.next {
		values = append(values, fmt.Sprint(n.Value))
	}
	return "[" + strings.Join(values, ", ") + "]"
}

func (n *Node[T]) Prev() *Node[T] {
	return n.prev
}

func (l *List[T]) Size() int {
	return l.size
}

func (l *List[T]) Clear() {
	l.root.next = l.root
	l.root.prev = l.root
	l.size = 0
}

func (l *List[T]) End() *Node[T] {
	return l.root
}

func (l *List[T]) Front() *Node[T] {
	if l.size == 0 {
		return l.root
	}
	return l.root.next
}

func (l *List[T]) Back() *Node[T] {
	if l.size == 0 {
		return l.root
	}
	return l.root.prev
}

func (l *List[T]) Remove(n *Node[T]) *Node[T] {
	if n == l.root {
		return l.root
	}
	n.prev.next = n.next
	n.next.prev = n.prev
	l.size--
	return n.next
}

func (l *List[T]) IndexOf(n *Node[T]) int {
	if n == l.root {
		return l.size
	}
	if n.root != l.root {
		return -1
	}
	i := 0
	for it := l.root.next; it != n; it = it.next {
		i++
		if i >= l.size {
			return -1
		}
	}
	return i
}
