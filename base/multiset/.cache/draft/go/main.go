package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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
	// ms := NewMultiSet(0)

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
			// ms = NewMultiSet(value)
		case "magic":
			// value, _ := strconv.Atoi(parts[1])
			// fmt.Println(ms.MagicSearch(value))
		case "insert":
			// for _, part := range parts[1:] {
			// 	value, _ := strconv.Atoi(part)
			// 	ms.Insert(value)
			// }
		case "show":
			// fmt.Println(ms)
		case "erase":
			// value, _ := strconv.Atoi(parts[1])
			// err := ms.Erase(value)
			// if err != nil {
			// 	fmt.Println(err)
			// }
		case "contains":
			// value, _ := strconv.Atoi(parts[1])
			// fmt.Println(ms.Contains(value))
		case "count":
			// value, _ := strconv.Atoi(parts[1])
			// fmt.Println(ms.Count(value))
		case "unique":
			// fmt.Println(ms.Unique())
		case "clear":
			// ms.Clear()
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
