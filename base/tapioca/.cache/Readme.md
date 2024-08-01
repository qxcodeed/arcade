# L3 - @tapioca Sort

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Preparar a pilha perfeita de tapiocas é uma tarefa complicada, pois todas as tapiocas em qualquer pilha têm diâmetros diferentes. Para manter a pilha organizada, você pode ordenar as tapiocas por tamanho de forma que cada tapioca seja menor do que todas as tapiocas abaixo dela. O tamanho de uma tapioca é determinado pelo seu diâmetro.

A ordenação de uma pilha é feita por uma sequência de viradas de tapiocas. Uma virada consiste em inserir uma espátula entre duas tapiocas em uma pilha e virar (inverter) todas as tapiocas acima da espátula, invertendo a subpilha.

Uma virada é especificada pela posição da tapioca na parte inferior da subpilha a ser virada em relação a toda a pilha. A tapioca de baixo tem a posição 1, enquanto a tapioca de cima em uma pilha de `n` tapiocas tem posição `n`.

Uma pilha é especificada dando o diâmetro de cada tapioca na ordem em que aparecem na pilha. Por exemplo, considere a seguinte pilha de tapiocas, onde a tapioca com diâmetro 5 está no topo:

```txt
topo -> 5 1 2 3 4 |
```

Fazendo a operação `virada 1` (a espátula está representada por |), obtemos a seguinte pilha de tapiocas:

```txt
topo -> 4 3 2 1 | 5
```

Fazendo a operação `virada 2`, obtemos a seguinte pilha de tapiocas:

```txt
topo -> 1 2 3 4 5
```

Observe que a pilha de tapiocas pode ser ordenada utilizando duas operações de virada.

## Draft

- Você deve implementar a função `tapiocaSort` e suas auxiliares no arquivo `main.cpp`.

<!-- links .cache/draft -->
- cpp
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A primeira linha contém um inteiro N representando o número de tapiocas.
- A segunda linha contém N inteiros positivos representando os diâmetros das tapiocas na pilha. Cada tapioca terá um diâmetro entre 1 e 30.

### Saída

- Seu programa deve imprimir uma sequência de viradas que resulte na pilha de tapiocas ordenada de maneira que a maior tapioca esteja na parte inferior e a menor tapioca na parte superior. A sequência de viradas deve terminar com 0, indicando que não são mais necessárias viradas.

```txt
>>>>>>>>
5
5 1 2 3 4
========
1 2 0
<<<<<<<<
```

```txt
>>>>>>>>
5
5 4 3 2 1
========
1 0
<<<<<<<<
```
