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
			// value, _ := strconv.Atoi(parts[1])
			// v = NewSet(value)
		case "insert":
			// for _, part := range parts[1:] {
			// 	value, _ := strconv.Atoi(part)
			// }
		case "show":
		case "erase":
			// value, _ := strconv.Atoi(parts[1])
		case "contains":
			// value, _ := strconv.Atoi(parts[1])
		case "clear":
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
