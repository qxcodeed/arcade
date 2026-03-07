# Divisão e Resto

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/resto/cover.jpg)

Para trabalhar essa técnica, vamos resolver o seguinte problema.

Seja um número inteiro, você deve imprimir os resultados da divisão inteira por 2 e o resto da divisão por 2 até que o número seja 0, porém na ordem inversa.

Vamos utilizar o número 100 como exemplo.

- Primeiro vamos dividir 100 por 2 e obter o resultado 50 e o resto 0.
- Depois vamos dividir 50 por 2 e obter o resultado 25 e o resto 0.
- Depois vamos dividir 25 por 2 e obter o resultado 12 e o resto 1.
- Depois vamos dividir 12 por 2 e obter o resultado 6 e o resto 0.
- Depois vamos dividir 6 por 2 e obter o resultado 3 e o resto 0.
- Depois vamos dividir 3 por 2 e obter o resultado 1 e o resto 1.
- Depois vamos dividir 1 por 2 e obter o resultado 0 e o resto 1.

Imprimindo ao contrário, temos:

```txt
0 1
1 1
3 0
6 0
12 1
25 0
50 0
```

## Resolução

[![imagem](https://user-images.githubusercontent.com/4747652/267033420-04b92b31-5905-45ea-9cb6-f903681e7e20.png)](https://youtu.be/2n8w2yju6Sc)

## Testes

```bash

>>>>>>>>
5
========
0 1
1 0
2 1
<<<<<<<<

>>>>>>>>
100
========
0 1
1 1
3 0
6 0
12 1
25 0
50 0
<<<<<<<<

>>>>>>>>
101
========
0 1
1 1
3 0
6 0
12 1
25 0
50 1
<<<<<<<<


>>>>>>>>
150
========
0 1
1 0
2 0
4 1
9 0
18 1
37 1
75 0
<<<<<<<<

```
