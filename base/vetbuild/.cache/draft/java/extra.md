# Java

```ts
class Vector {
  - data: int[]                             // Guarda os elementos do vetor
  - size: int                               // Guarda o número atual de elementos
  - capacity: int                           // Guarda a capacidade atual do vetor
  --
  + Vector(capacity: int)                   // Cria um novo vetor com a capacidade inicial especificada
  + reserve(newCapacity: int): void         // Redimensiona a capacidade do vetor para pelo menos o valor especificado
  + pushBack(value: int): void              // Adiciona um valor ao final do vetor, redimensionando se necessário
  + size(): int                             // Retorna o número atual de elementos no vetor
  --
  + popBack(): int throws Exception         // Remove e retorna o último elemento do vetor.
                                            // Retorna um erro se o vetor estiver vazio
  + capacity(): int                         // Retorna a capacidade atual do vetor
  + status(): String                        // Retorna o tamanho e a capacidade do vetor
  + toString(): String                      // Retorna uma representação em string dos elementos do vetor
  --
  + get(index: int): int                    // Retorna o elemento no índice especificado sem verificação de limites
  + at(index: int): int throws Exception    // Retorna o elemento no índice especificado com verificação de limites.
                                            // Retorna um erro se o índice estiver fora dos limites
  + set(index: int, value: int): void throws Exception
                                            // Define o valor no índice especificado.
                                            // Retorna um erro se o índice estiver fora dos limites
  + clear(): void                           // Limpa todos os elementos do vetor
  --
  + insert(index: int, value: int): void throws Exception
                                            // Insere um valor no índice especificado, deslocando os elementos conforme necessário.
                                            // Retorna um erro se o índice estiver fora dos limites
  + erase(index: int): void throws Exception
                                            // Remove o elemento no índice especificado, deslocando os elementos conforme necessário.
                                            // Retorna um erro se o índice estiver fora dos limites
  --
  + indexOf(value: int): int                // Retorna o índice da primeira ocorrência do valor especificado, ou -1 se não for encontrado
  + contains(value: int): boolean           // Verifica se o valor especificado existe no vetor
}
```
