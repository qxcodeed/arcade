# Construindo Pilha com Lista Encadeada - CPP

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você implementará uma estrutura de dados fundamental na computação: a **Pilha**. A pilha é uma estrutura linear que segue o princípio **LIFO** (Last In, First Out), o que significa que o último elemento inserido é o primeiro a ser removido. Um exemplo clássico de pilha é uma pilha de pratos, onde você só pode remover o prato que está no topo.

A pilha neste exercício é implementada usando uma **Lista Simplesmente Encadeada**, onde cada nó contém um valor inteiro e um ponteiro para o próximo nó. É importante manter o atributo `size` atualizado após cada operação de inserção ou remoção.

**Detalhes da implementação**: Por simplicidade, os elementos armazenados na pilha serão números inteiros.

No arquivo `lib.cpp`, você encontrará a classe `Stack` com os seguintes métodos:

- ~~`Stack()`~~
- ~~`~Stack()`~~
- `void push(int info)`
- `void pop()`
- `int peek()`
- `void clear()`
- ~~`bool empty()`~~
- ~~`void print()`~~

**Importante**: Não altere os métodos que já estão implementados no arquivo `lib.cpp`. Concentre-se em completar as funcionalidades faltantes conforme as instruções nos comentários. O arquivo `main()` já está implementado no Moodle, então você não precisa se preocupar com a entrada e saída padrão.

Os métodos riscados já estão implementados. Você deve completar os métodos `push`, `pop`, `peek` e `clear`. As descrições de cada método estão nos comentários dentro do arquivo `lib.cpp`. Sua tarefa é completar o código conforme especificado.

## Draft

- Implemente os métodos faltantes no arquivo `lib.cpp` conforme as instruções fornecidas.

<!-- links .cache/draft -->
<!-- links -->

## Tests

### Entrada

- A entrada para este exercício será gerada automaticamente com uma série de operações que serão testadas na sua implementação da classe `Stack`. Você não precisa implementar a leitura ou a escrita da entrada/saída, pois isso já está disponível na infraestrutura do Moodle.

### Saída

- Seu código deve garantir que as operações de `push`, `pop`, `peek` E `clear` funcionem corretamente e que o tamanho da pilha (`size`) seja atualizado de forma precisa após cada operação.

### Dicas para Implementação

1. **Push**: Crie um novo nó, faça-o apontar para o nó atualmente no topo e atualize o ponteiro de topo para o novo nó. Lembre-se de incrementar `size`.
2. **Pop**: Verifique se a pilha não está vazia antes de remover o nó do topo. Atualize o ponteiro de topo e decremente `size`. Não se esqueça de liberar a memória do nó removido.
3. **Peek**: Retorne o valor do elemento no topo, garantindo que a pilha não esteja vazia.
4. **Clear**: Limpa toda a pilha e atualiza o `size`.
