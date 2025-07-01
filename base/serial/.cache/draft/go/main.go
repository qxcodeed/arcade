package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Node representa um nó na árvore binária.
type Node struct {
	Value int
	Left  *Node
	Right *Node
}

func clone(parts []string, index *int) *Node {
	return nil
}

// BShow é uma função auxiliar para bshow.
func BShow(node *Node, heranca string) {
	if node != nil && (node.Left != nil || node.Right != nil) {
		BShow(node.Left, heranca+"l")
	}

	for i := 0; i < len(heranca)-1; i++ {
		if heranca[i] != heranca[i+1] {
			fmt.Print("│   ")
		} else {
			fmt.Print("    ")
		}
	}
	if heranca != "" {
		if heranca[len(heranca)-1] == 'l' {
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
		BShow(node.Right, heranca+"r")
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	vet := strings.Fields(scanner.Text())
	index := 0
	root := clone(vet, &index)
	BShow(root, "")
}
