# Arvore incompleta

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, você irá treinar a atribuição de valores relacionados a cada nó de uma árvore binária. A árvore é composta por nós, onde cada nó pode ter um filho à esquerda e um filho à direita. Além disso, cada nó possui os seguintes atributos adicionais:

- `Node *parent`: um ponteiro para o nó pai.
- `int size`: o tamanho da subárvore enraizada nesse nó.
- `int level`: o nível do nó na árvore (começando em 0 para a raiz).
- `int height`: a altura da subárvore enraizada nesse nó.

A árvore é iniciada sem esses valores atribuídos, e sua tarefa é implementar o método `fill()` para preencher corretamente essas informações. Este método deve ser capaz de percorrer a árvore e calcular os valores de cada nó de maneira recursiva.

**Importante**: Não altere os métodos já implementados no arquivo `lib.cpp`. Você deve se concentrar apenas em implementar as funcionalidades que estão faltando. O arquivo principal `main()` já está implementado, então você não precisa se preocupar com isso.

## Draft

- Você deve implementar a função `fill()` no arquivo `lib.cpp` para que os atributos `parent`, `size`, `level` e `height` sejam corretamente atribuídos a cada nó da árvore.

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/incompleta/.cache/draft/cpp/lib.cpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/incompleta/.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A entrada consistirá na construção da árvore binária, onde cada nó é representado por sua referência na memória. Não é necessário se preocupar com a entrada padrão, pois a árvore será criada automaticamente pelo sistema.

### Saída

- Após a execução do seu método `fill()`, a árvore deve ter todos os nós preenchidos corretamente com os valores de `parent`, `size`, `level` e `height`. Você deve garantir que, ao imprimir a árvore, os valores atribuídos estejam corretos e representem a estrutura da árvore.

### Dicas para Implementação

1. **Nível**: O nível de um nó pode ser calculado com base no nível do nó pai, aumentando em 1 para cada nível descendo na árvore.
2. **Tamanho**: O tamanho de um nó deve ser igual a 1 (contando ele mesmo) mais o tamanho de suas subárvores esquerda e direita.
3. **Altura**: A altura de um nó pode ser calculada como 1 (contando ele mesmo) mais a altura da subárvore mais alta entre suas duas subárvores.

### Exemplos

Considere a seguinte árvore binária:

```txt
        A
       / \
      B   C
     / \
    D   E
```

Após a implementação do método `fill()`, você deve ser capaz de acessar e imprimir as informações dos nós:

```txt
No: A
Parent: NULL
Size: 5
Level: 0
Height: 2

No: B
Parent: A
Size: 3
Level: 1
Height: 1

No: C
Parent: A
Size: 1
Level: 1
Height: 0

No: D
Parent: B
Size: 1
Level: 2
Height: 0

No: E
Parent: B
Size: 1
Level: 2
Height: 0
```

A correta implementação do método `fill()` deve garantir que todas as informações estejam coerentes com a estrutura da árvore.
