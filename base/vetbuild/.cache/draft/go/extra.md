# Vector

```ts
class Vector {
  - data: []int                             ' Guarda os elementos do vetor
  - size: int                               ' Guarda o número atual de elementos
  - capacity: int                           ' Guarda a capacidade atual do vetor
  --
  + NewVector(capacity: int): *Vector       ' Cria um novo vetor com a capacidade inicial especificada
  + Reserve(newCapacity: int): void         ' Redimensiona a capacidade do vetor para pelo menos o valor especificado
  + PushBack(value: int): void              ' Adiciona um valor ao final do vetor, redimensionando se necessário
  + Size(): int                             ' Retorna o número atual de elementos no vetor
  --
  + PopBack(): (int, error)                 ' Remove e retorna o último elemento do vetor. Retorna um erro se o vetor estiver vazio
  + Capacity(): int                         ' Retorna a capacidade atual do vetor
  + Status(): string                        ' Retorna o tamanho e a capacidade do vetor
  + String(): string                        ' Retorna uma representação em string dos elementos do vetor
  --
  + Get(index: int): int                    ' Retorna o elemento no índice especificado sem verificação de limites
  + At(index: int): (int, error)            ' Retorna o elemento no índice especificado com verificação de limites.
                                            ' Retorna um erro se o índice estiver fora dos limites
  + Set(index: int, value: int): error      ' Define o valor no índice especificado.
                                            ' Retorna um erro se o índice estiver fora dos limites
  + Clear(): void                           ' Limpa todos os elementos do vetor
  --
  + Insert(index: int, value: int): error   ' Insere um valor no índice especificado, deslocando os elementos conforme necessário.
                                            ' Retorna um erro se o índice estiver fora dos limites
  + Erase(index: int): error                ' Remove o elemento no índice especificado, deslocando os elementos conforme necessário.
                                            ' Retorna um erro se o índice estiver fora dos limites
  --
  + IndexOf(value: int): int                ' Retorna o índice da primeira ocorrência do valor especificado, ou -1 se não for encontrado
  + Contains(value: int): bool              ' Verifica se o valor especificado existe no vetor
}
```
