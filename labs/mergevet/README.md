# Criando um vetor simples e fazendo um merge

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

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
1
======== EXPECT
Criando vetor com capacidade 4
size: 0
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
2
======== EXPECT
Adicionando 1,2,3,0 usando push back
Esperado: [1,2,3,0]
Recebido: [1,2,3,0]
Elemento 2: 3
Mudando elemento 2 para 5
Esperado: [1,2,5,0]
Recebido: [1,2,5,0]
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
3
======== EXPECT
Criando vetor com lista de inicialização {1,2,3}
Esperado: [1,2,3]
Recebido: [1,2,3]
Criando vetor com cópia do anterior
Esperado: [1,2,3]
Recebido: [1,2,3]
<<<<<<<< FINISH
```
<!-- load -->
