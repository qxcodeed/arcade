# Multiset

```ts
class MultiSet {
  - data: []int                             ' Guarda os elementos do multiconjunto (ordenados, com repetições)
  - size: int                               ' Número atual de elementos no multiconjunto
  - capacity: int                           ' Capacidade alocada do vetor data
  --
  + NewMultiSet(capacity: int): *MultiSet   ' Cria um novo multiconjunto com a capacidade especificada
  - expand(): void                          ' Aumenta a capacidade do vetor quando necessário (dobrando ou iniciando)
  --
  + search(value: int): (bool, int)         ' Se o elemento value estiver presente, retorna true e o índice da última ocorrência
  --                                        ' Se não estiver, retorna false e o índice onde ele deve ser inserido
  --
  + Insert(value: int): void                ' Insere o valor na posição correta, mantendo a ordem e permitindo repetições
  - insert(value: int, index: int): error   ' Insere value no índice indicado, deslocando os elementos à direita
  --
  + Erase(value: int): error                ' Remove uma ocorrência do valor, se existir; retorna erro caso não exista
  - erase(index: int): error                ' Remove o elemento na posição index, deslocando os demais
  --
  + Contains(value: int): bool              ' Retorna true se o valor estiver presente no multiconjunto
  + Count(value: int): int                  ' Retorna o número de ocorrências do valor no multiconjunto
  + Unique(): int                           ' Retorna o número de valores distintos no multiconjunto
  + Clear(): void                           ' Remove todos os elementos do multiconjunto
  + String(): string                        ' Retorna uma representação textual dos elementos do multiconjunto
}
```
