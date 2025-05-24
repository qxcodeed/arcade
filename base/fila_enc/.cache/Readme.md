# Fila usando lista encadeada simples

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você implementará uma **Fila** utilizando uma **Lista Simplesmente Encadeada**. Fila é uma estrutura de dados linear que segue o princípio FIFO (**First In, First Out**), onde o primeiro elemento inserido é também o primeiro a ser removido.

Na implementação de uma fila encadeada, cada nó contém uma informação e um ponteiro para o próximo elemento. A estrutura da fila é composta por:

- `head`: ponteiro para o primeiro nó da fila.
- `tail`: ponteiro para o último nó da fila.

Cada operação de inserção e remoção na fila deve atualizar o atributo `size`, que representa o número de elementos na fila.

### Estrutura do Exercício

A classe `LinkedQueue` está definida no arquivo `lib.cpp` e possui os seguintes métodos:

- ~~`LinkedQueue()`~~
- ~~`~LinkedQueue()`~~
- `void push(int info)`
- `void pop()`
- `int peek()`
- `void clear()`
- ~~`void empty()`~~
- ~~`void print()`~~

Os métodos riscados já estão implementados; você deve implementar os demais métodos, conforme as descrições nos comentários do arquivo `lib.cpp`.

### Observações

- **OBS. 1:** Não altere os métodos já implementados.
- **OBS. 2:** Não é necessário escrever a função `main()`, pois ela já está implementada no ambiente de avaliação.

## Draft

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/fila_enc/.cache/draft/cpp/lib.cpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/fila_enc/.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A entrada consistirá em uma sequência de operações de inserção (`push`), remoção (`pop`), consulta (`peek`), e limpeza (`clear`).

### Saída

- O programa deve exibir o estado da fila conforme as operações realizadas, seguindo o formato descrito nos casos de teste.
