## L1 - {interactive} Random matriz

Vamos preencher uma matriz aleatoriamente com árvores `#` e espaços vazios `.`.

Leia do usuário utilizando os parâmetros de argc e argv a quantidade de linhas e quantidade de colunas e a porcentagem de árvores.

Utilize a geração de números aleatórios para gerar sempre matrizes diferentes. Conte a quantidade de árvores que seu algoritmo está colocando e veja se se aproxima do que foi solicitado pelo usuário.

Uma forma simples de fazer isso é para cada célula fazer `(rand() % 100 < porcentagem)` para verificar se ela deve ser uma árvore.

Recebendo parâmetros em c e c++
```c++
int main(int argc, char * argv[]) {
```


## Exemplo

```bash
$ ./gerar_mat 10 20 60
10 20
##...####.#####.###.
#####.##....#..###.#
#.#.####.#.#...##..#
#.##.#.#.###...#..#.
###.....###..###.#.#
###.#..##.#.##..##..
#####.#####..#.##..#
#..#.#.###.#....#..#
#.#####.####.####...
##.###..####..#..##.

$ ./gerar_mat 8 30 70
8 30
#.######..#####.####..#.#.#.##
..###.####..####.#####.###.###
##...####..#..#.#######.####.#
.###..###.#######.#####..##..#
.##.#.########..####.#.##...#.
########..##.##.##############
.####.######.##.#.####..##.#.#
.##.#...#.#.##...#.##..#..##.#

```