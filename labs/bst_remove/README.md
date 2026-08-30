# Árvore Binária de Busca - Remoção

<!-- toch -->
[Intro](#intro) | [Entrada e Saída](#entrada-e-saída) | [Exemplos](#exemplos)
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

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
4
4
======== EXPECT
original:
4
modificado:
#
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
4
5
======== EXPECT
original:
4
modificado:
4
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
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
```
<!-- load -->
