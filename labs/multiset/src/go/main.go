package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv" // @DROP
	"strings"
)

// @DROP

type MultiSet struct {
	data     []int
	size     int
	capacity int
}

func NewMultiSet(capacity int) *MultiSet {
	return &MultiSet{
		data:     make([]int, capacity),
		size:     0,
		capacity: capacity,
	}
}

// Se o valor já existe, retorna a última posição onde ele está
// Se não existe, retorna a posição onde ele deve ser inserido
// Utilize a estratégia da busca binária para descobrir a posição de alguma das ocorrências
func (ms *MultiSet) magicSearch(value int) int {
	low, high := 0, ms.size-1
	pos := -1
	for low <= high {
		mid := (low + high) / 2
		if ms.data[mid] == value {
			pos = mid
			break
		} else if ms.data[mid] < value {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	if pos != -1 {
		for {
			if pos+1 < ms.size && ms.data[pos+1] == value {
				pos++
			} else {
				break
			}
		}
		return pos
	}
	return low
}

// Insere o valor nessa posição deslocando os elementos para frente
func (ms *MultiSet) insert(value int, index int) error {
	if index > ms.size {
		return fmt.Errorf("index out of bounds")
	}
	if ms.size == ms.capacity {
		ms.expand()
	}
	ms.size += 1
	for i := ms.size - 1; i > index; i-- {
		ms.data[i] = ms.data[i-1]
	}
	ms.data[index] = value
	return nil
}

func (ms *MultiSet) match(index, value int) bool {
	return index >= 0 && index < ms.size && ms.data[index] == value
}

func (ms *MultiSet) Insert(value int) {
	idx := ms.magicSearch(value)
	if err := ms.insert(value, idx); err != nil {
		fmt.Println(err)
	}
}

func (ms *MultiSet) erase(index int) error {
	if index < 0 || index >= ms.size {
		return fmt.Errorf("index out of bounds")
	}
	for i := index; i < ms.size-1; i++ {
		ms.data[i] = ms.data[i+1]
	}
	ms.size -= 1
	return nil
}

func (ms *MultiSet) Erase(value int) error {
	idx := ms.magicSearch(value)
	if !ms.match(idx, value) {
		return fmt.Errorf("value not found")
	}
	return ms.erase(idx)
}

func (ms *MultiSet) Contains(value int) bool {
	idx := ms.magicSearch(value)
	return ms.match(idx, value)
}

func (ms *MultiSet) Count(value int) int {
	idx := ms.magicSearch(value)
	count := 0
	for ms.match(idx, value) {
		count += 1
		idx -= 1
	}
	return count
}

func (ms *MultiSet) Unique() int {
	if ms.size == 0 {
		return 0
	}
	diff := 1
	for i := 1; i < ms.size; i++ {
		if ms.data[i] != ms.data[i-1] {
			diff++
		}
	}
	return diff
}

// se for 0, vai para 1
// se não, dobra a capacidade atual
func (ms *MultiSet) expand() {
	newCapacity := max(1, 2*ms.capacity)
	newData := make([]int, newCapacity)
	copy(newData, ms.data)
	ms.data = newData
	ms.capacity = newCapacity
}

func (ms *MultiSet) String() string {
	return fmt.Sprintf("[%s]", Join(ms.data[:ms.size], ", "))
}

func (ms *MultiSet) Clear() {
	ms.size = 0
}

// @KEEP
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

func main() {
	var line, cmd string
	scanner := bufio.NewScanner(os.Stdin)
	// @COM
	ms := NewMultiSet(0)
	// @KEEP

	for scanner.Scan() {
		fmt.Print("$")
		line = scanner.Text()
		args := strings.Fields(line)
		fmt.Println(line)
		if len(args) == 0 {
			continue
		}
		cmd = args[0]

		switch cmd {
		case "end":
			return
		case "init":
			// @COM
			value, _ := strconv.Atoi(args[1])
			ms = NewMultiSet(value)
		case "insert":
			// @COM
			for _, part := range args[1:] {
				value, _ := strconv.Atoi(part)
				// @DROP
				ms.Insert(value)
			}
		case "show":
			// @COM
			// @DROP
			fmt.Println(ms)
		case "erase":
			// @COM
			value, _ := strconv.Atoi(args[1])
			// @DROP
			err := ms.Erase(value)
			if err != nil {
				fmt.Println(err)
			}
		case "contains":
			// @COM
			value, _ := strconv.Atoi(args[1])
			// @DROP
			fmt.Println(ms.Contains(value))
		case "count":
			// @COM
			value, _ := strconv.Atoi(args[1])
			// @DROP
			fmt.Println(ms.Count(value))
		case "unique":
			// @COM
			// @DROP
			fmt.Println(ms.Unique())
		case "clear":
			// @COM
			// @DROP
			ms.Clear()
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
