# L1 - @buscas de strings

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/buscas/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed buscas`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

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

## Formato de entrada

- Linha 1: tamanho do vetor de consultas
- Linha 2: vetor de consultas
- Linha 3: tamanho do vetor de buscas
- Linha 4: vetor de buscas

## Formato de saída

Retorne um vetor inteiro dos resultados de todas as consultas em ordem.

## Testes

```txt
>>>>>>>> 01
4 
aba baba aba xzxb 
3
aba xzxb ab
========
2 1 0
<<<<<<<<
```
