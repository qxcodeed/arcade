## 03.4 Mat  Gerando um matriz aleatória
## @qxcode

Vamos preencher uma matriz aleatoriamente com árvores `#` e espaços vazios `.`.

Leia do usuário utilizando os parâmetros de argv a quantidade de linhas e quantidade de colunas e a porcentagem de árvores.

Utilize a geração de números aleatórios para gerar sempre matrizes diferentes. Conte a quantidade de árvores que seu algoritmo está colocando e veja se se aproxima do que foi solicitado pelo usuário.

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