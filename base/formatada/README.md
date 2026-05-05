# Mostrando a árvore formatada

<!-- toch -->
[Descrição](#descrição) | [Exemplos](#exemplos)
-- | --
<!-- toch -->

![_](assets/cover.jpg)

## Descrição

- Leia a string que representa a árvore serializada utilizando o código que você implementou no exercício @serial para construir sua árvore.
- Crie um método recursivo chamado `my_show()` que recebe um nó e um inteiro `depth` (inicialmente 0) e imprime a árvore formatada.
- Utilize o espaçamento de "...." para cada nível de profundidade do nó.
- Faça a impressão usando o percorrimento in-order.
- Se o nó possuir pelos menos um filho não nulo, chame a recursão para ambos os filhos e imprima o filho nulo como um #
- Se o nó não possuir filhos, imprima apenas o valor do nó.

- Saída
  - Impressão da função 'BShow' que já vem no rascunho, seguido da sua função de impressão `MyShow()`.

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
....#
1
....0
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
....#
4
........2
....8
........#
<<<<<<<< FINISH
```
<!-- load -->
