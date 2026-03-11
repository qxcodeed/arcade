# Java

```ts
class MyArrayList {
  - elementData: int[]                      // Guarda os elementos da lista
  - size: int                               // Número atual de elementos na lista
  - capacity: int                           // Capacidade atual do array interno
  --
  + MyArrayList(initialCapacity: int)       // Cria uma nova lista com a capacidade inicial especificada
  + ensureCapacity(minCapacity: int): void  // Garante que a capacidade seja pelo menos o valor especificado
  + add(value: int): void                   // Adiciona um valor ao final da lista, redimensionando se necessário
  + size(): int                             // Retorna o número atual de elementos na lista
  --
  + removeLast(): boolean                   // Remove e retorna o último elemento da lista.
  + getCapacity(): int                      // Retorna a capacidade atual da lista
  + getStatus(): String                     // Retorna uma string com o tamanho e a capacidade
  + toString(): String                      // Retorna uma representação em string dos elementos
  --
  + get(index: int): int                    // Retorna o elemento no índice especificado sem verificação
  + getAt(index: int): Integer              // Retorna o elemento com verificação de limites ou null caso não exista
  + set(index: int, value: int): boolean    // Define o valor no índice especificado
                                            // Define o valor no índice especificado
  + clear(): void                           // Remove todos os elementos da lista
  --
  + add(index: int, value: int): boolean    // Insere valor no índice especificado, deslocando os elementos
  + remove(index: int): boolean             // Remove o elemento no índice especificado, deslocando os elementos
  --
  + indexOf(value: int): int                // Retorna o índice da primeira ocorrência do valor, ou -1
  + contains(value: int): boolean           // Retorna se o valor está presente na lista
}
```
