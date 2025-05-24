package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// // Essa função vai de brinde pra você
// func (b *CircularBuffer) String() string {
// 	result := []string{}
// 	for i := range b.size {
// 		val := b.data[(b.head+i)%b.capacity]
// 		result = append(result, fmt.Sprint(val))
// 	}
// 	return "[" + strings.Join(result, ", ") + "]"
// }
// 
func main() {
	scanner := bufio.NewScanner(os.Stdin)
// 	buf := NewCircularBuffer(4)

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
			// fmt.Println(buf.String())
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
			// buf.PopBack()
		case "pop_front":
			// buf.PopFront()
		case "clear":
			// buf.Clear()
		case "end":
			return
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
