# extra

Com a implementação do Nó como interador, os seguintes códigos podem ser escritos, permitindo navegar e manipular a estrutura sem precisar lidar com a implementação interna dela.

```go
var llist LList = NewLList()

// Adicionando valores na lista
for i := range 10 {
    llist.PushBack(i)
}

// Iterando sobre a lista
for node := llist.Front(); node != nil; node = node.Next() {
    fmt.Println(node.Value)
}

// Iterando de trás pra frente
for node := llist.Back(); node != nil; node = node.Prev() {
    fmt.Println(node.Value)
}

// Busca de um nó
node := llist.Search(3)
if node != nil {
    fmt.Println("Encontrado:", node.Value)
} else {
    fmt.Println("Não encontrado")
}

// Removendo todos os nós impares
for node := llist.Front(); node != nil; { // começa do primeiro nó
    if node.Value%2 == 1 {                // se o valor for impar
        node = llist.remove(node)         // remove o nó e retorna o próximo nó
    } else {                              // se o valor for par
        node = node.Next()                // apenas avança para o próximo nó
    }
}

```

## Diagrama de Implementação

```go
class Node {
    Value int    // Valor é público
    next *Node   // o próximo nó da lista
    prev *Node   // o nó anterior

    root *Node   // aponta para o nó sentinela da lista da qual ele faz parte
    Next() *Node // retorna o próximo nó ou nulo, se o próximo é o root
    Prev() *Node // retorna o nó anterior ou nulo, se o anterior é o root
}

class LList {
    root * Node                   // Nó sentinela que marca o começo e o fim da lista
    size int                      // tamanho da lista
    Size()                        // retorna o tamanho da lista
    Clear()                       // apaga todos os nós da lista
    PushFront(value int)          // adiciona um novo nó com esse valor no início da lista
    PushBack(value int)           // adiciona um novo nó com esse valor no fim da lista
    PopFront()                    // remove o primeiro valor da lista se existir
    PopBack()                     // remove o último valor da lista se existir
    Front() *Node                 // retorna o primeiro nó válido da lista ou nulo
    Back() *Node                  // retorna o último nó válido da lista ou nulo
    Search(value int) *Node       // retorna o nó que contém a primeira ocorrência desse valor ou nulo
    Insert(node *Node, value int) // insere um novo nó antes do nó passado por referência
    Remove(node *Node) *Node      // remove o nó passado por referência retornando o nó que ficou no lugar dele
}
```
