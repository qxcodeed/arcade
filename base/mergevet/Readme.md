# L2 - @mergevet - Criando um vetor simples e fazendo um merge

- Nessa atividade você vai aprender sobre

- Construtor de cópia
- Lista de inicialização
- Operador de igualdade
- Métodos no vetor

Essa atividade ainda não tem os testes, você pode rodar o único caso de teste executando a main.

## Guide

- Você deve implementar os métodos da biblioteca `lib.hpp`.
- Na classe `main.cpp` estão todos os casos de teste.
- Sugiro implementar os métodos na ordem sugerida no `main.cpp`.

<!-- links .cache/draft -->
- cpp
  - [lib.hpp](.cache/draft/cpp/lib.hpp)
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

## Testes

```bash
>>>>>>>>
1
========
Criando vetor com capacidade 4
size: 0
<<<<<<<<

>>>>>>>>
2
========
Adicionando 1,2,3,0 usando push back
Esperado: [1,2,3,0]
Recebido: [1,2,3,0]
Elemento 2: 3
Mudando elemento 2 para 5
Esperado: [1,2,5,0]
Recebido: [1,2,5,0]
<<<<<<<<

>>>>>>>>
3
========
Criando vetor com lista de inicialização {1,2,3}
Esperado: [1,2,3]
Recebido: [1,2,3]
Criando vetor com cópia do anterior
Esperado: [1,2,3]
Recebido: [1,2,3]
<<<<<<<<

>>>>>>>>
4
========
Criando vetor v1 {4,5,1}
Criando vetor v2 {4,5,1,7}
Fazendo v1 == v2
Esperado: 0
Recebido: 0
Fazendo pop_back em v2
Fazendo v1 == v2
Esperado: 1
Recebido: 1
<<<<<<<<

>>>>>>>>
5
========
Inicializando vetores va, vb e vc
Criando vetor va {6,8,5}
Criando vetor vb {3,2,1}
Criando vetor vc {4,0,9}
Fazendo merge
Esperado: [3,2,1,4,0,6,8,5,9]
Recebido: [3,2,1,4,0,6,8,5,9]
<<<<<<<<

```
