# Iteradores

```ts
class MyList {
  - data: []int                             ' Armazena os valores inteiros da lista
  --
  + NewMyList(values: []int): *MyList       ' Cria uma nova lista com os valores fornecidos
  + Iterator(): *Iterator                   ' Retorna um iterador do início ao fim
  + ReverseIterator(): *ReverseIterator     ' Retorna um iterador do fim ao início
  + CyclicIterator(): *CyclicIterator       ' Retorna um iterador circular que nunca termina
}

class Iterator {
  - data: []int                             ' Referência à lista de inteiros a ser iterada
  - index: int                              ' Índice atual do iterador
  --
  + HasNext(): bool                         ' Retorna true se houver mais elementos a iterar
  + Next(): int                             ' Retorna o próximo elemento e avança o índice
}

class ReverseIterator {
  - data: []int                             ' Referência à lista de inteiros a ser iterada
  - index: int                              ' Índice atual do iterador (começa do fim)
  --
  + HasNext(): bool                         ' Retorna true se houver elementos anteriores
  + Next(): int                             ' Retorna o elemento atual e retrocede o índice
}

class CyclicIterator {
  - data: []int                             ' Referência à lista de inteiros a ser iterada
  - index: int                              ' Índice atual do iterador (volta ao início ao fim)
  --
  + HasNext(): bool                         ' Sempre retorna true (iterador infinito)
  + Next(): int                             ' Retorna o próximo elemento e reinicia no fim
}
```
