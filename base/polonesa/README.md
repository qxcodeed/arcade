# Transforme da notação padrão para polonesa reversa

## Descrição

- Faça o caso simples sem parênteses
- Utilize os operadores `+`, `-`, `*`, `/` e `^`
- Precedência 1(menor): `+` e `-`
- Precedência 2: `*` e `/`
- Precedência 3(maior): `^`

## Drafts

<!-- links .cache/drafts -->
- cpp
  - [fn.hpp](.cache/drafts/cpp/fn.hpp)
  - [main.cpp](.cache/drafts/cpp/main.cpp)
<!-- links -->

## Testes

```bash

>>>>>>>>
3 + 4 * 2
========
3 4 2 * +
<<<<<<<<


>>>>>>>>
3 + 4 * 2 - 1
========
3 4 2 * + 1 -
<<<<<<<<

>>>>>>>>
3 + 4 * 2 - 1 / 2
========
3 4 2 * + 1 2 / -
<<<<<<<<

>>>>>>>>
1 + 2 * 3 ^ 4
========
1 2 3 4 ^ * +
<<<<<<<<

>>>>>>>>
1 + 2 * 3 ^ 4 - 5
========
1 2 3 4 ^ * + 5 -
<<<<<<<<

```
