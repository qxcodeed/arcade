package main

import "fmt"

type Stack[T any] struct {
	data []T
}

func NewStack[T any](cap int) *Stack[T] {
	return &Stack[T]{data: make([]T, 0, cap)}
}

func (s *Stack[T]) Push(value T) {
	s.data = append(s.data, value)
}

func (s *Stack[T]) Pop() error {
	if len(s.data) == 0 {
		return fmt.Errorf("stack is empty")
	}
	s.data = s.data[:len(s.data)-1]
	return nil
}

func (s *Stack[T]) Top() (T, error) {
	if len(s.data) == 0 {
		var zero T
		return zero, fmt.Errorf("stack is empty")
	}
	return s.data[len(s.data)-1], nil
}

func (s *Stack[T]) IsEmpty() bool {
	return len(s.data) == 0
}

func (s *Stack[T]) Size() int {
	return len(s.data)
}

func (s *Stack[T]) Clear() {
	s.data = s.data[:0]
}

func (s *Stack[T]) String() string {
	output := "["
	for i, v := range s.data {
		if i != 0 {
			output += ", "
		}
		output += fmt.Sprintf("%v", v)
	}
	output += "]"
	return output
}
