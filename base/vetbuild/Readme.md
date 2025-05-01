# Lista Sequencial Dinâmica

- O vetor dinâmico é uma lista sequencial que pode crescer ou diminuir de tamanho conforme necessário.
- Ele é implementado com diferentes nomes dependendo da linguagem.
  - c não possui vetor dinâmico, mas pode ser implementado com ponteiros.
  - c++ usa `Vector`
  - go usa `slice`
  - python usa `list`
  - rust usa `Vec`
  - java usa `ArrayList`
  - javascript e typescript usam `Array`

![_](cover.jpg)

Implemente a classe do vetor dinâmico.

- Cada linguagem vai ter um arquivo `extra.md` com orientações sobre a implementação.
- Você deve criar a classe e implementar os métodos conforme as orientações.
- Depois de implementar um método, descomente e ajuste a entrada do método na função main.
- Implemente apenas os métodos necessários para passar no primeiro teste.
- Depois de passar no primeiro teste, implemente os métodos necessários para passar no segundo teste.
- Continue assim até passar em todos os testes.

- Os seguintes testes mostrar o comportamento esperado da classe para cada invocação de método.
- Cada linha que começa com `$` equivale a uma chamada de método.
- Cada #TEST_CASE separa um caso de teste diferente.

## Testes

```bash
#TEST_CASE create
$init 3
$status
size:0 capacity:3
$show
[]
$end
```

```bash
#TEST_CASE push
$init 1
$status
size:0 capacity:1
$show
[]
$push 3
$show
[3]
$status
size:1 capacity:1
$push 4
$show
[3, 4]
$status
size:2 capacity:2
$push 5
$show
[3, 4, 5]
$status
size:3 capacity:4
$push 1
$show
[3, 4, 5, 1]
$status
size:4 capacity:4
$push 2
$show
[3, 4, 5, 1, 2]
$status
size:5 capacity:8
$end
```

```bash
#TEST_CASE get e set
$init 10
$push 10 2 8 12 8 6
$show
[10, 2, 8, 12, 8, 6]
$get 2
8
$set 2 20
$show
[10, 2, 20, 12, 8, 6]
$get 10
index out of range
$set 10 20
index out of range
$show
[10, 2, 20, 12, 8, 6]
$end
```

```bash
#TEST_CASE clear
$init 6
$push 1 2 3 4 5 6
$clear
$show
[]
$status
size:0 capacity:6
$end
```

```bash
#TEST_CASE reserve
$init 6
$push 1 2 3 4 5 6
$show
[1, 2, 3, 4, 5, 6]
$reserve 10
$show
[1, 2, 3, 4, 5, 6]
$status
size:6 capacity:10
$end
```

```bash
#TEST_CASE pop
$init 5
$push 1 2 3 4 5
$show
[1, 2, 3, 4, 5]
$pop
$show
[1, 2, 3, 4]
$pop
$pop
$pop
$show
[1]
$status
size:1 capacity:5
$pop
$show
[]
$pop
vector is empty
$status
size:0 capacity:5
$end
```

```bash
#TEST_CASE insert
$init 6
$push 1 2 3 4 5
$insert 2 10
$show
[1, 2, 10, 3, 4, 5]
$status
size:6 capacity:6
$insert 0 20
$show
[20, 1, 2, 10, 3, 4, 5]
$status
size:7 capacity:12
$end
```

```bash
#TEST_CASE insert_resize
$init 6
$push 1 2 3 4 5 6
$insert 2 10
$show
[1, 2, 10, 3, 4, 5, 6]
$status
size:7 capacity:12
$end
```

```bash
#TEST_CASE erase
$init 6
$push 1 2 3 4 5 6
$show
[1, 2, 3, 4, 5, 6]
$erase 2
$show
[1, 2, 4, 5, 6]
$status
size:5 capacity:6
$erase 0
$show
[2, 4, 5, 6]
$status
size:4 capacity:6
$erase 8
index out of range
$status
size:4 capacity:6
$show
[2, 4, 5, 6]
$end
```

```bash
#TEST_CASE indexOf e contains
$init 10
$push 10 2 8 12 8 6
$indexOf 12
3
$indexOf 8
2
$indexOf 7
-1
$contains 12
true
$end
```
