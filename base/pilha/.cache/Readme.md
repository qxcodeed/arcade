# Pilha sobre uma lista sequencial

- A pilha é uma estrutura de dados linear que armazena elementos de forma ordenada, onde o último elemento adicionado é o primeiro a ser removido (LIFO - Last In First Out).
- A pilha pode ser implementada utilizando uma lista sequencial, onde os elementos são armazenados em um vetor e o topo da pilha é representado pelo último índice ocupado do vetor.
- A pilha possui duas operações principais: empilhar (push) e desempilhar (pop).
- A operação de empilhar adiciona um elemento ao topo da pilha, enquanto a operação de desempilhar remove o elemento do topo da pilha.
- Uma implementação eficiente da pilha pode ser efetuada sobre uma lista sequencial, por exemplo, a atividade [@vetbuild](https://github.com/qxcodeed/arcade/blob/master/base/pilha/../vetbuild/Readme.md).
- Nesse modelo, a pilha é apenas uma restrição dos métodos de acesso e manipulação da lista sequencial, ou seja, a pilha é uma lista sequencial com restrições.
- Para essa atividade, você deve implementar uma pilha utilizando uma lista sequencial, preferencialmente genérica, ou seja, que funcione para qualquer tipo de dado. A base por baixo da pilha é qualquer vetor dinâmico que sua linguagem já tenha implementado.
  - list em python
  - vector em C++
  - ArrayList em Java
  - slices em Go
- A pilha deve ter as seguintes operações:
  - Criar uma pilha vazia, com capacidade inicial: O(1).
  - Verificar se a pilha está vazia: O(1).
  - Empilhar um elemento, redimensionando o vetor se necessário: O(1) amortizado.
  - Desempilhar um elemento: O(1).
  - Obter o elemento do topo da pilha: O(1).
  - Obter o tamanho da pilha: O(1).
  - Limpar a pilha: O(1).
  - Gerar um texto com os elementos da pilha: O(n).
- Observações interessantes:
  - Diferente da lista sequencial, a pilha não deve ter um método de acesso direto aos elementos, ou seja, não deve ter um método que permita acessar um elemento em uma posição específica da pilha. A única forma de acessar os elementos da pilha é através das operações de empilhar e desempilhar.
  - Pilhas normalmente não possuem iteradores, métodos de busca ou percorrimento. O método toString aqui é apenas para debug e visualização do estado da pilha e normalmente não é disponibilizado em implementações reais de pilhas.

- Você encontrará orientações específicas de cada linguagem no arquivo `extra.md`.

## Shell

```bash
#TEST_CASE empilhar
# $init <capacidade>
$init 2
# show the current state of the stack, using _ for unused capacity
$debug
_, _
$push 1
$debug
1, _
$push 2
$debug
1, 2
$push 3
$debug
1, 2, 3, _
$end
```

```bash
#TEST_CASE desempilhar
$init 5
$push 5
$push 4
$push 3
$push 2
$push 8
$debug
5, 4, 3, 2, 8
$top
8
$size
5
$clear
$debug
_, _, _, _, _
$end
```

```bash
#TEST_CASE erros
$init 5
$pop
stack is empty
$top
stack is empty
$push 2
$push 8
$debug
2, 8, _, _, _
$pop
$debug
2, _, _, _, _
$pop
$debug
_, _, _, _, _
$pop
stack is empty
$end
```
