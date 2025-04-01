# Lista Duplamente Encadeada

Nesse exercício, implementaremos uma variação de lista encadeada: a Lista Duplamente Encadeada.

Uma lista duplamente encadeada é uma estrutura de lista semelhante a uma lista simplesmente encadeada, mas com uma diferença: cada nó contém um ponteiro para o próximo nó e outro ponteiro para o nó anterior. Dessa forma, podemos acessar o antecessor de um nó de forma simples e rápida.

Por simplicidade, implementaremos as informações dos Nós apenas como um inteiro.
No arquivo lib.cpp, se encontra a classe DLinkedList que possui os seguintes métodos:

- ~~DLinkedList();~~
- ~~\~DLinkedList();~~
- bool hasInfo(int info);
- ~~void push_front(int info);~~
- void push_back(int info);
- void pop_front(int info);
- void pop_back(int info);
- void remove_one(int info);
- ~~bool length();~~
- ~~void empty();~~
- ~~void print();~~

Métodos riscados já estão implementados, você precisa implementar os demais.

A funcionalidade de cada método está descrita em comentários no próprio arquivo lib.cpp. Sua tarefa é alterar o arquivo lib.cpp, implementando as funcionalidades faltantes citadas. Seu código deve passar no caso de teste para ser considerado correto.
OBS.: Não altere os métodos já implementados.OBS.2: Não precisa escrever a main(). Ela já está implementada internamente no Moodle.
