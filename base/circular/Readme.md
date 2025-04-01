# Lista Sequencial Circular

Nesse exercício, implementaremos métodos de uma estrutura circular.

Teoricamente, uma lista circular consiste em uma lista original que é repetida infinitas vezes. Por exemplo: a seguinte lista linear [1,2,3] é convertida para a seguinte lista circular: [1,2,3,1,2,3,1,2,3,1,2,3,1,..].

Na prática, iremos salvar o vetor original e apenas modificar a forma na qual um elemento é acessoado pelo índice.

No arquivo lib.cpp, se encontra a classe SequentialSortedListInt que possui apenas o seguinte método com cabeçalho, mas sem implementação:

- int get(int index);

O método get simular uma lista circular para retornar o elemento correto. É possível implementar esse método com complexidade O(1).

A funcionalidade de cada método está descrita em comentários no próprio arquivo lib.cpp. Sua tarefa é alterar o arquivo lib.cpp, implementando as funcionalidades faltantes citadas. Seu código deve passar no único caso de teste para ser considerado correto.

OBS: Não altere os métodos já implementados.
