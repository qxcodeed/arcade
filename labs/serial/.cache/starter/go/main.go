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

// create constrói uma árvore binária a partir de uma lista de strings.
// Consuma os elementos da lista sempre do início.
// Você pode obter o primeiro elemento com 'elem := (*parts)[0]'
// Você pode fazer um "push_front" no array usando '*parts = (*parts)[1:]
// Se o elemento for "#", significa que o nó é nulo.
func create(parts *[]string) *Node {
	_ = parts
	return nil
}

// BShow é uma função auxiliar para imprimir a árvore binária.
// Primeira invocação de ser com history como uma string vazia.
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
	line := scanner.Text()
	parts := strings.Split(line, " ")
	root := create(&parts)
	BShow(root, "")
}
