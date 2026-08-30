# Go

Na atividade seguinte a essa, a @lista_d2, vamos implementar um modelo de iteradores para deixar nossa lista mais usável, mas por enquanto, o resultado final dessa estrutura de dados deve ser algo parecido com isso:

```go
var ll LList = NewLList()  // inicializa a lista, criando o root, e fazendo ele apontar para ele mesmo

// Adicionando valores na lista
for i := range 10 {
    ll.PushBack(i)
}

// Iterando sobre a lista
node := ll.root.next; // começa do primeiro nó valido
for node != ll.root { // enquanto não chegar no nó sentinela
    fmt.Println(node.Value)
    node = node.next
}

// Não se preocupe, vamos melhorar a legibilidade disso na próxima atividade
```

## Diagrama de Implementação

```go
class Node {
    Value int            // Valor é público
    next *Node           // o próximo nó da lista
    prev *Node           // o nó anterior
}

class LList {
    root * Node          // Nó sentinela que marca o começo e o fim da lista
    Size()               // retorna o tamanho da lista
    Clear()              // apaga todos os nós da lista
    PushFront(value int) // adiciona um novo nó com esse valor no início da lista
    PushBack(value int)  // adiciona um novo nó com esse valor no fim da lista
    PopFront()           // remove o primeiro valor da lista se existir
    PopBack()            // remove o último valor da lista se existir
    String()             // retorna a string da lista no formato [1, 2, 3]
}
```
