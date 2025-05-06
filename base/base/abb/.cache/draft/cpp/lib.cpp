#include <iostream>

// Node: classe utilizada para representar um No
// Nao altere essa classe
struct Node {
    int info; // Informacao salva pelo usuario na arvore
    Node *left; // Ponteiro para o No filho a esquerda
    Node *right; // Ponteiro para o No filho a direita

    // Construtores
    Node(); 
    Node(int info, Node *left=NULL, Node *right=NULL);
    
    // Destrutor
    ~Node();
};

// Binary Search Tree ou
// Arvore de busca binaria
// Altere somente os campos marcados com TODO
struct BSTree {
    Node *root;   // Ponteiro para o No raiz da arvore

    BSTree() {
        root = NULL;
    }

    ~BSTree() { // Destrutor
        clear();
    }

    // Retorna o No da arvore que possui sua informacao igual a 'info',
    // ou retorna um No vazio (NULL) caso a arvore nao possua tal 'info'.
    Node* search(int info) {
        // TODO: Complexidade O(h), onde h = altura da arvore
        (void) info;
        return nullptr;
    }

    // Adiciona um elemento na arvore.
    // Esse novo elemento deve ser inserido no lugar
    // de um No vazio e ao mesmo tempo respeitar as propriedades
    // de uma arvore binaria de busca. 
    // info: informacao do elemento a ser inserido
    void insert(int info) {
        // TODO: Complexidade O(h), onde h = altura da arvore
        (void) info;
        return;
    }
    /*
        Exemplo:

           T =   40
                /  \
               20  70
              /  \
             10  30

        T.insert(90)

           T =   40
                /  \
               20  70
              /  \   \
             10  30  90
    */


    // Retorna a quantidade de elementos da arvore.
    int size() {
        // TODO: Complexidade O(n)
        return 0;
    }
    // Retorna o menor elemento da arvore, ou -1 caso nao exista
    int min() {
        // TODO: Complexidade O(h), onde h = altura da arvore
        return -1;
    }


    // Retorna o maior elemento da arvore, ou -1 caso nao exista
    int max() {
        // TODO: Complexidade O(h), onde h = altura da arvore
        return -1;
    }

    // Deixa a lista vazia, com zero elementos
    void clear() {
        _clear(root);
        root = nullptr;
    }

    void _clear(Node* current) {
        if(current == nullptr) return;
        _clear(current->left);
        _clear(current->right);
        delete current;
    }

    // Devolve true se vazia e false caso contrario
    bool empty() {
        return root == nullptr;
    }

    // Printa as informacoes da lista
    void print() {
        std::cout << "BSTree: ";
        _print(root);
        std::cout << std::endl;
    }

    void _print(Node *current) {
        if(current != nullptr) {
            std::cout << "Node-" << current->info << "{(";
            _print(current->left);
            std::cout << ", ";
            _print(current->right);
            std::cout << ")}";
        }
    }
};
