# L3 - @fibonacci2 - Fazendo filhos e morrendo

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Suponha agora os nossos coelhos não vivam para sempre e morrem depois de 3 meses. Contudo, os coelhos acasalam com um mês de idade e cada fêmea produz um novo par de coelhos a cada mês a partir do segundo mês.

![Fibonacci](Fibonacci.png)

A imagem mostra que ao final de seis meses teremos apenas 4 pares de coelhos considerando que os coelhos morrem após 3 meses. Quantos pares de coelhos teremos ao final de $n$ meses?

Desenvolva uma função recursiva $f(n)$ que devolve o número de pares de coelhos após n meses considerando que os coelhos morrem depois de 3 meses.

## Draft

- Você deve implementar de forma recursiva a função `f` no arquivo `main.cpp`.

<!-- links .cache/draft -->
- cpp
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

- Entrada
  - A entrada é composta por uma única linha contendo um único inteiro correspondente ao mês desejado ($1 \leq n \leq 40$).

- Saída
  - A saída é composta por uma única linha contendo o número total de pares de coelhos que estão presentes após n meses, se começarmos com 1 par e em cada geração, cada par de coelhos em idade reprodutiva produz um par de coelhos e eles morrem depois de 3 meses.

```txt
>>>>>>>>
6
========
4
<<<<<<<<
```

```txt
>>>>>>>>
40
========
55405
<<<<<<<<
```
