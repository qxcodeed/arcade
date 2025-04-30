package main

import (
	"bufio"
	"fmt"
	"os"
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
			// value, _ := strconv.Atoi(args[1])
			// ms = NewMultiSet(value)
		case "magic":
			// value, _ := strconv.Atoi(args[1])
		case "insert":
			// for _, part := range args[1:] {
			// 	value, _ := strconv.Atoi(part)
			// }
		case "show":
		case "erase":
			// value, _ := strconv.Atoi(args[1])
		case "contains":
			// value, _ := strconv.Atoi(args[1])
		case "count":
			// value, _ := strconv.Atoi(args[1])
		case "unique":
		case "clear":
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
