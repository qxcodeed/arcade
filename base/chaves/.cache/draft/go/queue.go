package main

import (
	"container/list"
	"fmt"
)

type Queue[T any] struct {
	items *list.List
}

func NewQueue[T any]() *Queue[T] {
	return &Queue[T]{items: list.New()}
}

func (q *Queue[T]) Enqueue(item T) {
	q.items.PushBack(item)
}

func (q *Queue[T]) Dequeue() T {
	if q.items.Len() == 0 {
		var zero T
		return zero // Return zero value if queue is empty
	}
	front := q.items.Front().Value.(T)
	q.items.Remove(q.items.Front())
	return front
}

func (q *Queue[T]) IsEmpty() bool {
	return q.items.Len() == 0
}

func (q *Queue[T]) String() string {
	var result string
	for e := q.items.Front(); e != nil; e = e.Next() {
		result += fmt.Sprint(e.Value.(T)) + " "
	}
	return "[ " + result + "]"
}
