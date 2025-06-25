package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Node: classe utilizada para representar um No
// Nao altere essa classe
type Node struct {
	Value  int    // Valuermacao salva pelo usuario na arvore
	Left  *Node  // Ponteiro para o No filho a esquerda
    Right *Node  // Ponteiro para o No filho a direita
}

// Construtores
func NewNode(Value int, Left, Right *Node) *Node {
	return &Node{Value: Value, Left: Left, Right: Right}
}

// Binary Search Tree ou
// Arvore de busca binaria
// Altere somente os campos marcados com TODO
type BSTree struct {
	Root *Node // Ponteiro para o No raiz da arvore
}

func NewBSTree(serial string) *BSTree {
	bt := &BSTree{}
	parts := strings.Fields(serial)
	index := 0
	bt.Root = bt.clone(&index, parts)
	return bt
}

func (tree *BSTree) Destructor() { // Destrutor
	tree.clear()
}

// Retorna o No da arvore que possui sua Valuermacao igual a 'Value',
// ou retorna um No vazio (NULL) caso a arvore nao possua tal 'Value'.
func (tree *BSTree) search(Value int) *Node {
	// TODO: Complexidade O(h), onde h = altura da arvore
	(void) Value;
	return nil;
}

// Adiciona um elemento na arvore.
// Esse novo elemento deve ser inserido no lugar
// de um No vazio e ao mesmo tempo respeitar as propriedades
// de uma arvore binaria de busca. 
// Value: Valuermacao do elemento a ser inserido
func (tree *BSTree) insert(Value int) {
	// TODO: Complexidade O(h), onde h = altura da arvore
	(void) Value;
	return;
}
/*
    Exemplo:

       T =   40
            /  \
           20  70
          /  \
         10  30

    T.insert(90)

       T =   40
            /  \
           20  70
          /  \   \
         10  30  90
*/

// Retorna a quantidade de elementos da arvore.
func (tree *BSTree) size() int {
	// TODO: Complexidade O(n)
	return 0;
}

// Retorna o menor elemento da arvore, ou -1 caso nao exista
func (tree *BSTree) min() int {
	// TODO: Complexidade O(h), onde h = altura da arvore
	return -1;
}

func (bt *BSTree) clone(index *int, parts []string) *Node {
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

	node := NewNode(value, nil, nil)
	node.Left = bt.clone(index, parts)
	node.Right = bt.clone(index, parts)
	return node
}

// Retorna o maior elemento da arvore, ou -1 caso nao exista
func (tree *BSTree) max() int {
	// TODO: Complexidade O(h), onde h = altura da arvore
	return -1;
}

// Deixa a lista vazia, com zero elementos
func (tree *BSTree) clear() {
	tree.Root = nil
}

// Devolve true se vazia e false caso contrario
func (tree *BSTree) empty() bool {
	return tree.Root == nil
}

// Printa as Valuermacoes da lista
func (tree *BSTree) print() {
	fmt.Print("BSTree: ")
	tree._print(tree.Root)
	fmt.Println()
}

func (tree *BSTree) _print(current *Node) {
	if current != nil {
		fmt.Printf("Node-%d{(", current.Value)
		tree._print(current.Left)
		fmt.Print(", ")
		tree._print(current.Right)
		fmt.Print(")}")
	}
}

func (bt *BSTree) show(node *Node, level int) {
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
func (bt *BSTree) Show() {
	bt.show(bt.Root, 0)
}

// bshow imprime a árvore de forma mais visual.
func (bt *BSTree) bshow() {
	bt.internalBShow(bt.Root, "")
}

// internalBShow é uma função auxiliar para bshow.
func (bt *BSTree) internalBShow(node *Node, heranca string) {
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
func (bt *BSTree) internalShowInOrder(node *Node) {
	if node == nil {
		return
	}
	bt.internalShowInOrder(node.Left)
	fmt.Printf("%d ", node.Value)
	bt.internalShowInOrder(node.Right)
}

// ShowInOrder imprime a travessia em ordem da árvore.
func (bt *BSTree) ShowInOrder() {
	fmt.Print("[ ")
	bt.internalShowInOrder(bt.Root)
	fmt.Println("]")
}



func main() {
    reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)

	bt := NewBSTree(line)
	bt.bshow()
	bt.ShowInOrder()
}
