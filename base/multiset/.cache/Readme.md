# MultiSet usando vetor dinâmico

- Um MultiSet é um conjunto que permite a repetição de elementos.
  - Ele normalmente é implementado com uma tabela hash ou árvores.
  - Mas vamos implementar um MultiSet usando uma lista sequencial ordenada.
  - Um multiset é equivalente a um mapa\[chave, valor\] onde a chave é o elemento e o valor é a contagem de ocorrências do elemento.
- Inserção - O(n)
  - A lista sequencial ordenada é uma lista que mantém os elementos em ordem crescente e permite repetição de valores.
  - Vamos ter um vetor dinâmico que vai armazenar os elementos.
  - O vetor dinâmico vai ser redimensionado quando necessário.
  - O vetor dinâmico vai ter um tamanho inicial padrão.
  - Vamos ter um custo de O(n) para inserção pela necessidade de deslocar os elementos.
- Busca - O(log n)
  - Como os dados estão em um vetor ordenado, podemos fazer uma busca binária para encontrar o elemento.
  - A busca binária tem um custo de O(log n).
- Remoção - O(n)
  - A remoção de um elemento também tem um custo de O(n) pela necessidade de deslocar os elementos.
  - Como existe possibilidade de repetição, remover um elemento remove apenas uma ocorrência do elemento.
  - Se o elemento não existir, deve retornar uma mensagem de erro.
- Contagem - O(log n)
  - Retorna o número de ocorrências do elemento na lista.
  - Após encontrar o elemento com a busca binária, percorre a lista para contar as ocorrências.
- ContarDiferentes - O(n)
  - Retorna o número de elementos diferentes na lista.
  - Percorre a lista uma única vez e conta os elementos diferentes.
  - Observe que podemos utilizar o fato de o vetor estar ordenado para contar os elementos diferentes.

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/multiset/cover.jpg)

Implemente a classe do vetor dinâmico.

- Cada linguagem vai ter um arquivo `extra.md` com orientações sobre a implementação.
- Você deve criar a classe e implementar os métodos conforme as orientações.
- Depois de implementar um método, descomente e ajuste a entrada do método na função main.
- Implemente apenas os métodos necessários para passar no primeiro teste.
- Depois de passar no primeiro teste, implemente os métodos necessários para passar no segundo teste.
- Continue assim até passar em todos os testes.

- Os seguintes testes mostrar o comportamento esperado da classe para cada invocação de método.

## Testes

```bash
#__case insert and show with repetitions
$init 2
$insert 3 1 2 2 3 4 3
$show
[1, 2, 2, 3, 3, 3, 4]
$end
```

```bash
#__case contains true and false
$init 5
$insert 5 1 5 3
$show
[1, 3, 5, 5]
$contains 3
true
$contains 5
true
$contains 2
false
$end
```

```bash
#__case erase one occurrence at a time
$init 5
$insert 2 2 2 3
$show
[2, 2, 2, 3]
$erase 2
$show
[2, 2, 3]
$erase 2
$show
[2, 3]
$erase 2
$show
[3]
$erase 2
value not found
$end
```

```bash
#__case count
$init 5
$insert 1 2 2 2 3 3 4
$count 2
3
$count 3
2
$count 4
1
$count 5
0
$end
```

```bash
#__case unique
$init 10
$insert 5 5 5 1 2 2 3 3 3 3
$show
[1, 2, 2, 3, 3, 3, 3, 5, 5, 5]
$unique
4
$insert 4
$unique
5
$end
```

```bash
#__case clear
$init 3
$insert 1 1 2 3
$show
[1, 1, 2, 3]
$clear
$show
[]
$count 1
0
$unique
0
$end
```
