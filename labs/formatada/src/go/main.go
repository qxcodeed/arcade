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
// -----------------------------------------------------------------------------------
// @KEEP
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
	root := create(&parts)
	BShow(root, "") // Chama a função de impressão formatada
	MyShow(root, 0) // Chama a função de impressão personalizada
}
