# @lista_simples - Lista Simplesmente Encadeada

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/lista_simples/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed lista_simples`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

Nesse exercício, implementaremos nossa primeira estrutura encadeada: Lista Simplesmente Encadeada.

Uma lista simplesmente encadeada é uma estrutura de dados que consiste em uma sequência de elementos, onde cada elemento (chamado de Nó) contém dois componentes: uma informação do elemento e um ponteiro para o próximo Nó na sequência.

Por simplicidade, implementaremos as informações como apenas um inteiro.

No arquivo lib.cpp, se encontra a classe SLinkedList que possui os seguintes métodos:

- SLinkedList();
- ~SLinkedList();
- bool hasInfo(int info);
- int get(int index);
- int operator[](int index);
- void push_front(int info);
- void push_back(int info);
- ~~void pop_front();~~
- void pop_back();
- void clear();
- int length();
- bool empty();
- ~~Node\* sucessor(Node* node);~~
- Node\* predecessor(Node* node);
- ~~void print();~~

Métodos riscados já estão implementados, você precisa implementar os demais.
A funcionalidade de cada método está descrita em comentários no próprio arquivo lib.cpp. Sua tarefa é alterar o arquivo lib.cpp, implementando as funcionalidades faltantes citadas. Seu código deve passar no caso de teste para ser considerado correto.

OBS.: Não altere os métodos já implementados.

OBS.2: Não precisa escrever a main() nem alterar o arquivo main.cpp.

<!-- links .cache/draft -->
- cpp
  - [lib.cpp](https://github.com/qxcodeed/arcade/blob/master/base/lista_simples/.cache/draft/cpp/lib.cpp)
  - [main.cpp](https://github.com/qxcodeed/arcade/blob/master/base/lista_simples/.cache/draft/cpp/main.cpp)
<!-- links -->