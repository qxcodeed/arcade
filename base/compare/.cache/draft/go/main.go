package main

import (
	"bufio"
	"fmt"
	"os"

	"strconv"
	"strings"
)

type Node struct {
	Value int
	Left  *Node
	Right *Node
}

func compare(a, b *Node) int {
	if a == nil && b == nil {
		return 0
	}
	if a == nil {
		return -1
	}
	if b == nil {
		return 1
	}
	if a.Value < b.Value {
		return -1
	}
	if a.Value > b.Value {
		return 1
	}
	left := compare(a.Left, b.Left)
	if left != 0 {
		return left
	}
	return compare(a.Right, b.Right)
}

// ----------------------------------------------------------------------
func BShow(node *Node, history string) {
	if node != nil && (node.Left != nil || node.Right != nil) {
		BShow(node.Left, history+"l")
	}
	for i := 0; i < len(history)-1; i++ {
		if history[i] != history[i+1] {
			fmt.Print("│   ")
		} else {
			fmt.Print("    ")
		}
	}
	if history != "" {
		if history[len(history)-1] == 'l' {
			fmt.Print("╭───")
		} else {
			fmt.Print("╰───")
		}
	}
	if node == nil {
		fmt.Println("#")
		return
	}
	fmt.Println(node.Value)
	if node.Left != nil || node.Right != nil {
		BShow(node.Right, history+"r")
	}
}

func create(parts *[]string) *Node {
	elem := (*parts)[0]
	*parts = (*parts)[1:]
	if elem == "#" {
		return nil
	}
	value, _ := strconv.Atoi(elem)
	node := &Node{Value: value}
	node.Left = create(parts)
	node.Right = create(parts)
	return node
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	a := create(&parts)
	BShow(a, "")
	scanner.Scan()
	parts = strings.Split(scanner.Text(), " ")
	b := create(&parts)
	BShow(b, "")
	result := compare(a, b)
	if result == 0 {
		fmt.Println("iguais")
	} else if result < 0 {
		fmt.Println("menor")
	} else {
		fmt.Println("maior")
	}
}
