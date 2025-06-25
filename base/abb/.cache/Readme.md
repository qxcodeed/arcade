# Árvore Binária de Busca

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você irá trabalhar com a implementação de uma Árvore Binária de Busca (ABB), uma variação da árvore binária com regras específicas de ordenação. A árvore binária de busca é uma estrutura de dados eficiente para operações de busca, inserção e remoção, sendo amplamente utilizada em algoritmos e sistemas que precisam de organização de dados estruturados.

Em uma Árvore Binária de Busca, cada nó tem no máximo dois filhos: um filho esquerdo e um filho direito. A regra de ordenação é a seguinte:

- Todos os valores dos nós na subárvore esquerda de um nó são menores que o valor do próprio nó.
- Todos os valores dos nós na subárvore direita de um nó são maiores que o valor do próprio nó.

No arquivo `lib.cpp`, você encontrará a classe `BSTree` que representa a Árvore Binária de Busca, com alguns métodos já implementados (riscados) e outros que você precisa desenvolver.

- ~~`BSTree()`~~
- ~~`~BSTree()`~~
- `Node* search(int info)`
- `void insert(Node *current, int info)`
- `int size()`
- `int min()`
- `int max()`
- ~~`void clear()`~~
- ~~`bool empty()`~~
- ~~`void print()`~~

## Draft

- Você deve implementar os métodos faltantes no arquivo `lib.cpp`

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/abb/.cache/draft/cpp/lib.cpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/abb/.cache/draft/cpp/main.cpp)
- go
  - [main.go](https://github.com/qxcodeed/arcade/blob/master/base/abb/.cache/draft/go/main.go)
<!-- links -->

- **Importante**: Não altere os métodos que já estão implementados no arquivo `lib.cpp`. Foque apenas em completar as funcionalidades que estão faltando. O arquivo `main()` já está disponível, então você não precisa se preocupar com a entrada ou saída padrão.

## Tests

### Entrada

- A entrada para este exercício é gerada automaticamente no sistema do Moodle. Você não precisa se preocupar em lidar diretamente com a entrada ou saída, pois a árvore será manipulada internamente pelos métodos que você implementar.

### Saída

- O sistema irá verificar se a sua implementação está correta, passando casos de teste automáticos. Seu código deve garantir que as operações de busca, inserção e cálculo de tamanho, mínimo e máximo funcionem corretamente.

### Dicas para Implementação

1. **Busca**: Comece da raiz e percorra a árvore seguindo as regras da ABB até encontrar o valor ou atingir um nó nulo.
2. **Inserção**: Compare o valor a ser inserido com o nó atual. Se for menor, vá para o filho esquerdo; se for maior, vá para o filho direito, inserindo na posição correta.
3. **Tamanho**: Percorra toda a árvore e conte o número de nós.
4. **Mínimo e Máximo**: Vá para o nó mais à esquerda para encontrar o mínimo e para o mais à direita para o máximo.
