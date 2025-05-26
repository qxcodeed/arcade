# Buffer Circular (Deque Dinâmico)

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Guia](#guia) | [Como implementar](#como-implementar) | [Draft](#draft) | [Shell](#shell)
-- | -- | -- | -- | -- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/bufferring/cover.jpg)

## Intro

- Vamos implementar um deque usando um buffer circular que cresce dinamicamente.
- O termo Deque (Double-Ended Queue ou Fila de final duplo) refere-se a uma estrutura de dados que permite inserção e remoção de elementos em ambas as extremidades de forma eficiente.
- A implementação mais comum do deque utiliza um vetor que manipula o índice de frente (`front`) e (`size`) para controlar a posição de leitura e escrita dos elementos em ambas as extremidades.
- Quando um dos índices atinge o início ou o final do vetor, ele é ajustado para o outro lado do vetor, criando um efeito circular.

## Guide

Esse deque simula uma lista de dois lados usando um vetor circular. O índice de frente (`front`) e o (`size`) controlam a posição de leitura e escrita. A estrutura precisa ser redimensionada quando está cheia, mantendo a ordem correta dos elementos.

## Guia

- Se sua linguagem dá suporte, utilize uma estrutura interna que lhe ofereça um vetor dinâmico, como `ArrayList` em Java, `vector` em C++, ou `slice` em Go.
- O buffer circular é uma estrutura que permite operações de inserção e remoção eficientes em ambas as extremidades, mantendo a ordem dos elementos.
- O buffer pode ser a estrutura base para implementar uma fila, que possui operações de inserção em um lado e remoção do outro.
- Outra implementação possível para o buffer seria utilizando uma lista duplamente encadeada. Mas a implementação com vetor circular é mais eficiente em termos de utilização do cache de memória e velocidade de acesso. Ou seja, mesmo que tanto a implementação com lista ligada ou com vetor circular sejam O(1) para as operações de inserção e remoção, a implementação com vetor circular é mais rápida devido à forma como a memória é acessada e manipulada pelo processador.
- A implementação deve incluir as seguintes operações:
  - Criar um deque vazio com capacidade inicial: O(1).
  - Verificar se o deque está vazio: O(1).
  - Inserir um elemento na frente, redimensionando o vetor se necessário: O(1) amortizado.
  - Inserir um elemento no fim, redimensionando o vetor se necessário: O(1) amortizado.
  - Remover um elemento da frente: O(1).
  - Remover um elemento do fim: O(1).
  - Obter o tamanho do deque: O(1).
  - Limpar o deque: O(1).
  - Gerar uma representação em string dos elementos do deque para debug: O(n).
- Observações interessantes:
  - Diferente de uma lista, o deque não deve ter um método de acesso direto aos elementos, ou seja, não deve ter um método que permita acessar um elemento em uma posição específica do deque. A única forma de acessar os elementos do deque é através das operações de inserção e remoção.
  - Deques normalmente não possuem iteradores, métodos de busca ou percorrimento. O método `toString` aqui é apenas para debug e visualização do estado do deque e normalmente não é disponibilizado em implementações reais de deques.
  - O conceito de amortizado se refere ao fato de que, embora a operação de inserção possa ser O(n) quando o vetor precisa ser redimensionado, a maioria das inserções será O(1), resultando em um custo médio O(1) ao longo de várias operações.

## Como implementar

Estrutura básica do deque:

```ts
class Deque[T] {
    data: []T
    front: int  // posição do primeiro elemento
    size: int   // número de elementos no deque
    capacity: int  // capacidade total do deque
}
```

