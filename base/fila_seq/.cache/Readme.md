# ANTIGO Fila usando vetor circular

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você implementará uma **Fila** usando uma **Lista Sequencial** (array). A fila é uma estrutura de dados linear que segue o princípio FIFO (**First In, First Out**), onde o primeiro elemento inserido é o primeiro a ser removido.

Na implementação da fila sequencial, os elementos são armazenados em um array `Arr`, e a fila possui:

- `front`: ponteiro que aponta para o primeiro elemento da fila.
- `size`: representa o número atual de elementos na fila e deve ser atualizado após cada operação de inserção e remoção.
- `capacity`: representa o tamanho máximo da fila.

### Estrutura do Exercício

A classe `SequentialQueue` está definida no arquivo `lib.cpp` e possui os seguintes métodos:

- ~~`SequentialQueue()`~~
- ~~`~SequentialQueue()`~~
- `void push(int info)`
- `void pop()`
- `int peek()`
- `void clear()`
- `bool empty()`
- `bool full()`
- ~~`void print()`~~

Os métodos riscados já estão implementados; você deve implementar os demais métodos, conforme as descrições nos comentários do arquivo `lib.cpp`.

### Observações

- **OBS. 1:** Não altere os métodos já implementados.
- **OBS. 2:** Não é necessário escrever a função `main()`, pois ela já está implementada no ambiente de avaliação.

## Draft

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/fila_seq/.cache/draft/cpp/lib.cpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/fila_seq/.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A entrada consistirá em uma sequência de operações.

### Saída

- O programa deve exibir o estado da fila conforme as operações realizadas, conforme descrito nos casos de teste.
