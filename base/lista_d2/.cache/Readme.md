# Lista Dupla com Nó Iterador

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

## Intro

Todas as linguagens implementam algum modelo de abstração para facilitar o percorrimentos das diversas estruturas de dados implementadas. Alguns utilizam o modelo de for range, que permite percorrer qualquer coleção de dados, como listas, dicionários, etc. Esse modelo é mais simples e fácil de usar, mas não é tão flexível quanto o modelo de iterador, por não permitir escolher o ponto de partida e o ponto de parada do loop.

Exemplos de for range:

```java
// Java
for (int i : list) {
    System.out.println(i);
}
```

```python
# Python
for i in list:
    print(i)
```

```c++
// C++
for (int i : list) {
    cout << i << endl;
}
```

Também existe o modelo de iterador:

```java
// Java
var it = list.iterator();
while (it.hasNext()) {
    System.out.println(it.next());
}
```

```c++
// C++
for (auto it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << std::endl;
}
```

```go
// Go
lista := list.New()
for e := lista.Front(); e != nil; e = e.Next() {
    fmt.Println(e.Value)
}
```

## Guide

Vamos partir do código da atividade anterior, a @lista_d1, e implementar um modelo de iterador para deixar nossa lista mais usável. O resultado final dessa estrutura de dados deve ser algo parecido o código de percorrimento para Go usando o modelo de iterador.

- Para isso, vamos mudar a estrutura do Nó para que ele se comporte como iterador.

```ts
class Node {
    - value: int        // Valor é público
    - next: *Node       // o próximo nó da lista
    - prev: *Node       // o nó anterior
    - root: *Node       // aponta para o nó sentinela da lista da qual ele faz parte
    + Next(): *Node     // retorna o próximo nó ou nulo, se o próximo é o root
    + Prev(): *Node     // retorna o nó anterior ou nulo, se o anterior é o root
}    

class LList {
    - root: * Node                  // Nó sentinela que marca o começo e o fim da lista
    - size: int                     // tamanho da lista
    + Size()                        // retorna o tamanho da lista
    + Clear()                       // apaga todos os nós da lista
    + PushFront(value int)          // adiciona um novo nó com esse valor no início da lista
    + PushBack(value int)           // adiciona um novo nó com esse valor no fim da lista
    + PopFront()                    // remove o primeiro valor da lista se existir
    + PopBack()                     // remove o último valor da lista se existir
    // novos métodos
    + Front(): *Node                 // retorna o primeiro nó válido da lista ou nulo
    + Back(): *Node                  // retorna o último nó válido da lista ou nulo
    + Search(value int): *Node       // retorna o nó que contém a primeira ocorrência desse valor ou nulo
    + Insert(node *Node, value int)  // insere um novo nó antes do nó passado por referência
    + Remove(node *Node): *Node      // remove o nó passado por referência retornando o nó que ficou no lugar dele ou nulo
                                     // caso o nó não exista ou o próximo seja o último
}
```

Perceba que implementando assim, escondemos o root para quem utiliza a lista, dando a impressão que os limites dela apontam para nulo.

## Shell

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

Percorrendo a lista usando front e back até o fim

```bash
#TEST_CASE walking
$push_back 1 2 3 4 5 6
$walk
[ 1 2 3 4 5 6 ]
[ 6 5 4 3 2 1 ]
$clear
$walk
[ ]
[ ]
$end
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
$replace 3 7
fail: not found
$show
[8, 2, 9, 4, 5]
$end
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
$insert 7 6
$show
[8, 1, 2, 9, 3, 4, 6, 7, 5]
$insert 1 7
$show
[8, 7, 1, 2, 9, 3, 4, 6, 7, 5]
$insert 10 7
fail: not found
$show
[8, 7, 1, 2, 9, 3, 4, 6, 7, 5]
$end
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
$end
```