- Um deque vazio inicia com `data` de acordo com a capacidade especificada, `front` em 0, `size` em 0 e `capacity` em 0.
- Quando o deque está cheio e um novo elemento é adicionado, primeiro o vetor é redimensionado para o dobro do tamanho atual e os elementos são copiados para a nova posição, mantendo a ordem correta, depois o novo elemento é adicionado.
- Para cada operação de inserção ou remoção, o índice `front` e `size` são atualizados corretamente, considerando o tamanho do vetor e a posição circular.
- Uma operação de push_back adiciona um elemento no final, aumentando o `size`.
- Uma operação de push_front adiciona um elemento no início, movendo o `front` para trás de forma circular.
- Uma operação de pop_front remove o elemento do início, movendo o `front` para frente.
- Você pode calcular a posição circular usando a fórmula `(index + capacity) % capacity`, onde `index` é o índice desejado e `capacity` é o tamanho do vetor.
  - Por exemplo, uma operação de push_back insere o elemento na posição `(front + size) % capacity`
  - Enquanto uma operação de push_front insere o elemento na posição `(front - 1 + capacity) % capacity`.
- Os métodos `front` e `back` retornam os elementos na frente e no final do deque, respectivamente, sem removê-los.
- As nomeclaturas mudam um pouco dependendo da linguagem, mas o conceito é o mesmo.
  - Em C++, os métodos são chamados de `front` e `back`.
  - Por exemplo, em Java, os métodos podem ser chamados de usam `First` e `Last`.
  - Em Python, é utilizado `left` e `right`.

## Draft

<!-- links .cache/draft -->
- go
  - [extra.md](https://github.com/qxcodeed/arcade/blob/master/base/bufferring/.cache/draft/go/extra.md)
  - [main.go](https://github.com/qxcodeed/arcade/blob/master/base/bufferring/.cache/draft/go/main.go)
<!-- links -->

## Shell

```bash
#TEST_CASE size
$size
0
$debug
>_ | _ | _ | _
$push_back 4
$show
[4]
$debug
>4 | _ | _ | _
$size
1
$push_back 3
$show
[4, 3]
$debug
>4 | 3 | _ | _
$size
2
$end
```

```bash
#TEST_CASE pop_front
$push_back 4 3 2
$debug
>4 | 3 | 2 | _
$pop_front
$debug
 _ |>3 | 2 | _
$push_back 1
$debug
 _ |>3 | 2 | 1
$pop_front
$debug
 _ | _ |>2 | 1
$push_back 5
$debug
 5 | _ |>2 | 1
$push_back 6
$debug
 5 | 6 |>2 | 1
$push_back 7
$debug
>2 | 1 | 5 | 6 | 7 | _ | _ | _
$end
```

```bash
#TEST_CASE clear
$push_front 1
$debug
 _ | _ | _ |>1
$push_front 2
$debug
 _ | _ |>2 | 1
$push_front 3
$debug
 _ |>3 | 2 | 1
$push_front 4
$debug
>4 | 3 | 2 | 1
$show
[4, 3, 2, 1]
$push_front 5
$debug
 4 | 3 | 2 | 1 | _ | _ | _ |>5
$show
[5, 4, 3, 2, 1]
$clear
$debug
>_ | _ | _ | _ | _ | _ | _ | _
$show
[]
$end
```

```bash
#TEST_CASE pop_front
$push_back 1 3 4 5
$show
[1, 3, 4, 5]
$pop_front
$show
[3, 4, 5]
$pop_front
$show
[4, 5]
$pop_front
$show
[5]
$pop_front
$show
[]
$pop_front
fail: buffer vazio
$show
[]
$end
```

```bash
#TEST_CASE pop_back
$push_back 1 3 4 5
$show
[1, 3, 4, 5]
$pop_back
$show
[1, 3, 4]
$pop_back
$show
[1, 3]
$pop_back
$show
[1]
$pop_back
$show
[]
$pop_back
fail: buffer vazio
$show
[]
$end
```

```bash
#TEST_CASE front e back

$push_back 1 2 3
$push_front 4 5 6
$debug
 4 | 1 | 2 | 3 | _ | _ |>6 | 5
$front
6
$back
3
$end
```
