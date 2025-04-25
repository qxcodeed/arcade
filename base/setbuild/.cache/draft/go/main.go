package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var line, cmd string
	scanner := bufio.NewScanner(os.Stdin)

	// v := NewSet(0)
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
			// v = NewSet(value)
		case "insert":
			// for _, part := range parts[1:] {
			// 	value, _ := strconv.Atoi(part)
			// 	v.Insert(value)
			// }
		case "show":
			// fmt.Println(v)
		case "erase":
			// value, _ := strconv.Atoi(parts[1])
			// err := v.Erase(value)
			// if err != nil {
			// 	fmt.Println(err)
			// }
		case "contains":
			// value, _ := strconv.Atoi(parts[1])
			// if v.Contains(value) {
			// 	fmt.Println("true")
			// } else {
			// 	fmt.Println("false")
			// }
		case "clear":
			// v.Clear()
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
