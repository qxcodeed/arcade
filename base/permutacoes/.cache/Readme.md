# Permutando coisas

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/permutacoes/cover.jpg)

O problema de **Permutações** consiste em listar **todas as permutações distintas** de uma *string de caracteres*.

Por exemplo, para a palavra `"abc"`, as permutações são:

`[abc, acb, bac, bca, cab, cba]`

## Entrada

A entrada consiste em uma única string com até `6` caracteres (sem espaços):

- `s` — string de entrada  
  `1 ≤ |s| ≤ 6`  
  Os caracteres são únicos.

## Saída

- Uma lista com **todas as permutações distintas** da string de entrada, **ordenadas lexicograficamente**, uma por linha.

---

**Você pode ver sobre ordem lexicográfica [aqui](https://en.wikipedia.org/wiki/Lexicographic_order).**

**Dica:** coloque todas as permutações **em um array**, e depois **ordene o array** para garantir a ordem lexicográfica na saída.

### Exemplo

```txt
>>>>>>>>
abc
========
abc
acb
bac
bca
cab
cba
<<<<<<<<
```

```txt
>>>>>>>>
ab
========
ab
ba
<<<<<<<<
```
