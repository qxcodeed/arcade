# Transforme da notação padrão para polonesa reversa

## Descrição

- Faça o caso simples sem parênteses
- Utilize os operadores `+`, `-`, `*`, `/` e `^`
- Precedência 1(menor): `+` e `-`
- Precedência 2: `*` e `/`
- Precedência 3(maior): `^`

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
3 + 4 * 2
======== EXPECT
3 4 2 * +
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
3 + 4 * 2 - 1
======== EXPECT
3 4 2 * + 1 -
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
3 + 4 * 2 - 1 / 2
======== EXPECT
3 4 2 * + 1 2 / -
<<<<<<<< FINISH
```
<!-- load -->
