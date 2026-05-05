# Inverter a árvore

<!-- toch -->
[Descrição](#descrição) | [Exemplos](#exemplos)
-- | --
<!-- toch -->

![_](assets/cover.jpg)

## Descrição

- Inverta uma árvore binária, ou seja, troque os nós filhos esquerdo e direito de cada nó.

- Saída
  - Impressão da função 'BShow' que já vem no rascunho.

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
4 # # 
======== EXPECT
4
4
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
1 # 0 # # 
======== EXPECT
╭───#
1
╰───0
╭───0
1
╰───#
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
4 # 8 2 # # # 
======== EXPECT
╭───#
4
│   ╭───2
╰───8
    ╰───#
    ╭───#
╭───8
│   ╰───2
4
╰───#
<<<<<<<< FINISH
```
<!-- load -->
