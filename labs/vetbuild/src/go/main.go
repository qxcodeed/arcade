package main

import (
	"bufio"
	"fmt"
	"os"      // @DROP
	"strconv" // @DROP
	"strings"
)

type Vector struct {
	data     []int
	size     int
	capacity int
}

func NewVector(capacity int) *Vector {
	return &Vector{
		data:     make([]int, capacity), // nunca use len(data) ou cap(data) ou qq método do go de manipulação de array
		size:     0,
		capacity: capacity,
	}
}

// @DROP

func (v *Vector) PushBack(value int) {
	if v.size == v.capacity {
		v.Reserve(max(1, v.capacity*2))
	}
	v.data[v.size] = value
	v.size++
}

func (v *Vector) PopBack() error {
	if v.size == 0 {
		return fmt.Errorf("vector is empty")
	}
	v.size--
	return nil
}

func (v *Vector) Insert(index int, value int) error {
	if index < 0 || index > v.size {
		return fmt.Errorf("index out of range")
	}
	if v.size == v.capacity {
		v.Reserve(max(1, v.capacity*2))
	}
	copy(v.data[index+1:], v.data[index:v.size])
	v.data[index] = value
	v.size++
	return nil
}

func (v *Vector) Erase(index int) error {
	if index < 0 || index >= v.size {
		return fmt.Errorf("index out of range")
	}
	copy(v.data[index:], v.data[index+1:v.size])
	v.size--
	return nil
}

func (v *Vector) IndexOf(value int) int {
	for i := range v.size {
		if v.data[i] == value {
			return i
		}
	}
	return -1
}

func (v *Vector) Contains(value int) bool {
	return v.IndexOf(value) != -1
}

func (v *Vector) Reserve(newCapacity int) {
	if newCapacity > v.capacity {
		newData := make([]int, newCapacity)
		copy(newData, v.data)
		v.data = newData
		v.capacity = newCapacity
	}
}

func (v *Vector) Size() int {
	return v.size
}

func (v *Vector) Capacity() int {
	return v.capacity
}

func (v *Vector) Status() string {
	return fmt.Sprintf("size:%v capacity:%v", v.size, v.capacity)
}

func (v *Vector) String() string {
	return fmt.Sprintf("[%s]", Join(v.data[:v.size], ", "))
}

func (v *Vector) Get(index int) int {
	return v.data[index]
}

func (v *Vector) At(index int) (int, error) {
	if index < 0 || index >= v.size {
		return 0, fmt.Errorf("index out of range")
	}
	return v.data[index], nil
}

func (v *Vector) Set(index int, value int) error {
	if index < 0 || index >= v.size {
		return fmt.Errorf("index out of range")
	}
	v.data[index] = value
	return nil
}

func (v *Vector) Clear() {
	v.size = 0
}

func (v *Vector) Slice(start, end int) *Vector {
	start = (start%v.size + v.size) % v.size
	end = (end%v.size + v.size) % v.size
	if end < start {
		end = start
	}
	other := Vector{
		data:     v.data[start:end],
		size:     end - start,
		capacity: end - start,
	}
	return &other
}

// @KEEP

func Join(slice []int, sep string) string {
	if len(slice) == 0 {
		return ""
	}
	var result strings.Builder
	fmt.Fprintf(&result, "%d", slice[0])
	for _, value := range slice[1:] {
		fmt.Fprintf(&result, "%s%d", sep, value)
	}
	return result.String()
}

func main() {
	var line, cmd string
	scanner := bufio.NewScanner(os.Stdin)

	// @COM
	v := NewVector(0)
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
			value, _ := strconv.Atoi(parts[1])
			v = NewVector(value)
		case "push":
			// @COM
			for _, part := range parts[1:] {
				value, _ := strconv.Atoi(part)
				v.PushBack(value)
			}
		case "show":
			// @COM
			fmt.Println(v)
		case "status":
			// @COM
			fmt.Println(v.Status())
		case "pop":
			// @COM
			err := v.PopBack()
			if err != nil {
				fmt.Println(err)
			}
		case "insert":
			// @COM
			index, _ := strconv.Atoi(parts[1])
			value, _ := strconv.Atoi(parts[2])
			err := v.Insert(index, value)
			if err != nil {
				fmt.Println(err)
			}
		case "erase":
			// @COM
			index, _ := strconv.Atoi(parts[1])
			err := v.Erase(index)
			if err != nil {
				fmt.Println(err)
			}
		case "indexOf":
			// @COM
			value, _ := strconv.Atoi(parts[1])
			index := v.IndexOf(value)
			fmt.Println(index)
		case "contains":
			// @COM
			value, _ := strconv.Atoi(parts[1])
			if v.Contains(value) {
				fmt.Println("true")
			} else {
				fmt.Println("false")
			}
		case "clear":
			// @COM
			v.Clear()
		case "capacity":
			// @COM
			fmt.Println(v.Capacity())
		case "get":
			// @COM
			index, _ := strconv.Atoi(parts[1])
			value, err := v.At(index)
			if err != nil {
				fmt.Println(err)
			} else {
				fmt.Println(value)
			}
		case "set":
			// @COM
			index, _ := strconv.Atoi(parts[1])
			value, _ := strconv.Atoi(parts[2])
			err := v.Set(index, value)
			if err != nil {
				fmt.Println(err)
			}

		case "reserve":
			// @COM
			newCapacity, _ := strconv.Atoi(parts[1])
			v.Reserve(newCapacity)
		case "slice":
			// @COM
			start, _ := strconv.Atoi(parts[1])
			end, _ := strconv.Atoi(parts[2])
			slice := v.Slice(start, end)
			fmt.Println(slice)
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
