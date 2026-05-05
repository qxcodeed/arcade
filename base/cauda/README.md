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

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
test_has_info
======== EXPECT
TESTE has_info
[30 -> 20 -> 15 -> 10]
has_info -1 == 0
has_info 0 == 0
has_info 5 == 0
has_info 10 == 1
has_info 15 == 1
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
test_push_front
======== EXPECT
TESTE push_front
push_front 10
push_front 15
push_front 20
push_front 30
Esperado: [30 -> 20 -> 15 -> 10]
[30 -> 20 -> 15 -> 10]
4 Nos alocados
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
test_push_back
======== EXPECT
TESTE push_back
push_back 10
push_back 15
push_back 20
push_back 30
Expected: [10 -> 15 -> 20 -> 30]
[10 -> 15 -> 20 -> 30]
<<<<<<<< FINISH
```
<!-- load -->
