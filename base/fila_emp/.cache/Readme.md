# ANTIGO Utilizando Pilhas para a Criação de uma Fila

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Test](#test)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você implementará uma fila usando **duas pilhas**. Embora não seja a forma mais eficiente de implementar uma fila, esta abordagem é útil para entender a lógica de manipulação de pilhas e filas.

### Estrutura

A classe `StackedQueue` já está definida no arquivo `lib.cpp`, contendo os seguintes métodos:

- ~~`StackedQueue()`~~
- `void push(int info)`
- `void pop()`
- `int peek()`
- `void clear()`
- ~~`bool empty()`~~
- ~~`void print()`~~

Os métodos riscados já estão implementados; você deverá implementar os demais métodos, conforme descrito nos comentários do arquivo `lib.cpp`.

### Funcionamento dos Métodos

- A fila será implementada usando duas pilhas: `stack` e `aux`.
  - `stack` armazena os elementos inseridos.
  - `aux` é usada para acessar o elemento no início da fila em operações `peek` e `pop`.

### Observações

- **OBS. 1**: Não altere os métodos já implementados.
- **OBS. 2**: Não é necessário escrever a função `main()`, pois ela já está implementada no ambiente de avaliação.

## Draft

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/fila_emp/.cache/draft/cpp/lib.cpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/fila_emp/.cache/draft/cpp/main.cpp)
<!-- links -->

## Test

### Entrada

- A entrada consistirá em uma sequência de operações de inserção (`push`), remoção (`pop`), consulta (`peek`) e limpeza (`clear`).

### Saída

- O programa deve exibir o estado da fila conforme as operações realizadas, conforme descrito nos casos de teste.
