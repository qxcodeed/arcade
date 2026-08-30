## L2 - Princesa Vector x List  #trabalho
## @qxcode

- Seu objetivo é implementar a princesa V1 em Vector e List e comparar o desempenho em ambos os algoritmos. 
- A lista é melhor que o vetor?
- Após fazer ambas as implementações e testar com os dados apresentados na descrição do problema faça:
    - retire os prints do vetor no meio do código. Deixe apenas a impressão do resultado final.
    - vá aumentando o tamanho de N e iniciando o dono da espada sempre na primeira posição.
- Sugestões
    - Altere seu código para usar `long` no lugar de int.
    - No vector utilize alocação dinâmica ao invés de estática para não ter segmentation fault.
    - Altere seus códigos para pegar os argumentos de argc e argv ao invés de ler no scanf
    - Use a função `time ./exec` para calcular o tempo de execução.
    - Você consegue estimar quanto tempo o algoritmo de vector com remoção faria 1KK elementos?

- Algoritmos
    - Vetor com Marçação
        - Inicialize um vetor com todos os elementos da lista de 1 até N
        - Percorra o vetor de forma circular
        - Coloque -1 como valor das posições que forem morrendo.
    - Vetor com Remoção
        - Inicialize um vetor com todos os elementos da lista de 1 até N
        - Percorra o vetor de forma circular.
        - Quando alguém morrer, sobrescreva a posição copiando todos os elementos à frente uma posição para trás e reduza o tamanho do vetor.
        - OBS: Cuidado com o caso onde o último elemento do vetor mata o primeiro, ele precisará de tratamento especial para não quebrar o percorrimento circular.
    - Lista
        - Cria uma lista ligada implementada manualmente ou usando uma estrutura como `list`.
        - Percorra a lista removendo os elementos.

## Sugestão de planilha que você deve montar

Tempo\ED  | vector marcação | lista         | vetor remoção
----------|-----------------|---------------|-------
50K       | 0.02            |  0.02         | 2 seg
100K      | 0.03            |  0.03         | 7 seg
200K      | 0.06            |  0.06         | 31 seg
1KK       | 0.3             |  0.2          | 
10KK      | 3.4             |  2.0          |
100KK     | 38.9            | 20.0          | 

