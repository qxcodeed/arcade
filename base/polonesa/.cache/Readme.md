# L1 - @polonesa - Transforme da notação padrão para polonesa reversa

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/polonesa/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed polonesa`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

## Descrição

- Faça o caso simples sem parênteses
- Utilize os operadores `+`, `-`, `*`, `/` e `^`
- Precedência 1(menor): `+` e `-`
- Precedência 2: `*` e `/`
- Precedência 3(maior): `^`


## Drafts

<!-- links .cache/draft -->
- cpp
  - [flow.hpp](https://github.com/qxcodeed/arcade/blob/master/base/polonesa/.cache/draft/cpp/flow.hpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/polonesa/.cache/draft/cpp/main.cpp)
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

