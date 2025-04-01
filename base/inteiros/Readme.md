# Lista Sequencial de Inteiros

Nesse exercício, implementaremos métodos de uma das estruturas mais simples porém mais utilizadas na programação: lista sequencial.

Uma lista sequencial, ou também lista linear ou vetor, é uma estrutura de dados que armazena elementos de forma contínua na memória. Cada elemento na lista pode ser acessado diretamente através de um índice, o que permite operações de acesso eficientes.

Por simplicidade, implementaremos uma lista sequencial de inteiros nesse exercício.

No arquivo **lib.cpp**, se encontra a classe **SequentialListInt** que possui os seguintes métodos métodos com cabeçalho, mas sem implementação:

- ~~SequentialListInt(int maxSize);~~
- ~~\~SequentialListInt()~~
- int get(int index);
- int getIndex(int item);
- void insertBack(int item);
- void insert(int item, int index);
- void removeBack();
- void remove(int index);
- void clear();
- int lenght();
- bool isEmpty();
- bool isFull();
- ~~void print();~~

A funcionalidade de cada método está descrita em comentários no próprio arquivo lib.cpp. Sua tarefa é alterar o arquivo lib.cpp, implementando as funcionalidades faltantes citadas. Seu código deve passar no caso de teste para ser considerado correto.

OBS: Não altere os métodos já implementados.
