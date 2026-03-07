# Lista Simplesmente Encadeada com Cauda

Nesse exercício, implementaremos lista simplesmente encadeada com uma pequena modificação: adição de um ponteiro para o nó cauda.
A lista encadeada com cauda consiste utilizar um ponteiro adicional que aponta para o último nó da lista (tail), além de apenas o ponteiro para o início da lista (head). Após cada operação, você pode manter o ponteiro para a cauda atualizado.
Por simplicidade, implementaremos as informações dos Nós apenas como um inteiro.
No arquivo lib.cpp, se encontra a classe SLinkedList que possui os seguintes métodos:

- ~~SLinkedList();~~
- ~~\~SLinkedList();~~
- bool hasInfo(int info);
- void push_front(int info);
- void push_back(int info);
- void pop_front(int info);
- void pop_back(int info);
- ~~void clear();~~
- ~~bool length();~~
- ~~void empty();~~
- ~~void print();~~

Métodos riscados já estão implementados, você precisa implementar os demais.
A funcionalidade de cada método está descrita em comentários no próprio arquivo lib.cpp. Sua tarefa é alterar o arquivo lib.cpp, implementando as funcionalidades faltantes citadas. Seu código deve passar no caso de teste para ser considerado correto.

OBS.: Não altere os métodos já implementados.

OBS.2: Não precisa escrever a main(). Ela já está implementada internamente no Moodle.
