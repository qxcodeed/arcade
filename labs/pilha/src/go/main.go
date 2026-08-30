package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv" // @DROP
	"strings"
)

type Stack[T any] struct {
	data []T
}

// @DROP
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

func (s *Stack[T]) Peek() (T, error) {
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

// @COM
func (s *Stack[T]) String() string {
	output := ""
	for i := range cap(s.data) {
		if i != 0 {
			output += ", "
		}
		if i < len(s.data) {
			output += fmt.Sprintf("%v", s.data[i])
		} else {
			output += "_"
		}
	}
	return output
}

// @KEEP
func main() {
	var line, cmd string
	scanner := bufio.NewScanner(os.Stdin)

	// @COM
	v := NewStack[int](10)
	// @KEEP
	for {
		fmt.Print("$")
		if !scanner.Scan() {
			break
		}
		line = scanner.Text()
		fmt.Println(line)
		parts := strings.Fields(line)
		if len(parts) == 0 {
			continue
		}
		cmd = parts[0]

		switch cmd {
		case "end":
			return
		case "init":
			// @COM
			cap, _ := strconv.Atoi(parts[1])
			v = NewStack[int](cap)
		case "push":
			// @COM
			for _, part := range parts[1:] {
				value, _ := strconv.Atoi(part)
				v.Push(value)
			}
		case "debug":
			// @COM
			fmt.Println(v)
		case "top":
			// @COM
			top, err := v.Peek()
			if err != nil {
				fmt.Println(err)
			} else {
				fmt.Println(top)
			}
		case "size":
			// @COM
			fmt.Println(v.Size())
		case "pop":
			// @COM
			err := v.Pop()
			if err != nil {
				fmt.Println(err)
			}
		case "clear":
			// @COM
			v.Clear()
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
