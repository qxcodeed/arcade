package main

import (
	"fmt"
	"strings"
)

/*
class DNode<T> {
	Value: T
	next, prev, root: *DNode<T>
	Next() *DNode<T>
	Prev() *DNode<T>
}
class DList<T> {
	root: *DNode<T>
	size: int
	___ métodos de alteração ___
	PushBack(value T)
	PushFront(value T)
	PopBack()
	PopFront()
	Insert(it *DNode<T>, value T)
	Erase(it *DNode<T>)
	Clear()
	___ métodos de acesso e percorrimento ___
	Front() *DNode<T>
	Back() *DNode<T>
	End() *DNode<T>
	___
	String() string
	Size() int
*/

type DNode[T comparable] struct {
	Value            T
	next, prev, root *DNode[T]
}

func (n *DNode[T]) Next() *DNode[T] {
	if n == n.root {
		return n
	}
	return n.next
}

func (n *DNode[T]) Prev() *DNode[T] {
	if n == n.root {
		return n
	}
	return n.prev
}

type DList[T comparable] struct {
	root *DNode[T]
	size int
}

func NewDList[T comparable]() *DList[T] {
	root := &DNode[T]{}
	root.next = root
	root.prev = root
	root.root = root
	return &DList[T]{root: root, size: 0}
}

func (l *DList[T]) PushBack(value T) {
	l.Insert(l.root, value)
}

func (l *DList[T]) PopBack() {
	if l.size == 0 {
		return
	}
	l.Erase(l.root.prev)
}

func (l *DList[T]) PopFront() {
	if l.size == 0 {
		return
	}
	l.Erase(l.root.next)
}

func (l *DList[T]) PushFront(value T) {
	l.Insert(l.root.next, value)
}

func (l *DList[T]) Insert(it *DNode[T], value T) *DNode[T] {
	n := &DNode[T]{Value: value, root: l.root}
	n.prev = it.prev
	n.next = it
	it.prev.next = n
	it.prev = n
	l.size++
	return n
}

func (l *DList[T]) Erase(it *DNode[T]) {
	if it == l.root || it == nil {
		return
	}
	it.prev.next = it.next
	it.next.prev = it.prev
	l.size--
}

func (l *DList[T]) String() string {
	values := []string{}
	for n := l.root.next; n != l.root; n = n.next {
		values = append(values, fmt.Sprint(n.Value))
	}
	return "[" + strings.Join(values, ", ") + "]"
}

func (l *DList[T]) Size() int {
	return l.size
}

func (l *DList[T]) Clear() {
	l.root.next = l.root
	l.root.prev = l.root
	l.size = 0
}

func (l *DList[T]) Front() *DNode[T] {
	return l.root.next
}

func (l *DList[T]) Back() *DNode[T] {
	return l.root.prev
}

func (l *DList[T]) End() *DNode[T] {
	return l.root
}
