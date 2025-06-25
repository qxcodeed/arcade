# Capturar Regiões Cercadas

Após fazer essa atividade aqui, rode todos os casos de testes no site do leetcode para verificar se o código está correto. [Link para o problema](https://leetcode.com/problems/surrounded-regions/)

Após passar nos testes do site do leetcode, você pode marcar manualmente como feito.

Você recebe uma matriz `m x n` chamada `board`, contendo letras `'X'` e `'O'`. O objetivo é capturar regiões que estão **cercadas**.

## Definições

- **Conectar**: Uma célula está conectada às células adjacentes horizontal ou verticalmente.
- **Região**: Uma região é formada conectando todas as células `'O'` adjacentes.
- **Cercada**: Uma região está cercada por células `'X'` se for possível conectá-la com `'X'` e nenhuma das células da região estiver na borda do tabuleiro.

## Objetivo

Para capturar uma região cercada, substitua todos os `'O'` por `'X'` diretamente na matriz original. Não é necessário retornar nada.

## Estratégia

- Crie um mapa de visitados e visite todas as ilhas que estão conectadas às bordas do tabuleiro. Se está na borda, então não é cercada.
- Depois, percorra a matriz e substitua os `'O'` não visitados por `'X'`.

## IO

- Entrada
  - número de linhas e número de colunas da matriz
  - matriz com letras `'X'` e `'O'`
- Saída
  - matriz modificada com as regiões cercadas capturadas com `'X'`

## Testes

```txt
>>>>>>>> INSERT
4 4
XXXX
XOOX
XXOX
XOXX
======== EXPECT
XXXX
XXXX
XXXX
XOXX
<<<<<<<< FINISH
```

```txt
>>>>>>>> INSERT
1 1
X
======== EXPECT
X
<<<<<<<< FINISH
```

```txt
>>>>>>>> INSERT
5 5
XXXXX
XOOOX
XXOXX
XXXOX
XXXOX
======== EXPECT
XXXXX
XXXXX
XXXXX
XXXOX
XXXOX
<<<<<<<< FINISH
```
