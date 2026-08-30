# Altura e profundidade da árvore

<!-- toch -->
[Descrição](#descrição) | [Exemplos](#exemplos)
-- | --
<!-- toch -->

![_](assets/cover.jpg)

## Descrição

Dado o modelo de árvore utilizado nas questões anteriores, implemente os seguintes métodos.

```cpp
Node * find(int value); //retorna o nó dado o valor ou retorna null
int getAltura(Node * node);
int getProfundidade(Node * node);
```

- Entrada
  - linha 1: o serial de uma árvore
  - linha 2: uma lista de valores de nó
- Saída
  - Para cada nó da lista, um nó por linha, altura e profundidade do nó ou -1 se o nó não for encontrado

![_](assets/__altura.jpg)

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
4 # # 
4
======== EXPECT
Arvore:
4
Altura: 1, Profundidade: 1
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
1 # 0 # # 
0 1
======== EXPECT
Arvore:
╭───#
1
╰───0
Altura: 1, Profundidade: 2
Altura: 2, Profundidade: 1
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
4 # 8 2 # # # 
2 8 4
======== EXPECT
Arvore:
╭───#
4
│   ╭───2
╰───8
    ╰───#
Altura: 1, Profundidade: 3
Altura: 2, Profundidade: 2
Altura: 3, Profundidade: 1
<<<<<<<< FINISH
```
<!-- load -->
