# Python

```ts
class Vector {
  - __data: list[int]                          ' Armazena os elementos da estrutura
  - __size: int                                ' Número de elementos atualmente armazenados
  - __capacity: int                            ' Capacidade total do vetor antes de realocar
  --
  + __init__(capacity: int): None              ' Inicializa o vetor com capacidade inicial
  + push_back(value: int): None                ' Adiciona um valor ao final da lista
  + pop_back(): None                           ' Remove o último elemento
  + insert(index: int, value: int): None       ' Insere um valor em uma posição específica
  + erase(index: int): None                    ' Remove o elemento da posição indicada
  + index_of(value: int): int                  ' Retorna o índice do valor ou -1
  + contains(value: int): bool                 ' Verifica se um valor está presente
  + reserve(new_capacity: int): None           ' Aumenta a capacidade do vetor
  + size(): int                                ' Retorna o tamanho atual do vetor
  + capacity(): int                            ' Retorna a capacidade atual do vetor
  + status(): str                              ' Retorna uma string com tamanho e capacidade
  + __str__(): str                             ' Representação em string dos elementos
  + get(index: int): int                       ' Acesso direto ao índice (sem verificação)
  + at(index: int): int                        ' Acesso ao índice com verificação de limites
  + set(index: int, value: int): None          ' Altera o valor no índice especificado
  + clear(): None                              ' Remove todos os elementos do vetor
  + reverse(): None                            ' Inverte a ordem dos elementos
  + sort(): None                               ' Ordena os elementos da lista
  + sorted(): Vector                           ' Retorna uma nova lista ordenada
}

```
