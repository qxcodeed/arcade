# Pilha - invertendo com pilhas auxiliares

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, o objetivo é inverter os elementos de uma pilha. A pilha original será fornecida com uma sequência de inteiros, e você deverá reordenar os elementos de modo que a sequência final seja invertida em relação à original.

Para realizar essa inversão, você terá acesso a duas pilhas auxiliares, **PilhaB** e **PilhaC**, e não é permitido o uso de outras estruturas auxiliares, como arrays ou listas.

## Draft

- Você deve alterar o método `invertStack` no arquivo `main.cpp`

<!-- links .cache/draft -->
- cpp
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A entrada consistirá em um número inteiro seguido de uma sequência de elementos da pilha.

### Saída

- A saída deve exibir a pilha com os elementos na ordem invertida.

```txt
>>>>>>>>
5
1 2 3 4 5
========
Pilha: [ 1 2 3 4 5 ]
invert
Pilha: [ 5 4 3 2 1 ] 
```
