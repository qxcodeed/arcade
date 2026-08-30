// @KEEP
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv" // @DROP
	"strings"
)

type Deque struct {
	data     []int
	front    int
	size     int
	capacity int
}

// @DROP

func NewDeque(capacity int) *Deque {
	if capacity < 1 {
		panic("capacity must be > 0")
	}
	return &Deque{
		data:     make([]int, capacity),
		capacity: capacity,
	}
}

func (b *Deque) Len() int {
	return b.size
}

func (b *Deque) IsEmpty() bool {
	return b.size == 0
}

func (b *Deque) IsFull() bool {
	return b.size == b.capacity
}

func (b *Deque) resize(newCap int) {
	newData := make([]int, newCap)
	for i := range b.size {
		newData[i] = b.data[(b.front+i)%b.capacity]
	}
	b.data = newData
	b.front = 0
	b.capacity = newCap
}

func (b *Deque) PushBack(value int) {
	if b.IsFull() {
		b.resize(b.capacity * 2)
	}
	index := (b.front + b.size) % b.capacity
	b.data[index] = value
	b.size++
}

func (b *Deque) PushFront(value int) {
	if b.IsFull() {
		b.resize(b.capacity * 2)
	}
	b.front = (b.front - 1 + b.capacity) % b.capacity
	b.data[b.front] = value
	b.size++
}

func (b *Deque) PopFront() error {
	if b.IsEmpty() {
		return fmt.Errorf("fail: buffer vazio")
	}
	b.front = (b.front + 1) % b.capacity
	b.size--
	return nil
}

func (b *Deque) PopBack() error {
	if b.IsEmpty() {
		return fmt.Errorf("fail: buffer vazio")
	}
	index := (b.front + b.size - 1) % b.capacity
	b.data[index] = 0 // Limpa o valor
	b.size--
	return nil
}

func (b *Deque) Clear() {
	b.front = 0
	b.size = 0
}

func (b *Deque) Front() (int, error) {
	if b.IsEmpty() {
		return 0, fmt.Errorf("fail: buffer vazio")
	}
	return b.data[b.front], nil
}
func (b *Deque) Back() (int, error) {
	if b.IsEmpty() {
		return 0, fmt.Errorf("fail: buffer vazio")
	}
	index := (b.front + b.size - 1) % b.capacity
	return b.data[index], nil
}

// @KEEP
func (b *Deque) String() string {
	result := []string{}
	for i := range b.size {
		val := b.data[(b.front+i)%b.capacity]
		result = append(result, fmt.Sprint(val))
	}
	return "[" + strings.Join(result, ", ") + "]"
}

func (b *Deque) Debug() string {
	result := make([]string, b.capacity)
	for i, _ := range result {
		result[i] = " _"
		if i == b.front {
			result[i] = ">_"
		}
	}
	for i := range b.size {
		index := (b.front + i) % b.capacity
		val := b.data[index]
		prefix := " "
		if i == 0 {
			prefix = ">"
		}
		result[index] = fmt.Sprintf("%s%d", prefix, val)
	}
	return strings.Join(result, " |")
}

// @KEEP
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	buf := &Deque{data: make([]int, 4), capacity: 4}

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
			fmt.Println(buf.String())
		case "debug":
			fmt.Println(buf.Debug())
		case "size":
			// @COM
			fmt.Println(buf.Len())
		case "push_back":
			// @COM
			for _, v := range args[1:] {
				num, _ := strconv.Atoi(v)
				buf.PushBack(num)
			}
		case "push_front":
			// @COM
			for _, v := range args[1:] {
				num, _ := strconv.Atoi(v)
				buf.PushFront(num)
			}
		case "pop_back":
			// @COM
			if err := buf.PopBack(); err != nil {
				fmt.Println(err)
			}
		case "pop_front":
			// @COM
			if err := buf.PopFront(); err != nil {
				fmt.Println(err)
			}
		case "front":
			// @COM
			if val, err := buf.Front(); err != nil {
				fmt.Println(err)
			} else {
				fmt.Println(val)
			}
		case "back":
			// @COM
			if val, err := buf.Back(); err != nil {
				fmt.Println(err)
			} else {
				fmt.Println(val)
			}
		case "clear":
			// @COM
			buf.Clear()
		case "end":
			return
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
