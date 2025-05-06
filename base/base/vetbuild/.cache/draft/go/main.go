package main

import (
	"bufio"
	"fmt"
	"strings"
)


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

	// v := NewVector(0)
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
			// value, _ := strconv.Atoi(parts[1])
			// v = NewVector(value)
		case "push":
			// for _, part := range parts[1:] {
			// 	value, _ := strconv.Atoi(part)
			// 	v.PushBack(value)
			// }
		case "show":
			// fmt.Println(v)
		case "status":
			// fmt.Println(v.Status())
		case "pop":
			// err := v.PopBack()
			// if err != nil {
			// 	fmt.Println(err)
			// }
		case "insert":
			// index, _ := strconv.Atoi(parts[1])
			// value, _ := strconv.Atoi(parts[2])
			// err := v.Insert(index, value)
			// if err != nil {
			// 	fmt.Println(err)
			// }
		case "erase":
			// index, _ := strconv.Atoi(parts[1])
			// err := v.Erase(index)
			// if err != nil {
			// 	fmt.Println(err)
			// }
		case "indexOf":
			// value, _ := strconv.Atoi(parts[1])
			// index := v.IndexOf(value)
			// fmt.Println(index)
		case "contains":
			// value, _ := strconv.Atoi(parts[1])
			// if v.Contains(value) {
			// 	fmt.Println("true")
			// } else {
			// 	fmt.Println("false")
			// }
		case "clear":
			// v.Clear()
		case "capacity":
			// fmt.Println(v.Capacity())
		case "get":
			// index, _ := strconv.Atoi(parts[1])
			// value, err := v.At(index)
			// if err != nil {
			// 	fmt.Println(err)
			// } else {
			// 	fmt.Println(value)
			// }
		case "set":
			// index, _ := strconv.Atoi(parts[1])
			// value, _ := strconv.Atoi(parts[2])
			// err := v.Set(index, value)
			// if err != nil {
			// 	fmt.Println(err)
			// }
			// 
		case "reserve":
			// newCapacity, _ := strconv.Atoi(parts[1])
			// v.Reserve(newCapacity)
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
