# Java Set

```ts
class Set {
  - data: int[]                            ' Armazena os elementos da lista ordenada
  - size: int                              ' Número atual de elementos na lista
  - capacity: int                          ' Capacidade alocada da lista (tamanho de data)
  --
  + Set(): Set                             ' Construtor: cria nova lista com capacidade inicial padrão
  - reserve(newCapacity: int): void        ' Redimensiona a capacidade da lista se necessário (interno)
  - binarySearch(value: int): int          ' Busca binária: retorna índice ou -1 se não encontrado
  - insertAt(value: int, index: int): void ' Insere value na posição indicada, deslocando à direita
  - eraseAt(index: int): void              ' Remove o valor na posição indicada, deslocando os demais
  --
  + insert(value: int): boolean            ' Insere valor mantendo ordem e sem duplicatas
  + contains(value: int): boolean          ' Retorna true se o valor existir na lista
  + erase(value: int): boolean             ' Remove valor se existir e retorna true, senão false
  + toString(): String                     ' Representação em string dos elementos da lista
}
```
