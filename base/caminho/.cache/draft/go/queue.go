package main

import (
	"container/list"
)

// Implmentação de uma fila genérica usando a lista duplamente encadeada do pacote container/list
type Queue[T any] struct {
	queue list.List
}

func NewQueue[T any]() *Queue[T] {
	return &Queue[T]{
		queue: *list.New(),
	}
}
func (q *Queue[T]) Enqueue(value T) {
	q.queue.PushBack(value)
}
func (q *Queue[T]) Dequeue() (T, bool) {
	element := q.queue.Front()
	if element == nil {
		var zero T
		return zero, false
	}
	q.queue.Remove(element)
	value := element.Value.(T)
	return value, true
}
func (q *Queue[T]) Peek() (T, bool) {
	element := q.queue.Front()
	if element == nil {
		var zero T
		return zero, false
	}
	value := element.Value.(T)
	return value, true
}
func (q *Queue[T]) IsEmpty() bool {
	return q.queue.Len() == 0
}
