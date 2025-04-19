# Construindo uma Pilha com Lista Sequencial CPP

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você implementará uma **Pilha** usando uma **Lista Sequencial**, uma estrutura de dados linear que segue o princípio **LIFO** (Last In, First Out). Isso significa que o último elemento inserido será o primeiro a ser removido. Pilhas são frequentemente usadas em várias aplicações, como gerenciamento de chamadas de função, navegação na web (pilha de histórico), e avaliação de expressões aritméticas.

A pilha será implementada usando um array chamado `Arr`, onde cada elemento armazenado será um inteiro. A classe `Stack` no arquivo `lib.cpp` já possui alguns métodos implementados, enquanto outros ainda precisam ser desenvolvidos.

### Métodos na Classe `Stack`

- ~~`Stack()`~~
- ~~`~Stack()`~~
- `void push(int info)`
- `void pop()`
- `int peek()`
- `void clear()`
- `bool full()`
- ~~`void empty()`~~
- ~~`void print()`~~

Os métodos riscados estão prontos. Você precisará implementar os métodos `push`, `pop`, `peek`, `clear`, e `full`. As instruções detalhadas sobre cada método estão nos comentários dentro do arquivo `lib.cpp`. Lembre-se de seguir as direções corretamente para garantir que sua implementação passe nos testes.

### Observações

- **OBS. 1:** Não altere os métodos já implementados.
- **OBS. 2:** Não é necessário escrever a função `main()`. Ela já está provida no ambiente de avaliação.

## Draft

- Implemente os métodos faltantes no arquivo `lib.cpp` usando a lógica apropriada para uma pilha baseada em array.

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](.cache/draft/cpp/lib.cpp)
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A entrada consiste em uma sequência de operações na pilha, incluindo inserções, remoções, e verificações de estado, como se a pilha está cheia ou se um elemento específico está no topo.

### Saída

- A saída consiste nas respostas para as operações realizadas, como o valor no topo da pilha ou mensagens indicando se a pilha está cheia ou vazia.
