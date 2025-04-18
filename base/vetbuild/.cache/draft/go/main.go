/*

Vector representa um array dinâmico que pode crescer conforme necessário.
Ele fornece métodos para manipular o array, como adicionar, remover e acessar elementos.

class Vector {
- data []int: Guarda os elementos do vetor
- size int: Guarda o número atual de elementos
- capacity int: Guarda a capacidade atual do vetor
__
+ NewVector(capacity int) *Vector: Cria um novo vetor com a capacidade inicial especificada
+ Reserve(newCapacity int): Redimensiona a capacidade do vetor para pelo menos o valor especificado
+ PushBack(value int): Adiciona um valor ao final do vetor, redimensionando se necessário
+ Size() int: Retorna o número atual de elementos no vetor
__
+ PopBack() (int, error): Remove e retorna o último elemento do vetor. Retorna um erro se o vetor estiver vazio
+ Capacity() int: Retorna a capacidade atual do vetor
+ Status() string: Retorna o tamanho e a capacidade do vetor
+ String() string: Retorna uma representação em string dos elementos do vetor
__
+ Get(index int) int: Retorna o elemento no índice especificado sem verificação de limites
+ At(index int) (int, error): Retorna o elemento no índice especificado com verificação de limites. Retorna um erro se o índice estiver fora dos limites
+ Set(index int, value int) error: Define o valor no índice especificado. Retorna um erro se o índice estiver fora dos limites
+ Clear(): Limpa todos os elementos do vetor
__
+ Insert(index int, value int) error: Insere um valor no índice especificado, deslocando os elementos conforme necessário. Retorna um erro se o índice estiver fora dos limites
+ Erase(index int) error: Remove o elemento no índice especificado, deslocando os elementos conforme necessário. Retorna um erro se o índice estiver fora dos limites
__
+ IndexOf(value int) int: Retorna o índice da primeira ocorrência do valor especificado, ou -1 se não for encontrado
+ Contains(value int) bool: Verifica se o valor especificado existe no vetor
+ Reverse() int: Inverte a ordem dos elementos no vetor
+ Sort() int: Ordena os elementos do vetor em ordem crescente
+ Sorted() []int: Retorna uma cópia ordenada dos elementos do vetor
}
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var line, cmd string
	scanner := bufio.NewScanner(os.Stdin)

	// v := NewVector(0)
	for {
		fmt.Print("$")
		if !scanner.Scan() {
			break
		}
		line = scanner.Text()
		fmt.Println(line)
		parts := strings.Fields(line)
		if len(parts) == 0 {
			continue
		}
		cmd = parts[0]

		switch cmd {
		case "end":
			return
		case "init":
			// value, _ := strconv.Atoi(parts[1])
			// v = NewVector(value)
		case "push":
			// for _, part := range parts[1:] {
			// 	value, _ := strconv.Atoi(part)
			// 	v.PushBack(value)
			// }
		case "show":
			// fmt.Println(v)
		case "status":
			// fmt.Println(v.Status())
		case "pop":
			// err := v.PopBack()
			// if err != nil {
			// 	fmt.Println(err)
			// }
		case "insert":
			// index, _ := strconv.Atoi(parts[1])
			// value, _ := strconv.Atoi(parts[2])
			// err := v.Insert(index, value)
			// if err != nil {
			// 	fmt.Println(err)
			// }
		case "erase":
			// index, _ := strconv.Atoi(parts[1])
			// err := v.Erase(index)
			// if err != nil {
			// 	fmt.Println(err)
			// }
		case "indexOf":
			// value, _ := strconv.Atoi(parts[1])
			// index := v.IndexOf(value)
			// fmt.Println(index)
		case "contains":
			// value, _ := strconv.Atoi(parts[1])
			// if v.Contains(value) {
			// 	fmt.Println("true")
			// } else {
			// 	fmt.Println("false")
			// }
		case "clear":
			// v.Clear()
		case "capacity":
			// fmt.Println(v.Capacity())
		case "get":
			// index, _ := strconv.Atoi(parts[1])
			// value, err := v.At(index)
			// if err != nil {
			// 	fmt.Println(err)
			// } else {
			// 	fmt.Println(value)
			// }
		case "set":
			// index, _ := strconv.Atoi(parts[1])
			// value, _ := strconv.Atoi(parts[2])
			// err := v.Set(index, value)
			// if err != nil {
			// 	fmt.Println(err)
			// }
			// 
		case "reserve":
			// newCapacity, _ := strconv.Atoi(parts[1])
			// v.Reserve(newCapacity)
		case "sort":
			// v.Sort()
		case "sorted":
			// fmt.Println("[" + Join(v.Sorted(), ", ") + "]")
		case "reverse":
			// v.Reverse()
		default:
			fmt.Println("fail: comando invalido")
		}
	}
}
