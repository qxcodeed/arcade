# Construir árvore binaria CPP

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você implementará uma **Árvore Binária**, uma estrutura de dados hierárquica amplamente usada em computação. Cada elemento da árvore é armazenado em um nó, que pode ter no máximo dois filhos: o filho esquerdo e o filho direito. Essa estrutura permite organizar e buscar dados de maneira eficiente, sendo muito utilizada em diversas aplicações, como sistemas de arquivos, árvores de decisão e algoritmos de busca.

Por simplicidade, as informações da árvore serão representadas como inteiros.

No arquivo `lib.cpp`, encontra-se a classe `BinaryTree`, que possui os seguintes métodos:

- ~~`BinaryTree()`~~
- ~~`~BinaryTree()`~~
- `Node* search(int info)`
- `void insert(Node *current, int info)`
- `int size()`
- `int min()`
- `int max()`
- ~~`void clear()`~~
- ~~`bool empty()`~~
- ~~`void print()`~~

Os métodos riscados já estão implementados. Você precisará implementar os demais. A funcionalidade de cada método está descrita em comentários no próprio arquivo `lib.cpp`. Sua tarefa é completar o arquivo, implementando as funcionalidades faltantes.

### Observações

- **OBS. 1:** Não altere os métodos já implementados.

- **OBS. 2:** Não é necessário escrever a função `main()`. Ela já está implementada internamente no sistema de avaliação.

## Draft

- Você deve implementar os métodos faltantes no arquivo `lib.cpp`.

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/arvore/.cache/draft/cpp/lib.cpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/arvore/.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- Você receberá um conjunto de operações que devem ser realizadas na árvore binária, incluindo inserções, buscas e cálculos de tamanho, mínimo e máximo.

### Saída

- Seu programa deve imprimir os resultados das operações realizadas na árvore. O formato de saída será especificado nos casos de teste.

```txt
>>>>>>>>
Inserir 10
Inserir 5
Inserir 15
Buscar 10
Tamanho
Minimo
Maximo
========
Encontrado: 10
Tamanho: 3
Minimo: 5
Maximo: 15
<<<<<<<<
```
