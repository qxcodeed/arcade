## 00.3 Quando utilizar cada estrutura de dados?   #ready
## @qxcode

Pesquise e escreva um texto sobre quando utilizar cada uma das estruturas de dados apresentadas.

- Quando utilizar vector e quando utilizar list?
- Quando devo utilizar set no lugar de vector ou list?
- Quando devo utilizar um mapa?
- Qual a diferença entre uma mapa ou conjunto implementados sobre árvore ou sobre hash?


# Descrição

A forma como os elementos armazenados estão organizados em uma estrutura de dados determina diretamente o desempenho (de tempo e espaço) dessa estrutura. 

Pensando nisso, a nossa atividade consiste em analisar o desempenho de algumas estruturas quando realizamos operações de inserção, remoção e busca. 

A partir de um arquivo de entrada contendo valores e operações a serem realizadas sobre esses valores, meça o tempo que a implementação sobre cada estrutura (vetor, lista, árvore e etc) leva para processar o arquivo.

## Arquivo de entrada
Cada par ocupa uma linha do arquivo. As operações são representadas por um único caractere, onde:

- 'i' representa inserção, 
- 'r' representa remoção e 
- 's' representa busca. 

O valor é um número inteiro qualquer. Um exemplo de um trecho de arquivo de entrada pode ser visto abaixo.

```
i 666662
i 566772
s 566772
i 840981
r 566772
i 931128
r 666662
i 62706
r 4861
s 931128
s 929857
```

No exemplo, a primeira operação a ser realizada é inserir 666662 na estrutura, depois inserir 566772, buscar 566772 e seguem as demais operações sobre seus respectivos valores seguindo as regras já descritas.

Como restrição, desejamos que cada número seja inserido apenas se ele já não existir
na estrutura.

## Entrega

A sequência de operações presentes no arquivo de entrada deve ser aplicadas à três estruturas do C++: vector, list e set.

Para cada arquivo de entrada, deve ser contabilizado o tempo levou para realizar todas as operações. Ao final das simulações, escreva um relatório respondendo as seguintes perguntas:
1. Quanto tempo levou para cada estrutura processar cada um dos arquivos?
2. Houve uma diferença de desempenho entre as estruturas testadas?
3. Se houve, o que pode ter gerado essa diferença?

Conte também a quantidade de operações bem sucedidas.
1. Quantas inserções foram executadas com sucesso.
2. Quantas remoções foram executadas com sucesso.
3. Quantas buscas foram executadas com sucesso.

