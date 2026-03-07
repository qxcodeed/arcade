# Árvore Binária de Busca - Remoção

<!-- toch -->
[Intro](#intro) | [Entrada e Saída](#entrada-e-saída) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

- Utilize o método de inserção em uma árvore binária de busca (ABB) implementado na atividade anterior.
- Implemente o método de remoção da árvore binária de busca.
- No caso de um nó com dois filhos, substitua o nó pelo seu antecessor.
- Se o valor não existir, não faça nada.

## Entrada e Saída

- Entrada: 1a linha: Valores a serem inseridos para montar a árvore, 2a linha: Elemento a serem removido.
- Saída: Árvore original impressa pelo BShow que já vem no rascunho seguida da árvore modificada.

## Tests

```txt
>>>>>>>> INSERT um
4
4
======== EXPECT
original:
4
modificado:
#
<<<<<<<< FINISH

>>>>>>>> INSERT
4
5
======== EXPECT
original:
4
modificado:
4
<<<<<<<< FINISH

>>>>>>>> INSERT dois
2 3
3
======== EXPECT
original:
╭───#
2
╰───3
modificado:
2
<<<<<<<< FINISH


>>>>>>>> INSERT tres
4 2 1 5 2 1
2
======== EXPECT
original:
    ╭───1
╭───2
│   ╰───#
4
╰───5
modificado:
╭───1
4
╰───5
<<<<<<<< FINISH

>>>>>>>> INSERT tres
4 2 5 2 3 1
2
======== EXPECT
original:
    ╭───1
╭───2
│   ╰───3
4
╰───5
modificado:
    ╭───#
╭───1
│   ╰───3
4
╰───5
<<<<<<<< FINISH

>>>>>>>> INSERT quatro
4 9 6 2 3 1
2
======== EXPECT
original:
    ╭───1
╭───2
│   ╰───3
4
│   ╭───6
╰───9
    ╰───#
modificado:
    ╭───#
╭───1
│   ╰───3
4
│   ╭───6
╰───9
    ╰───#
<<<<<<<< FINISH

>>>>>>>> INSERT quatro
4 9 6 2 3 1
4
======== EXPECT
original:
    ╭───1
╭───2
│   ╰───3
4
│   ╭───6
╰───9
    ╰───#
modificado:
    ╭───1
╭───2
│   ╰───#
3
│   ╭───6
╰───9
    ╰───#
<<<<<<<< FINISH

>>>>>>>> INSERT seis
8 10 12 15 1 4 2 3
8
======== EXPECT
original:
    ╭───#
╭───1
│   │       ╭───#
│   │   ╭───2
│   │   │   ╰───3
│   ╰───4
│       ╰───#
8
│   ╭───#
╰───10
    │   ╭───#
    ╰───12
        ╰───15
modificado:
    ╭───#
╭───1
│   │   ╭───#
│   ╰───2
│       ╰───3
4
│   ╭───#
╰───10
    │   ╭───#
    ╰───12
        ╰───15
<<<<<<<< FINISH

```
