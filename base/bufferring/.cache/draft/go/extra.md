# Go

Nesta atividade, implementamos um **buffer circular com redimensionamento automático**. A estrutura se comporta como uma fila circular, permitindo inserções no início ou no fim e remoções em ambos os lados, mantendo os elementos em um vetor fixo que cresce conforme necessário.

## Diagrama de Implementação

```go
class Deque {
    data []int           // vetor que guarda os elementos
    front int            // índice do início
    size, capacity int   // tamanho atual e capacidade total
    resize(newCap int)   // dobra o tamanho do caso ele chege no máximo de sua capacidade
    PushBack(v int)      // insere valor no fim
    PushFront(v int)     // insere valor no início
    PopBack()            // remove valor do fim
    PopFront()           // remove valor do início
    Front() (int, error) // retorna o valor do início
    Back() (int, error)  // retorna o valor do fim
    Clear()              // limpa todos os elementos
    Len() int            // retorna o número de elementos
    String() string      // representação no formato [1, 2, 3]
}
```
