# Sudoku

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/sudoku/cover.jpg)

O Sudoku tem várias versões para diferentes dificuldades. O mais conhecido é o modelo 9x9.

O site [sudoku](https://www.sudokuonline.io/pt/criancas) tem versões simplificadas para crianças com versões 4x4 e 6x6.

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/sudoku/__exemplos.png)

Seu objetivo é resolver um sudoku NxN com números de 1 a N.

N pode ser 4 ou 9

- Se for 4, um número de 1 a 4 deve aparecer em cada linha, coluna e quadrante 2x2.
- Se for 9, um número de 1 a 9 deve aparecer em cada linha, coluna e quadrante 3x3.

- Entrada
  - Valor de N
  - Uma matriz N x N composta por números de 1 a N e pontos para os valores faltantes.
- Saída
  - O problema resolvido.

```txt
>>>>>>>>
4
1.3.
2...
...4
.1..
========
1432
2341
3214
4123
<<<<<<<<

>>>>>>>>
4
..2.
.1..
..4.
.3..
========
3421
2134
1243
4312
<<<<<<<<


>>>>>>>>
4
....
.2.1
1.3.
....
========
4123
3241
1432
2314
<<<<<<<<

>>>>>>>>
4
....
3.2.
.1.4
....
========
1243
3421
2134
4312
<<<<<<<<

>>>>>>>>
9
53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79
========
534678912
672195348
198342567
859761423
426853791
713924856
961537284
287419635
345286179
<<<<<<<<


```

## Ajuda

Use a mesma lógica do problema distância para percorrer a matriz. Você pode usar um índice progressivo e converter esse valor para linha e coluna como no exemplo abaixo:

- Crie funções diferentes para verificar se o número já existe na linha, coluna e quadrante.
- Para calcular o quadrante, você pode usar a divisão inteira e o resto da divisão.
- A função abaixo retorna uma lista com todos os valores do quadrante do elemento.
- A função é feita propositalmente feia para você entender como ela funciona.

```go
func quadrante(matriz [][]rune, lin, col int) []rune {
    dim := len(matriz)
    l := (lin // dim) * dim
    c := (col // dim) * dim

    if dim == 4 {
        return []rune{
            matriz[l+0][c], matriz[l+0][c+1],
            matriz[l+1][c], matriz[l+1][c+1],
        }
    }

    if dim == 9 {
        return []rune{
            matriz[l+0][c], matriz[l+0][c+1], matriz[l+0][c+2],
            matriz[l+1][c], matriz[l+1][c+1], matriz[l+1][c+2],
            matriz[l+2][c], matriz[l+2][c+1], matriz[l+2][c+2],
        }
    }
    return nil
}
```

```go
func resolver(matriz [][]rune, index int) bool {
    nl := len(matriz)
    l := index / nl
    c := index % nl
    if index == nl * nl {
        return True
    }
    // se não for ponto, continue
    // para todos os números de [1 a N]
    //     se o número não estiver na linha, coluna e quadrante
    //         coloque o número na matriz
    //         se resolver(matriz, index + 1):
    //             return True
    //         matriz[l][c] = '.' // desfaz a tentativa
    // return False
}
```
