# Vetor

```ts
class Vector {
    - data: int*                              ' Guarda os elementos do vetor
    - size: int                               ' Guarda o número atual de elementos
    - capacity: int                           ' Guarda a capacidade atual do vetor
    __
    + Vector(capacity: int)                   ' Cria um novo vetor com a capacidade inicial especificada
    + reserve(newCapacity: int): void         ' Redimensiona a capacidade do vetor para pelo menos o valor especificado
    + pushBack(value: int): void              ' Adiciona um valor ao final do vetor, redimensionando se necessário
    + getSize(): int                          ' Retorna o número atual de elementos no vetor
    __
    + popBack(): bool                         ' Remove o último elemento do vetor. Retorna false se o vetor estiver vazio
    + getCapacity(): int                      ' Retorna a capacidade atual do vetor
    + status(): string                        ' Retorna o tamanho e a capacidade do vetor
    + str(): string                           ' Retorna uma representação em string dos elementos do vetor
    __
    + get(index: int): int                    ' Retorna o elemento no índice especificado sem verificação de limites
    + at(index: int): pair<int, bool>         ' Retorna o elemento no índice especificado com verificação de limites.
                                              ' Retorna false se o índice estiver fora dos limites
    + set(index: int, value: int): bool       ' Define o valor no índice especificado.
                                              ' Retorna false se o índice estiver fora dos limites
    + clear(): void                           ' Limpa todos os elementos do vetor
    __
    + insert(index: int, value: int): bool    ' Insere um valor no índice especificado, deslocando os elementos conforme necessário.
                                              ' Retorna false se o índice estiver fora dos limites
    + erase(index: int): bool                 ' Remove o elemento no índice especificado, deslocando os elementos conforme necessário.
                                              ' Retorna false se o índice estiver fora dos limites
    + indexOf(value: int): int                ' Retorna o índice da primeira ocorrência do valor especificado, ou -1 se não for encontrado
    + contains(value: int): bool              ' Verifica se o valor especificado existe no vetor
    + reverse(): void                         ' Inverte a ordem dos elementos no vetor
    + sort(): void                            ' Ordena os elementos do vetor em ordem crescente
    + sorted(): vector<int>                   ' Retorna uma cópia ordenada dos elementos do vetor
}
```
