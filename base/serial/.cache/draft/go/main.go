package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Node representa um nó na árvore binária.
type Node struct {
	Value int
	Left  *Node
	Right *Node
}

// BTree representa a árvore binária.
type BTree struct {
	Root *Node
}

// NewNode cria um novo nó.
func NewNode(value int) *Node {
	return &Node{Value: value}
}

// NewBTree cria uma nova árvore binária a partir de uma string serializada.
func NewBTree(serial string) *BTree {
	bt := &BTree{}
	parts := strings.Fields(serial)
	index := 0
	bt.Root = bt.clone(&index, parts)
	return bt
}

// clone reconstrói a árvore a partir de uma representação serializada.
func (bt *BTree) clone(index *int, parts []string) *Node {
	if *index >= len(parts) || parts[*index] == "#" {
		*index++
		return nil
	}

	value, err := strconv.Atoi(parts[*index])
	if err != nil {
		fmt.Printf("Erro ao converter valor: %v\n", err)
		return nil
	}
	*index++

	node := NewNode(value)
	node.Left = bt.clone(index, parts)
	node.Right = bt.clone(index, parts)
	return node
}

// show imprime a árvore com indentação.
func (bt *BTree) show(node *Node, level int) {
	if node == nil {
		fmt.Printf("%s#\n", strings.Repeat(".", level))
		return
	}
	bt.show(node.Left, level+1)
	fmt.Printf("%s%d\n", strings.Repeat(".", level), node.Value)
	if node.Left == nil && node.Right == nil {
		return
	}
	bt.show(node.Right, level+1)
}

// Show chama show a partir da raiz.
func (bt *BTree) Show() {
	bt.show(bt.Root, 0)
}

// bshow imprime a árvore de forma mais visual.
func (bt *BTree) bshow() {
	bt.internalBShow(bt.Root, "")
}

// internalBShow é uma função auxiliar para bshow.
func (bt *BTree) internalBShow(node *Node, heranca string) {
	if node != nil && (node.Left != nil || node.Right != nil) {
		bt.internalBShow(node.Left, heranca+"l")
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
		bt.internalBShow(node.Right, heranca+"r")
	}
}

// internalShowInOrder é uma função auxiliar para showInOrder.
func (bt *BTree) internalShowInOrder(node *Node) {
	if node == nil {
		return
	}
	bt.internalShowInOrder(node.Left)
	fmt.Printf("%d ", node.Value)
	bt.internalShowInOrder(node.Right)
}

// ShowInOrder imprime a travessia em ordem da árvore.
func (bt *BTree) ShowInOrder() {
	fmt.Print("[ ")
	bt.internalShowInOrder(bt.Root)
	fmt.Println("]")
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)

	bt := NewBTree(line)
	bt.bshow()
	bt.ShowInOrder()
}
