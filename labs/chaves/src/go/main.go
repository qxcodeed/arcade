package main

import (
	"fmt" // @DROP
)

func main() {
	// @DROP
	times := NewQueue[rune]()
	for i := range 16 {
		times.Enqueue(rune(i + 'A'))
	}
	for range 15 {
		teamA := times.Dequeue()
		teamB := times.Dequeue()
		var gols_a, gols_b int
		fmt.Scan(&gols_a, &gols_b)
		if gols_a > gols_b {
			times.Enqueue(teamA)
		} else {
			times.Enqueue(teamB)
		}
	}
	fmt.Printf("%c\n", times.Dequeue())
}
