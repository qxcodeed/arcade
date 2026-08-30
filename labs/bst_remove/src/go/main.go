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

func BstInsert(values []int) *Node {
	// TODO
	// @UNC
	// _ = values
	// return nil
	// @DROP
	var root *Node
	for _, v := range values {
		root = insertBST(root, v)
	}
	return root
}

func BstRemove(node *Node, value int) *Node {
	// TODO
	// @UNC
	// _, _ = node, value
	// return nil
	// @DROP
	if node == nil {
		return nil
	}
	if value < node.Value {
		node.Left = BstRemove(node.Left, value)
	} else if value > node.Value {
		node.Right = BstRemove(node.Right, value)
	} else {
		if node.Left == nil {
			return node.Right
		} else if node.Right == nil {
			return node.Left
		}
		minNode := findSuc(node.Left)
		node.Value = minNode.Value
		node.Left = BstRemove(node.Left, minNode.Value)
	}
	return node
}

// @DROP
func findSuc(node *Node) *Node {
	if node == nil || node.Right == nil {
		return node
	}
	return findSuc(node.Right)
}

func insertBST(node *Node, value int) *Node {
	if node == nil {
		return &Node{Value: value}
	}
	if value < node.Value {
		node.Left = insertBST(node.Left, value)
	} else if value > node.Value {
		node.Right = insertBST(node.Right, value)
	}
	return node
}

// @KEEP
// -----------------------------------------------------------------------------------
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	values := make([]int, 0, len(parts))
	for _, elem := range parts {
		v, err := strconv.Atoi(elem)
		if err == nil {
			values = append(values, v)
		}
	}
	scanner.Scan()
	toRemove, _ := strconv.Atoi(scanner.Text())

	_ = toRemove // Ignora o valor a ser removido, pois não está implementado
	root := BstInsert(values)
	fmt.Println("original:")
	BShow(root, "") // Chama a função de impressão formatada
	root = BstRemove(root, toRemove)
	fmt.Println("modificado:")
	BShow(root, "") // Chama a função de impressão formatada da árvore modificada
}
