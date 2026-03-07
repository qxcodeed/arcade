# Lista simples 1

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Diagrama de Implementação](#diagrama-de-implementação) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/lista_simples/cover.jpg)

## Intro

- Vamos implementar uma lista duplamente encadeada com nó sentinela (nó de marcação). Esse modelo de implementação é o mais comum em linguagens como C/C++, Java, Go, Rust, etc.
- A excessão é o python, que tem uma implementação diferente, ao invés de usar nós que unem elementos individuais, ele faz nós que unem listas inteiras. Isso é mais eficiente, mas não é o que vamos fazer aqui.

## Guide

Nessa lista, teremos um único `Node` chamado `root` que marca tanto o início como o fim da lista. Esse nó não contém dados, apenas aponta para o primeiro e o último nó da lista.

- root.next representa o primeiro nó valido da lista.
- root.prev representa o último nó da lista.

Como queremos implementar algo que se aproxime do uso real, também vamos utilizar a classe `Node` como Iterador para a lista, permitindo percorrer a lista de forma mais simples. Seja o seguinte código um exemplo de uso do resultado final da implementação:

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

### 📌 **Funções a implementar (na ordem dos testes):**

#### ✅ Básicas

- **`init`** – inicializa a lista (vazia).
- **`size`** – retorna o tamanho da lista.
- **`clear`** – esvazia a lista.
- **`push_front <valores>`** – insere valores no início da lista (último valor aparece primeiro).
- **`push_back <valores>`** – insere valores no final da lista.

#### ✅ Remoção

- **`pop_front`** – remove o primeiro elemento da lista (se existir).
- **`pop_back`** – remove o último elemento da lista (se existir).

#### ✅ Acesso

- **`show`** – mostra a lista atual (no formato `[1, 2, 3]`).
- **`front`** – retorna o primeiro nó da lista ou nulo.
- **`back`** – retorna o último nó da lista ou nulo.

#### ✅ Operações com Node

- **`search`** - retorna o Node que contém o elemento ou Null.
- **`insert`** - insere um novo Node com valor antes da posição desse nó.
- **`remove`** - remove o nó e retorna o nó que ficou no lugar dele. Se era o útlimo, retorna Null.

## Shell

```bash

#TEST_CASE init e empty show
$show
[]
$end

```

```bash
#TEST_CASE push_front <value ...>
$push_front 1 2 3 4
$show
[4, 3, 2, 1]
$push_front 9 6
$show
[6, 9, 4, 3, 2, 1]
$end
```

```bash
#TEST_CASE size
$size
0
$push_front 4
$show
[4]
$size
1
$push_front 3 2 1
$show
[1, 2, 3, 4]
$size
4
$end
```

```bash
#TEST_CASE clear
$push_front 1 2 3 4
$show
[4, 3, 2, 1]
$clear
$show
[]
$clear
$show
[]
$push_front 1 2 3 4
$show
[4, 3, 2, 1]
$end
```

```bash
#TEST_CASE push_back <value ...>
$push_back 1 2 3 4
$show
[1, 2, 3, 4]
$push_back 1 2 3 4
$show
[1, 2, 3, 4, 1, 2, 3, 4]
$push_front 0 3
$show
[3, 0, 1, 2, 3, 4, 1, 2, 3, 4]
$end
```

```bash
#TEST_CASE pop_front
$push_back 1 3 4 5
$show
[1, 3, 4, 5]
$pop_front
$show
[3, 4, 5]
$pop_front
$show
[4, 5]
$pop_front
$show
[5]
$pop_front
$show
[]
$pop_front
$show
[]
$end
```

```bash
#TEST_CASE pop_back
$push_back 1 3 4 5
$show
[1, 3, 4, 5]
$pop_back
$show
[1, 3, 4]
$pop_back
$show
[1, 3]
$pop_back
$show
[1]
$pop_back
$show
[]
$pop_back
$show
[]
$end
```

Percorrendo a lista usando front e back

```bash
#TEST_CASE walking
$push_back 1 2 3 4 5 6
$walk
[1, 2, 3, 4, 5, 6]
[6, 5, 4, 3, 2, 1]
$clear
$walk
[]
[]
```

Para executar a inserção e remoção de nós, vamos usar o comando `search` para encontrar o nó que queremos manipular.
E depois usar o comando `replace`, `insert` ou `remove` para fazer a operação desejada.

```bash
#TEST_CASE search and replace
# replace <value_to_search> <value_to_replace>
$push_back 1 2 3 4 5
$replace 3 9
$show
[1, 2, 9, 4, 5]
$replace 1 8
$show
[8, 2, 9, 4, 5]
$replace 5 7
$show
fail: not found
```

```bash
#TEST_CASE search and insert
# insert <value_to_search> <value_to_insert_before>
$push_back 1 2 3 4 5
$show
[1, 2, 3, 4, 5]
$insert 3 9
$show
[1, 2, 9, 3, 4, 5]
$insert 1 8
$show
[8, 1, 2, 9, 3, 4, 5]
$insert 5 7
$show
[8, 1, 2, 9, 3, 4, 7, 5]
$insert 6 7
$show
[8, 1, 2, 9, 3, 4, 7, 6, 5]
$insert 1 7
$show
[8, 7, 1, 2, 9, 3, 4, 7, 6, 5]
$insert 10 7
fail: not found
$show
[8, 7, 1, 2, 9, 3, 4, 7, 6, 5]
```

```bash
#TEST_CASE search and remove
# remove <value_to_search>
$push_back 1 2 3 4 5
$show
[1, 2, 3, 4, 5]
$remove 3
$show
[1, 2, 4, 5]
$remove 1
$show
[2, 4, 5]
$remove 7
fail: not found
$show
[2, 4, 5]

------------------------------------------   LISTA DUPLA 2 ----------------------------------------------------------

```bash
#TEST_CASE erase <value>
$push_back 1 2 3 4 7 6 8 5
$show
[1, 2, 3, 4, 7, 6, 8, 5]
$erase 4
$show
[1, 2, 3, 7, 6, 8, 5]
$erase 5
$show
[1, 2, 3, 7, 6, 8]
$erase 1
$show
[2, 3, 7, 6, 8]
$erase 5
$show
[2, 3, 7, 6]
```

```bash
#TEST_CASE erase_all
$push_back 4 4 1 2 3 4 4 4 7 6 8 5 4 4
$show
[4, 4, 1, 2, 3, 4, 4, 4, 7, 6, 8, 5, 4, 4]
$erase_all 4
$show
[1, 2, 3, 7, 6, 8, 5]
$erase_all 1
$show
[2, 3, 7, 6, 8, 5]
```

```bash
#TEST_CASE index_of the first occurrence
$push_back 1 2 3 4 5 9 8 7 6 5
$show
[1, 2, 3, 4, 5, 9, 8, 7, 6, 5]
$index_of 5
4
$index_of 1
0
$index_of 9
5
```

```bash
#TEST_CASE equals_i 
$push_back
$equals [ ]
true
$push_back 1
$equals [ 1 ]
true
$clear
$push_back 1 2 3 4 5
$equals [ 1 2 3 4 5 ]
true
$clear
$push_back 1
$equals [ 1 2 ]
false
```

```bash
#TEST_CASE equals_ii
$push_back 1
$equals [ 1 2 ]
false
$clear
$push_back 1 2 3
$equals [ 1 2 ]
false
$clear
$push_back 1 2 3
$equals [ 1 3 2 ]
false
$clear
```

```bash
#TEST_CASE clone
$push_back 1 2 3 4 5
$clone
this  -> [1, 2, 3, 4, 5]
clone -> [1, 2, 3, 4, 5]
clone sucess
```

```bash
#TEST_CASE iterator
$push_back 1 2 3 4 5
$iter
[ 1 2 3 4 5 ]
$rev_iter
[ 5 4 3 2 1 ]
$cyclic 14
[ 1 2 3 4 5 1 2 3 4 5 1 2 3 5 ]
```
