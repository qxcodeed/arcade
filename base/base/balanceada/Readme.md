# Fórmula balanceada

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Neste exercício, o objetivo é verificar se uma string composta apenas por parênteses `()` e colchetes `[]` está **balanceada**.

Uma string é considerada balanceada quando:

- Para cada símbolo de abertura, existe um símbolo de fechamento correspondente.
- Os símbolos estão na ordem correta e corretamente aninhados.

Exemplos de strings balanceadas:

- `"()"`, `"(())"`, `"[()]"`, `"[()][]()"`

Exemplos de strings não balanceadas:

- `")("`, `"(()"`, `"[(])"`

## Draft

<!-- links .cache/draft -->
- cpp
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

### Observações

- Certifique-se de verificar correspondência exata entre os parênteses e colchetes.
- O algoritmo deve percorrer a string apenas uma vez, garantindo eficiência.

## Tests

### Entrada

- A entrada será uma string contendo apenas parênteses `()` e colchetes `[]`.

### Saída

- `balanceado` se a string estiver balanceada.
- `nao balanceado` caso contrário.

```txt
>>>>>>>>
(())
========
balanceado
<<<<<<<<
```
