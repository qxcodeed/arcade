## ©04_list_ Inserir um nó no início de uma lista ligada

![](__capa.jpg)

Você recebe o ponteiro para o nó principal de uma lista ligada e um número inteiro para adicionar à lista. Crie um novo nó com o número inteiro especificado, insira esse nó no início da lista ligada e retorne o novo nó principal. O ponteiro do cabeçalho fornecido pode ser nulo, o que significa que a lista inicial está vazia.

#### Formato de entrada

A primeira linha contém um número inteiro , indicando o número de elementos a serem inseridos no início da lista. As próximas linhas contêm um número inteiro cada, indicando o elemento a ser inserido.

#### Formato de saída

Insira o novo nó na cabeça e returnna cabeça da lista ligada atualizada.

A saída é tratada pelo código no editor e é a seguinte:

Imprima os elementos da lista ligada da cabeça à cauda, cada um em uma nova linha.

#### Entrada de amostra

```
>>>>>>>> 00
5
383 484 392 975 321
========
[ 321 975 392 484 383 ]
<<<<<<<<
```

#### Explicação

```
Inicialmente a lista em NULL.

Após inserir 383, a lista é 383 -> NULL.

Após inserir 484, a lista é 484 -> 383 -> NULL.

Após inserir 392, a lista é 392 -> 484 -> 383 -> NULL.

Após inserir 975, a lista é 975 -> 392 -> 484 -> 383 -> NULL.

Após inserir 321, a lista é 321 -> 975 -> 392 -> 484 -> 383 -> NULL.

```

## Código inicial

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node * next;
    int value;
};

struct List{
    Node * head;
};

Node * list_push_front(Node * head, int value){
    //seu código aqui
}


List * list_create();
void   list_show(List * ll);
int main(){
    List * ll = list_create();
    int size;
    cin >> size;
    while(size--){
        int value;
        cin >> value;
        ll->head = list_push_front(ll->head, value);
    }
    list_show(ll);
}

List * list_create(){
    List * ll = new List();
    ll->head = nullptr;
    return ll;
}

void list_show(List * ll){
    Node * node = ll->head;
    cout << "[ ";
    while(node != nullptr){
        cout << node->value << " ";
        node = node->next;
    }
    cout << "]\n";
}
```
