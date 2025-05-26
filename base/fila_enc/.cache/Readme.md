# Fila usando lista encadeada simples

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Shell](#shell)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você implementará uma **Fila** utilizando uma **Lista Simplesmente Encadeada**. Fila é uma estrutura de dados linear que segue o princípio FIFO (**First In, First Out**), onde o primeiro elemento inserido é também o primeiro a ser removido.

Na implementação de uma fila encadeada, cada nó contém uma informação e um ponteiro para o próximo elemento. A estrutura da fila é composta por:

- `head`: ponteiro para o primeiro nó da fila. É utilizado para remover elementos da fila.
- `tail`: ponteiro para o último nó da fila. É utilizado para adicionar novos elementos à fila.

Cada operação de inserção e remoção na fila deve atualizar o atributo `size`, que representa o número de elementos na fila. Sua fila não deve utilizar nós de marcação, ou seja, não deve haver nós que não contenham dados válidos. Todas as operações devem ser implementadas de forma eficiente.

### Complexidade das operações

- Inserção (`push`): O(1) - Adiciona um elemento ao final da fila (enqueue).
- Remoção (`pop`): O(1) - Remove o elemento do início da fila (dequeue).
- Verificação do tamanho (`size`): O(1) - Retorna o número de elementos na fila.
- Verificação se a fila está vazia (`isEmpty`): O(1) - Retorna verdadeiro se não há elementos na fila.
- Visualização do primeiro elemento (`peek`): O(1) - Retorna o primeiro elemento sem removê-lo.
- Visualização do estado da fila (`show`): O(n) - Retorna uma representação em string dos elementos da fila para debug.

## Draft

<!-- links .cache/draft -->
- go
  - [main.go](https://github.com/qxcodeed/arcade/blob/master/base/fila_enc/.cache/draft/go/main.go)
<!-- links -->

## Shell

```bash
#TEST_CASE 01
$push 4
$push 5
$push 6
$show
[4, 5, 6]
$end
```

```bash
#TEST_CASE 02
$push 1 3 5 7 8
$show
[1, 3, 5, 7, 8]
$pop
$show
[3, 5, 7, 8]
$pop
$show
[5, 7, 8]
$end
```

```bash
#TEST_CASE 03
$push 10
$push 20
$push 30
$peek
10
$pop
$peek
20
$pop
$peek
30
$pop
$peek
falha: fila vazia
$pop
falha: fila vazia
$end
```
