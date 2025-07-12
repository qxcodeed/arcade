package main

import (
	"fmt"
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

func find(node **Node, value int) **Node {
	if *node == nil {
		return nil
	}
	if (*node).Value == value {
		return node
	}
	if value > (*node).Value {
		return find(&(*node).Right, value)
	}
	return find(&(*node).Left, value)
}

func remover(root **Node, value int) {
	link := find(root, value)
	node := *link
	if node.Left == nil && node.Right == nil {
		*link = nil
	}
	if node.Left != nil && node.Right == nil {
		*link = node.Left
	}
	if node.Left == nil && node.Right != nil {
		*link = node.Right
	}
	escolhido := node.Left
	for escolhido.Right != nil {
		escolhido = escolhido.Right
	}
	remover(root, escolhido.Value)
	node.Value = escolhido.Value
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
	node := &Node{Value: 5}
	find(&node, 7)
}
