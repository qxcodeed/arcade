# Mostrando a árvore formatada

<!-- toch -->
[Descrição](#descrição) | [Exemplos](#exemplos)
-- | --
<!-- toch -->

![_](assets/cover.jpg)

## Descrição

- Compare duas árvores binárias e retorne se a primeira é menor, maior ou igual à segunda.
- Utilize a seguinte estratégia:
- Percorra simultaneamente ambas as árvores (DFS):
  - compare valor do nó atual;
  - se diferentes, retorna imediatamente (< ou >);
  - se iguais, prossiga para a subárvore esquerda, depois direita;
  - se nenhuma diferença e ambas terminam null ao mesmo tempo: são iguais.

- Saída:
  - `menor` se a primeira árvore for menor que a segunda;
  - `maior` se a primeira árvore for maior que a segunda;
  - `iguais` se ambas forem iguais.
  
## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
4 # # 
4 # # 
======== EXPECT
4
4
iguais
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
1 # 0 # # 
1 # 1 # # 
======== EXPECT
╭───#
1
╰───0
╭───#
1
╰───1
menor
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
1 # 2 # # 
1 # 1 # # 
======== EXPECT
╭───#
1
╰───2
╭───#
1
╰───1
maior
<<<<<<<< FINISH
```
<!-- load -->
