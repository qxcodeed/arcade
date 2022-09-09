## @028 L2 - {robot} sudoku

![](https://raw.githubusercontent.com/qxcodefup/arcade/master/base/028/cover.jpg)

O Sudoku tem várias versões para diferentes dificuldades. O mais conhecido é o modelo 9x9.

O site [sudoku](https://www.sudokuonline.io/pt/criancas) tem versões simplificadas para crianças com versões 4x4 e 6x6.

![](https://raw.githubusercontent.com/qxcodefup/arcade/master/base/028/__exemplos.png)

Seu objetivo é resolver um sudoku NxN com números de 1 a N.

N pode ser 4 ou 9

- Entrada
    - Valor de N
    - Uma matriz N x N composta por números de 1 a N e pontos para os valores faltantes.
- Saída
    - O problema resolvido.

```
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

Você pode utilizar o seguinte modelo para simplificar a lógica do sudoku

```cpp
struct Problem {
    vector<string> data;          //vetor de dados
    int size { 9 };               //normalmente 4 ou 9
    int dim { 3 };                //2 ou 3
    vector<pair<int, int>> holes; //posicoes para serem preenchidas

    Problem(vector<string> data) {
        this->data = data;
        this->size = data.size();
        this->dim = sqrt(this->size);

        for (int l = 0; l < size; l++)      //percorre todas as posições e guarda as que são .
            for (int c = 0; c < size; c++)
                if (data[l][c] == '.')
                    holes.push_back(make_pair(l, c));
    }

    //verifica se pode colocar esse valor nessa posição
    //pode colocar se não encontrar na linha, na coluna ou no quadrante
    bool fit(int hindex, char value) {
        auto [pl, pc] = holes[hindex];  //acha a posicao no vetor de posições
        
        for (int l = 0; l < size; l++) //olhando todas as linhas dessa coluna
            if (data[l][pc] == value) 
                return false;
        
        for (int c = 0; c < size; c++) //olhando todas as colunas dessa linha
            if (data[pl][c] == value)
                return false;
        
        int lh = pl - pl % dim; //achando a cabeça do quadrante removendo a sobra
        int ch = pc - pc % dim;
        for (int l = lh; l < lh + dim; l++)
            for (int c = ch; c < ch + dim; c++)
                if (data[l][c] == value)
                    return false;

        return true;
    }
}
```