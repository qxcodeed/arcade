# Better Search com busca binária

Vamos utilizar a busca binária para buscar elementos em uma lista ordenada sem repetição de valores.

## Implementação

```py
# python
def better_search(arr: list[int], value: int) -> tuple[bool, int]
```

```go
// go
func BetterSearch(arr []int, value int) (bool, int) 
```

- Faça a implementação da busca binária usando o intervalo [low, high[.
- O algoritmo para quando
  - O elemento é encontrado ou
  - O intervalo de busca se torna vazio (low == high).
- Ao final da busca, você pode cair nos seguintes casos.
  - A posição é válida e o elemento existe. Retorne True e a posição.
  - A posição é invalida ou o elemento não existe. Retorne False e a posição.
  - Observe que a posição retornada é onde o elemento deve ser inserido.

## Entrada e Saída

- Entrada
  - 1a linha: vetor com os elementos inteiros entre colchetes separados por espaço
  - 2a linha: elemento a ser pesquisado
- Saída
  - F ou V (Falso ou Verdadeiro) e a posição do elemento (encontrado ou onde deve ser inserido)

## Testes

```bash
>>>>>>>> INSERT
[ ]
4
======== EXPECT
F 0
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 4 ]
1
======== EXPECT
V 0
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 4 ]
2
======== EXPECT
V 1
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 4 ]
3
======== EXPECT
V 2
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 4 ]
4
======== EXPECT
V 3
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 3 4 ]
2
======== EXPECT
F 1
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 5 6 7 8 ]
4
======== EXPECT
F 3
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 7 8 9 ]
0
======== EXPECT
F 0
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 3 5 6 7 9 10 ]
2
======== EXPECT
F 1
<<<<<<<< FINISH

>>>>>>>> INSERT
[ 1 2 3 6 7 9 ]
9
======== EXPECT
V 5
<<<<<<<< FINISH

>>>>>>>> INSERT
[ -2 1 2 4 5 6 7 ]
8
======== EXPECT
F 7
<<<<<<<< FINISH

```
