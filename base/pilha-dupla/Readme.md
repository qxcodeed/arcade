# Pilha Dupla - CPP

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você implementará uma **Pilha Dupla** usando um único vetor para gerenciar duas pilhas diferentes: Pilha A e Pilha B. Nessa configuração, o topo da **Pilha A** começa no início do vetor, enquanto o topo da **Pilha B** começa no final. Essa abordagem permite que as duas pilhas compartilhem o mesmo espaço de armazenamento sem sobrepor seus elementos.

As operações de inserção, remoção e visualização de cada pilha (`push`, `pop`, `peek`) devem ser separadas para cada uma das pilhas, garantindo que não haja sobrescrita de elementos entre Pilha A e Pilha B. O objetivo é que as operações sejam o mais eficientes possível $O(1)$, sem desperdício de espaço.

A estrutura de dados será uma **Lista Sequencial** onde os elementos são armazenados em um array chamado `Arr`, com as informações representadas como inteiros. O arquivo `lib.cpp` contém a classe `DoubleStack`, com métodos já implementados e outros a serem desenvolvidos. Os métodos riscados já estão implementados.

### Métodos na Classe `DoubleStack`

- ~~`DoubleStack()`~~
- ~~`~DoubleStack()`~~
- ~~`void pushA(int info)`~~
- `void popA()`
- `int peekA()`
- `void clearA()`
- `void pushB(int info)`
- `void popB()`
- `int peekB()`
- `void clearB()`
- ~~`bool full()`~~
- ~~`void print()`~~

### Observações

- **OBS. 1:** Não altere os métodos já implementados.
- **OBS. 2:** Não é necessário escrever a função `main()`, pois ela já está implementada internamente no ambiente de avaliação.

## Draft

- Implemente os métodos faltantes no arquivo `lib.cpp` com base nas descrições fornecidas para cada operação.

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](.cache/draft/cpp/lib.cpp)
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A entrada consistirá em uma sequência de operações realizadas nas Pilhas A e B, incluindo inserções, remoções e verificações de estado, como se ambas estão cheias ou qual elemento está no topo.

### Saída

- A saída será composta pelos resultados das operações, incluindo o valor no topo de cada pilha ou mensagens indicando o estado de cada pilha.
