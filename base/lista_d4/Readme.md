# Lista Circular utilizando Template

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

## Intro

Vamos implementar uma lista circular utilizando template. A ideia é que a lista seja genérica e possa armazenar qualquer tipo de dado. Além disso, o nó deve ser um iterador, permitindo percorrer a lista de forma simples e intuitiva de forma infinita, já que a lista é circular.

## Guide

Vamos partir do código da atividade anterior, a @lista_d2. A classe `LList` não vai sofrer nenhuma alteração, apenas os métodos `Next` e `Prev` do nó vão ser alterados para que eles retornem o próximo nó da lista circular.

```ts
class Node[T comparable] {
    - value: T        // Valor é público
    - next: *Node[T]       // o próximo nó da lista
    - prev: *Node[T]       // o nó anterior
    - root: *Node[T]       // aponta para o nó sentinela da lista da qual ele faz parte
    + Next(): *Node[T]     // retorna o próximo nó na lista círcular
    + Prev(): *Node[T]     // retorna o nó anterior na lista círcular
}    

class LList[T comparable] {
    - root: *Node[T]              // Nó sentinela que marca o começo e o fim da lista
    - size: int                    // tamanho da lista
    + Size()                       // retorna o tamanho da lista
    + Clear()                      // apaga todos os nós da lista
    + PushBack(value T)            // adiciona um novo nó com esse valor no fim da lista
    + Front(): *Node[T]            // retorna o primeiro nó válido da lista ou nulo
    + Back(): *Node[T]             // retorna o último nó válido da lista ou nulo
    + Search(value T): *Node[T]    // retorna o nó que contém a primeira ocorrência desse valor ou nulo
}
```

## Shell

```bash
#TEST_CASE forward
# forward <value_to_search> <steps to walk>
$push_back 1 2 3 4 5
$show
[1, 2, 3, 4, 5]
$forward 3 9
[ 3 4 5 1 2 3 4 5 1 ]
$end
```

```bash
#TEST_CASE forward
# forward <value_to_search> <steps to walk>
$push_back 1
$show
[1]
$forward 1 9
[ 1 1 1 1 1 1 1 1 1 ]
$end
```

```bash
#TEST_CASE backward
# backward <value_to_search> <steps to walk>
$push_back 1 2 3 4 5
$show
[1, 2, 3, 4, 5]
$backward 3 9
[ 3 2 1 5 4 3 2 1 5 ]
$end
```
