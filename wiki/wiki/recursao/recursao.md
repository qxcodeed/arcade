# Recursividade

![boneca russa](boneca.jpeg)

## O que é Recursividade?

Recursividade é uma técnica de programação onde uma função chama a si mesma para resolver um problema. Essa abordagem é útil para problemas que podem ser divididos em subproblemas menores de natureza similar.

## Como Funciona?

Uma função recursiva deve ter duas partes essenciais:

1. Caso Base: A condição que para a recursão. É a situação em que a função retorna um valor sem fazer uma chamada recursiva.

2. Chamada Recursiva: A parte da função que chama a si mesma com argumentos modificados, aproximando-se do caso base.

### Exemplo Simples: Fatorial

O cálculo do fatorial de um número é um exemplo clássico de recursividade. O fatorial de n (denotado como n!) é o produto de todos os números inteiros positivos até n. Matematicamente, é definido como:

- 0! = 1
- n! = n * (n-1)! para n > 0

### Algoritmo iterativo

```python
def fatorial(n):
  fatorial = 1

  while n > 1:
    fatorial = fatorial * n
    n = n - 1
      
  return fatorial
```

Nessa abordagem nós percorremos todos os números entre 1 e n. Isso ocorre por meio do decremento da variável 'n' a cada iteração. A cada repetição no loop, o resultado da multiplicação é atualizado na variável 'fatorial', que seguirá até que 'n' assuma valor igual a 1. Ao final desse processo retornaremos n!.

### Algoritmo recursivo

A implementação recursiva em Python seria:

```python
def fatorial(n):
  if n == 0:
    return 1  # Caso Base
  return n * fatorial(n - 1) # Chamada Recursiva
```

Da mesma forma do algoritmo iterativo, percorremos todos os números entre 1 e n, porém esse percurso é feito a cada chamada recursiva. O resultado das multiplicações são retornados gradativamente no encerramento de cada chamada, obtendo n! apenas ao fim da chamada original.

### Exemplo

Vamos calcular 3! usando a função recursiva:

1. `fatorial(3)` chama `fatorial(2)`
2. `fatorial(2)` chama `fatorial(1)`
3. `fatorial(1)` chama `fatorial(0)`
4. `fatorial(0)` retorna `1` (caso base)
5. `fatorial(1)` retorna `1 * 1 = 1`
6. `fatorial(2)` retorna `2 * 1 = 2`
7. `fatorial(3)` retorna `3 * 2 = 6`

## Conclusão

A recursividade é uma técnica de programação poderosa que nos permite resolver problemas dividindo-os em partes menores e similares. No exemplo do cálculo do fatorial, vimos como uma função pode chamar a si mesma para resolver um problema de maneira eficiente. Isso nos ajuda a escrever código mais organizado e claro para lidar com problemas complexos.
