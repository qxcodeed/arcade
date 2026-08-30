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

func rec_sum(node *Node) int {
	// @UNC
	// _ = node
	// return 0
	// @DROP
	if node == nil {
		return 0
	}
	return node.Value + rec_sum(node.Left) + rec_sum(node.Right)
}

func rec_min(node *Node) int {
	// @UNC
	// _ = node
	// return 0
	// @DROP
	if node.Left == nil && node.Right == nil {
		return node.Value
	}
	min := node.Value
	if node.Left != nil {
		leftMin := rec_min(node.Left)
		if leftMin < min {
			min = leftMin
		}
	}
	if node.Right != nil {
		rightMin := rec_min(node.Right)
		if rightMin < min {
			min = rightMin
		}
	}
	return min
}

// MyShow imprime a árvore binária de forma formatada.
func MyShow(node *Node, nivel int) {
	_, _ = node, nivel
	// TODO
	// @DROP
	if node == nil {
		fmt.Println(strings.Repeat(".", nivel*4) + "#")
		return
	}
	if node.Left != nil || node.Right != nil {
		MyShow(node.Left, nivel+1)
	}
	fmt.Println(strings.Repeat(".", nivel*4) + fmt.Sprint(node.Value))
	if node.Left != nil || node.Right != nil {
		MyShow(node.Right, nivel+1)
	}
}

// @KEEP
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
	root := create(&parts)
	fmt.Println("Arvore:")
	BShow(root, "")
	fmt.Printf("Soma: %d, Minimo: %d\n", rec_sum(root), rec_min(root))
}
