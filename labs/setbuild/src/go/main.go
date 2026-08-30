package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"  // @DROP
	"sort"    // @DROP
	"strconv" // @DROP
	"strings"
)

// @DROP
type Set struct {
	data     []int
	size     int
	capacity int
}

func NewSet(capacity int) *Set {
	return &Set{
		data:     make([]int, capacity),
		size:     0,
		capacity: capacity,
	}
}

// retorna onde o valor está ou -1
func (v *Set) binarySearch(value int) int {
	low, high := 0, v.size-1
	for low <= high {
		mid := (low + high) / 2
		if v.data[mid] == value {
			return mid
		} else if v.data[mid] < value {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return -1
}

// Insere um valor de forma ordenada se não estiver presente
func (v *Set) Insert(value int) error {
	if v.size == v.capacity {
		v.Reserve(max(1, v.capacity*2))
	}
	if v.binarySearch(value) != -1 {
		return fmt.Errorf("valor %d já existe", value)
	}
	v.data[v.size] = value
	v.size++
	sort.Ints(v.data[:v.size])
	return nil
}

// Remove um valor se estiver presente usando o binarySearch
func (v *Set) Erase(value int) error {
	index := v.binarySearch(value)
	if index == -1 {
		return fmt.Errorf("value not found")
	}
	v.data = slices.Delete(v.data, index, index+1)
	v.size--
	return nil
}

// Verifica se o valor está presente usando o binarySearch
func (v *Set) Contains(value int) bool {
	return v.binarySearch(value) != -1
}

func (v *Set) Reserve(newCapacity int) {
	if newCapacity > v.capacity {
		newData := make([]int, newCapacity)
		copy(newData, v.data)
		v.data = newData
		v.capacity = newCapacity
	}
}

func (v *Set) Size() int {
	return v.size
}

func Join(slice []int, sep string) string {
	if len(slice) == 0 {
		return ""
	}
	result := fmt.Sprintf("%d", slice[0])
	for _, value := range slice[1:] {
		result += sep + fmt.Sprintf("%d", value)
	}
	return result
}

func (v *Set) String() string {
	return fmt.Sprintf("[%s]", Join(v.data[:v.size], ", "))
}

func (v *Set) Clear() {
	v.size = 0
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @KEEP
func main() {
	var line, cmd string
	scanner := bufio.NewScanner(os.Stdin)

	// @COM
	v := NewSet(0)
	// @KEEP
	for scanner.Scan() {
		fmt.Print("$")
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
			v = NewSet(value)
		case "insert":
			// @COM
			for _, part := range parts[1:] {
				value, _ := strconv.Atoi(part)
				// @DROP
				v.Insert(value)
			}
		case "show":
			// @COM
			// @DROP
			fmt.Println(v)
		case "erase":
			// @COM
			value, _ := strconv.Atoi(parts[1])
			// @DROP
			err := v.Erase(value)
			if err != nil {
				fmt.Println(err)
			}
		case "contains":
			// @COM
			value, _ := strconv.Atoi(parts[1])
			// @DROP
			if v.Contains(value) {
				fmt.Println("true")
			} else {
				fmt.Println("false")
			}
		case "clear":
			// @COM
			// @DROP
			v.Clear()
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
