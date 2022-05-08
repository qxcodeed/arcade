## TODO: Build Lista Simples

![](__capa.jpg)

Implementações de Lista Encadeada
==============================
Vamos trabalhar com implementações de listas simples e duplamente encadeadas, listas circulares. 

Compreender o funcionamento das **listas simples** é muito importante para nos preparar para trabalhar com árvores.

1. Listas Simples
_______________-
Implemente uma _Lista Encadeada Simples_ com os seguintes métodos e teste o funcionamento da sua implementação.

- criar
        #cria uma lista vazia
        criar()
        
        #cria uma lista a partir de outra
        #não utilize push_back
        #realize m O(N)
        clone(lista)
- inserir
        #insere na frente da lista
        void push_front(value)
        
        #insere no fim da lista
        void push_back(value)    
- destruir
        #destrutor ou equivalente
        destroy()
- remover
        #retira o no da frente
        void pop_front()
        
        #retira o no do fundo
        void pop_back()
 
        #retira e retorna o primeiro no com esse valor
        node remove(value)
- acessar
        #retorna o primeiro no ou nulo
        node front()
            
        #retorna o ultimo no ou nulo
        node back()
- visualizar
        #mostra a lista entre [ ]
        void print()
            
        #mostra lista ao contrario
        void reverse_print()    
- manipular
        #retorna se lista vazia
        bool is_empty()
            
        #se o valor existir retorne o no
        node find(value)
        
        #retorna o tamanho da lista
        int size()
            
        #verifica se duas listas são iguais
        bool equals(list_other)

2. Lista Simples Ordenada
_____________________--
Listas Ordenadas são muito práticas por facilitar a busca de elementos na lista.

Construa uma ListaSimplesOrdenada com os métodos da ListaSimples e as seguintes
modificações.

- Remover os métodos
        push_back(value)
        push_front(value)
- Adicionar os métodos
        #insere o valor de forma ordenado na lista.
        insert(value)  
- Mantenha todos os outros métodos fazendo adaptações quando necessário. Ex: o método find não precisa mais procurar em todos os elementos.

Nossa lista deve aceitar valores repetidos.
