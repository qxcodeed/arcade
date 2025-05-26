package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Deque struct {
	data     []int
	front    int
	size     int
	capacity int
}

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
			// fmt.Println(buf.Len())
		case "push_back":
			// for _, v := range args[1:] {
			// 	num, _ := strconv.Atoi(v)
			// 	buf.PushBack(num)
			// }
		case "push_front":
			// for _, v := range args[1:] {
			// 	num, _ := strconv.Atoi(v)
			// 	buf.PushFront(num)
			// }
		case "pop_back":
			// if err := buf.PopBack(); err != nil {
			// 	fmt.Println(err)
			// }
		case "pop_front":
			// if err := buf.PopFront(); err != nil {
			// 	fmt.Println(err)
			// }
		case "front":
			// if val, err := buf.Front(); err != nil {
			// 	fmt.Println(err)
			// } else {
			// 	fmt.Println(val)
			// }
		case "back":
			// if val, err := buf.Back(); err != nil {
			// 	fmt.Println(err)
			// } else {
			// 	fmt.Println(val)
			// }
		case "clear":
			// buf.Clear()
		case "end":
			return
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
