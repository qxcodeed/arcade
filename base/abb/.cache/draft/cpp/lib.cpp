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
        //DEL!
        Node* current = this->root;

        while(current != nullptr) {
            if(current->info == info) {
                return current;
            } else if(current->info > info) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return nullptr;
        //ACT!
        // (void) info;
        // return nullptr;
        //ADD!
    }

    // Adiciona um elemento na arvore.
    // Esse novo elemento deve ser inserido no lugar
    // de um No vazio e ao mesmo tempo respeitar as propriedades
    // de uma arvore binaria de busca. 
    // info: informacao do elemento a ser inserido
    void insert(int info) {
        // TODO: Complexidade O(h), onde h = altura da arvore
        //DEL!
        if(this->empty()) {
            this->root = new Node(info);
        }

        Node* current = this->root;
        Node* parent = nullptr;

        while(current != nullptr) {
            parent = current;
            if(current->info > info) {
                current = current->left;
            } else if(current->info < info) {
                current = current->right;
            } else {
                return;
            }
        }

        if(parent->info > info) {
            parent->left = new Node(info);
        } else {
            parent->right = new Node(info);
        }
        //ACT!
        // (void) info;
        // return;
        //ADD!
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
        //DEL!
        if (this->empty()) return 0;
        return _size(this->root);
        //ACT!
        // return 0;
        //ADD!
    }
    //DEL!
    int _size(Node* current) {
        if(current == nullptr) return 0;
        return _size(current->left) + _size(current->right) + 1;
    }
    //ADD!
    // Retorna o menor elemento da arvore, ou -1 caso nao exista
    int min() {
        // TODO: Complexidade O(h), onde h = altura da arvore
        //DEL!
        if(this->empty()) return -1;

        Node* current = this->root;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current->info;
        //ACT!
        // return -1;
        //ADD!
    }


    // Retorna o maior elemento da arvore, ou -1 caso nao exista
    int max() {
        // TODO: Complexidade O(h), onde h = altura da arvore
        //DEL!
        if(this->empty()) return -1;

        Node* current = this->root;

        while(current->right != nullptr) {
            current = current->right;
        }

        return current->info;
        //ACT!
        // return -1;
        //ADD!
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

