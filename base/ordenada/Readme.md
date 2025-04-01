# Lista Sequencial Ordenada

Nesse exercício, implementaremos métodos de uma estrutura ordenada.

Uma lista ordenada é uma estrutura similar à lista sequencial comum. Porém, após cada operação, os elementos são mantidos em uma ordem específica de acordo com os seus elementos vizinhos. Nesse exercício, utilizamos a ordem não decrescente, onde A[i-1] <= A[i] para todo i > 0.

No arquivo **lib.cpp**, se encontra a classe **SequentialSortedListInt** que possui os seguintes métodos métodos com cabeçalho, mas sem implementação:

- void insert(int item);
- bool countUnique();

O método insert deve inserir o novo elemento de tal forma que o vetor interno 'arrayList' permaneça ordenado após a inserção.

Ao implementar o método countUnique(), você pode aproveitar o fato da lista estar ordenada para fazer um algoritmo eficiente de complexidade O(n).

A funcionalidade de cada método está descrita em comentários no próprio arquivo lib.cpp. Sua tarefa é alterar o arquivo lib.cpp, implementando as funcionalidades faltantes citadas. Seu código deve passar no único caso de teste para ser considerado correto.

OBS: Não altere os métodos já implementados.
