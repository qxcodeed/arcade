# Árvore Binária de Busca - Serializar

<!-- toch -->
[Intro](#intro) | [Entrada e Saída](#entrada-e-saída) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

- Use o método de inserção em uma árvore binária de busca (ABB) implementado na atividade anterior.
- Implemente o método de serializar percorrendo a árvore e gerando uma string

## Entrada e Saída

- Entrada: lista de números inteiros representando a árvore a serem inseridos.
- Saída: Árvore impressa pelo BShow que já vem no rascunho seguida da serialização da árvore.

## Tests

```txt
>>>>>>>> INSERT um
4
======== EXPECT
4
4 # #
<<<<<<<< FINISH


>>>>>>>> INSERT dois
2 3 2
======== EXPECT
╭───#
2
╰───3
2 # 3 # #
<<<<<<<< FINISH


>>>>>>>> INSERT tres
4 2 1 5 2 1
======== EXPECT
    ╭───1
╭───2
│   ╰───#
4
╰───5
4 2 1 # # # 5 # #
<<<<<<<< FINISH


>>>>>>>> INSERT quatro
4 9 6 3 1
======== EXPECT
    ╭───1
╭───3
│   ╰───#
4
│   ╭───6
╰───9
    ╰───#
4 3 1 # # # 9 6 # # #
<<<<<<<< FINISH


>>>>>>>> INSERT cinco
3 2 5 8
======== EXPECT
╭───2
3
│   ╭───#
╰───5
    ╰───8
3 2 # # 5 # 8 # #
<<<<<<<< FINISH


>>>>>>>> INSERT seis
8 10 12 15 5 7 3 9 11
======== EXPECT
    ╭───3
╭───5
│   ╰───7
8
│   ╭───9
╰───10
    │   ╭───11
    ╰───12
        ╰───15
8 5 3 # # 7 # # 10 9 # # 12 11 # # 15 # #
<<<<<<<< FINISH

```
