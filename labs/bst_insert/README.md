# Árvore Binária de Busca - Inserção

<!-- toch -->
[Intro](#intro) | [Entrada e Saída](#entrada-e-saída) | [Exemplos](#exemplos)
-- | -- | --
<!-- toch -->

## Intro

- Implemente o método de inserção em uma árvore binária de busca (ABB).
- Se o valor já existir na árvore, não faça a inserção.

## Entrada e Saída

- Entrada: lista de números inteiros representando a árvore a serem inseridos.
- Saída: Árvore impressa pelo BShow que já vem no rascunho.

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
4
======== EXPECT
4
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
2 3 2
======== EXPECT
╭───#
2
╰───3
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
4 2 1 5 2 1
======== EXPECT
    ╭───1
╭───2
│   ╰───#
4
╰───5
<<<<<<<< FINISH
```
<!-- load -->
