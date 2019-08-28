## @4.2 Labirinto Resolvendo com recursão      #todo
## @qxcode

fazer os testes.
Usa  o modelo do flood fill para passar início e fim
- pedir um vetor com os pontos do caminho
- pedir pedir matriz marcada com a saída
- sugerir funcao que retorne uma lista com o caminho
    - no algoritmo de pilha, a pilha já é o caminho
    - na recursão, a pilha recursiva já é o caminho
- pedir o vetor de pontos, para forçar retornar a lista
- dar estrutura básica de 
    - carregar matriz
    - funcao de gerar os vizinhos
    - struct LC com construtor
- Colocar testes
- Pode ser resolvido
    - recursivo
    - pilha
    - fila

```c
list<LC> find_path(bool * mat, int nl, int nc, LC first, LC last);
```