package main

import (
	"container/list"
	"fmt"
)

// Função para encontrar o ponto de partida ideal
func findStartingPump(gasoline []int, distance []int, n int) int {
	queue := list.New() // Lista encadeada para simular a fila
	queue.PushBack(0)   // Começamos testando pela bomba 0

	saldoAcumulado := 0 // Mantém o saldo de gasolina acumulado
	ultimoIndice := 0   // Última bomba considerada na tentativa de completar o circuito

	for queue.Len() < n {
		ultimoIndice = queue.Back().Value.(int) // Obtém o último índice da fila
		saldoAcumulado += gasoline[ultimoIndice] - distance[ultimoIndice]

		// Se o saldo for negativo, removemos bombas da frente da fila até o saldo ser positivo
		for saldoAcumulado < 0 && queue.Len() > 0 {
			queue.Remove(queue.Front())
		}

		// Se a fila esvaziou, reiniciamos o saldo
		if queue.Len() == 0 {
			saldoAcumulado = 0
		}

		// Adicionamos a próxima bomba à fila
		queue.PushBack((ultimoIndice + 1) % n)
	}

	// O primeiro elemento da fila é o ponto de partida ideal
	return queue.Front().Value.(int)
}

func main() {
	var n int
	fmt.Scan(&n)

	gasoline := make([]int, n)
	distance := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&gasoline[i], &distance[i])
	}

	fmt.Println(findStartingPump(gasoline, distance, n))
}
