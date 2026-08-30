# Lendo uma árvore a partir de um serial

<!-- toch -->
[Descrição](#descrição) | [Exemplos](#exemplos)
-- | --
<!-- toch -->

![_](assets/cover.jpg)

## Descrição

- Leia a string que representa a árvore serializada.
- Você deve construir a árvore a partir da string implementando corretamente o construtor do código de partida.
- Você pode entender a lógica de serialização no seguinte [link para explicação](https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/).
- A saída é a árvore percorrida in-order, mas já está implementado no código de partida.
- Baixe o código de rascunho e implemente a função `create` para construir a árvore a partir da string serializada.

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
4 # # 
======== EXPECT
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
<<<<<<<< FINISH
```
<!-- load -->
