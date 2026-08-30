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

// retorne o caminho até o nó ou ! se não existir
// você pode fazer recursivo ou interativo
// também pode criar funções auxiliares se achar necessário
func findPath(node *Node, value int) string {
	// TODO
	// ACT
	// _, _ = node, value
	// return ""
	// @DROP
	if node == nil {
		return "!"
	}
	if node.Value == value {
		return "x"
	}
	left := findPath(node.Left, value)
	if len(left) > 0 && left[len(left)-1] == 'x' {
		return "l" + left
	}
	right := findPath(node.Right, value)
	if len(right) > 0 && right[len(right)-1] == 'x' {
		return "r" + right
	}
	return "!"
}

// @DROP
func findPath2(node *Node, history string, value int) string {
	if node == nil {
		return "!"
	}
	if node.Value == value {
		return history + "x"
	}
	if left := findPath2(node.Left, history+"l", value); left != "!" {
		return left
	}
	return findPath2(node.Right, history+"r", value)
}

func findPathInteractive(node *Node, value int) string {
	slice := []*Node{}
	slice = append(slice, node)
	path := map[*Node]string{node: ""}
	for len(slice) > 0 {
		current := slice[0]
		slice = slice[1:]
		if current.Value == value {
			return path[current] + "x"
		}
		delete(path, current)
		if current.Left != nil {
			slice = append(slice, current.Left)
			path[current.Left] = path[current] + "l"
		}
		if current.Right != nil {
			slice = append(slice, current.Right)
			path[current.Right] = path[current] + "r"
		}
	}
	return "!"
}

func findPathInteractive2(node *Node, value int) string {
	slice := []*Node{node}
	history := []string{""}
	for len(slice) > 0 {
		current := slice[0]
		currentHistory := history[0]
		slice = slice[1:]
		history = history[1:]
		if current.Value == value {
			return currentHistory + "x"
		}
		if current.Left != nil {
			slice = append(slice, current.Left)
			history = append(history, currentHistory+"l")
		}
		if current.Right != nil {
			slice = append(slice, current.Right)
			history = append(history, currentHistory+"r")
		}
	}
	return "!"
}

// @KEEP
// ----------------------------------------------------------------------------------
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
	scanner.Scan()
	value, _ := strconv.Atoi(scanner.Text())
	root := create(&parts)
	fmt.Println("Arvore:")
	BShow(root, "") // Chama a função de impressão formatada
	fmt.Println("Caminho:", findPath(root, value))
}
