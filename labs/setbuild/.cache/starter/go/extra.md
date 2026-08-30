# Vector

```ts
class Set {
  - data: []int                             ' Guarda os elementos da lista ordenada
  - size: int                               ' Número atual de elementos na lista
  - capacity: int                           ' Capacidade alocada da lista (tamanho de data)
  --
  + NewSet(): *Set                          ' Cria uma nova lista ordenada com capacidade inicial padrão
  - reserve(newCapacity: int): void         ' Redimensiona a capacidade da lista se necessário (interno)
  - binarySearch(value: int): int           ' Realiza busca binária e retorna o índice do valor, ou -1 se não for encontrado
  - insert(value: int, index: int): error   ' Insere value no índice indicado, deslocando os elementos à direita
  - erase(index: int): error                ' Remove o elemento na posição index, deslocando os demais
  --
  + Insert(value: int): void                ' Insere um valor na posição correta da lista, mantendo a ordem e sem duplicatas
  + Contains(value: int): bool              ' Retorna true se o valor existir na lista, false caso contrário
  + Erase(value: int): bool                 ' Remove o valor da lista, se existir, e retorna true. Retorna false se não for encontrado
  + String(): string                        ' Retorna uma representação em string dos elementos da lista
}
```
