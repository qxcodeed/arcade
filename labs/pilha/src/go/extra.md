# Orientações de Implementação

```go
type Stack[T any] struct {   // Uma pilha genérica que pode armazenar qualquer tipo de dado.
    data []T                 // Os dados são armazenados em um slice, a capacidade do slice é a capacidade da pilha.
    Push(value T)            // Adiciona um valor ao topo da pilha utilizando append.
    Pop() error              // Remove o valor do topo da pilha.
    Peek() (T, error)        // Retorna o valor do topo da pilha sem removê-lo.
    IsEmpty() bool           // Retorna true se a pilha estiver vazia.
    Size() int               // Retorna o número de elementos na pilha. Isso equivale ao tamanho do slice.
    Clear()                  // Limpa a pilha, removendo todos os elementos.
    String() string          // Retorna uma representação em string dos elementos da pilha para efeitos de debug.
}

func NewStack[T any](cap int) *Stack[T]  // Cria uma nova pilha com a capacidade inicial especificada
```

Para remover o último elemento ou zerar o slice, você pode usar as operações de slice do Go, como `s = s[:len(s)-1]` para remover o último elemento ou `s = s[:0]` para zerar o slice. O operador de fatiamento mantém a capacidade original do bloco alocado, ele apenas manipula o tamanho do slice, o que é eficiente em termos de memória.
