# Converte simples em dupla

Dada uma lista simplesmente encadeada, sua tarefa é implementar uma função que faça uma cópia dessa lista, mas convertendo-a para uma lista duplamente encadeada.
A struct SLinkedList::Node representa um nó de uma lista singular, que possui apenas a informação e um ponteiro para o próximo. A struct DLinkedList::Node representa um nó da lista duplamente encadeada, que possui ponteiros para o próximo e anterior.
Você deve implementar a função DLinkedList::Node* convertToDouble(SLinkedList::Node *head)

## Entrada

- Ponteiro para nó cabeça da lista simplesmente encadeada.

## Saída

- Retorna um ponteiro para uma nova lista duplamente encadeada, que possui as mesmas informações da lista original.
