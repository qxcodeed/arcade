# Buscas de strings

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/buscas/cover.jpg)

Há um vetor de strings de entrada e um vetor de strings de consulta. Para cada sequência de consultas, determine quantas vezes ela ocorre na lista de sequências de entrada.

Por exemplo, dada

- **entrada = ['ab','ab','abc' ]** e
- **consultas = ['ab','abc','bc']**,

encontramos

- 2 instâncias de **'ab'** ,
- 1 de **'abc'** e
- 0 de **'bc'**.

Para cada consulta, adicionamos um elemento ao nosso vetor de retorno.

## Descrição da função

Complete a função *matchingStrings*. A função deve retornar um vetor de números inteiros representando a frequência de ocorrência de cada sequência de consultas em *sequências* .

matchingStrings possui os seguintes parâmetros:

- *strings* - uma matriz de strings para pesquisar
- *consultas* - uma matriz de cadeias de consulta

## Como fazer

- Utilize um mapa para preprocessar a matriz de strings guardando antecipadamente quais elementos existem e em que quantidade.
- Depois faça um laço com as consultas, consultando pela chave do mapa.

## Formato de entrada

- Linha 1: tamanho do vetor de consultas
- Linha 2: vetor de consultas
- Linha 3: tamanho do vetor de buscas
- Linha 4: vetor de buscas

## Formato de saída

Retorne um vetor inteiro dos resultados de todas as consultas em ordem.

## Testes

```py
>>>>>>>> 00
4 
aba baba aba xzxb
3
aba xzxb ab
========
2 1 0
<<<<<<<<

>>>>>>>> 01
3
c c mpikv
8
f c o uplbd o zl xoi mpikv
========
0 2 0 0 0 0 0 1
<<<<<<<<

>>>>>>>> 02
7
qu qu pg qu qu cjyrx y
6
o qu sxsse b pd yuv
========
0 4 0 0 0 0
<<<<<<<<
```
