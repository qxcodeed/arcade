# Conjunto usando Lista Sequencial Ordenada

- Conjuntos normalmente são implementados com tabelas hash ou árvores.
- Mas vamos implementar um conjunto usando uma lista sequencial ordenada.
- A lista sequencial ordenada é uma lista que mantém os elementos em ordem crescente sem repetição.
- Vamos ter um custo de O(n) para inserção pela necessidade de deslocar os elementos.
- Como os dados estão em um vetor ordenado, podemos fazer uma busca binária para encontrar o elemento.
- A busca binária tem um custo de O(log n).
- A remoção de um elemento também tem um custo de O(n) pela necessidade de deslocar os elementos.

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/setbuild/cover.jpg)

Implemente a classe do vetor dinâmico.

- Cada linguagem vai ter um arquivo `extra.md` com orientações sobre a implementação.
- Você deve criar a classe e implementar os métodos conforme as orientações.
- Depois de implementar um método, descomente e ajuste a entrada do método na função main.
- Implemente apenas os métodos necessários para passar no primeiro teste.
- Depois de passar no primeiro teste, implemente os métodos necessários para passar no segundo teste.
- Continue assim até passar em todos os testes.

- Os seguintes testes mostrar o comportamento esperado da classe para cada invocação de método.

## Drafts

<!-- links .cache/draft -->
- go
  - [extra.md](https://github.com/qxcodeed/arcade/blob/master/base/setbuild/.cache/draft/go/extra.md)
  - [main.go](https://github.com/qxcodeed/arcade/blob/master/base/setbuild/.cache/draft/go/main.go)
- java
  - [Main.java](https://github.com/qxcodeed/arcade/blob/master/base/setbuild/.cache/draft/java/Main.java)
  - [extra.md](https://github.com/qxcodeed/arcade/blob/master/base/setbuild/.cache/draft/java/extra.md)
<!-- links -->


## Testes

```bash
#__case insert
$init 1
$show
[]
$insert 3
$show
[3]
$insert 4
$show
[3, 4]
$insert 5
$show
[3, 4, 5]
$insert 1
$show
[1, 3, 4, 5]
$insert 2
$show
[1, 2, 3, 4, 5]
$insert 3
$show
[1, 2, 3, 4, 5]
$end
```

```bash
#__case contains
$init 10
$insert 10 2 8 12 6
$show
[2, 6, 8, 10, 12]
$contains 10
true
$contains 3
false
$end
```

```bash
#__case erase
$init 6
$insert 1 2 3 4 5 6
$show
[1, 2, 3, 4, 5, 6]
$erase 3
$show
[1, 2, 4, 5, 6]
$erase 1
$show
[2, 4, 5, 6]
$erase 8
value not found
$show
[2, 4, 5, 6]
$end
```
