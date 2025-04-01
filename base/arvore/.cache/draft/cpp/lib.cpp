#include <iostream>

// Node: classe utilizada para representar um No
// Nao altere essa classe
struct Node {
    int info; // Informacao salva pelo usuario na arvore
    Node *left; // Ponteiro para o No filho a esquerda
    Node *right; // Ponteiro para o No filho a direita

    // Construtores
    Node(); 
    Node(int info, Node *left=nullptr, Node *right=nullptr);
    
    // Destrutor
    ~Node();
};

// Binary Search Tree ou
// Arvore de busca binaria
// Altere somente os campos marcados com TODO
struct BinaryTree {
    Node *root;   // Ponteiro para o No raiz da arvore

    BinaryTree() {
        root = nullptr;
    }

    ~BinaryTree() { // Destrutor
        clear();
    }

    // Retorna o No da arvore que possui sua informacao igual a 'info',
    // ou retorna um No vazio (NULL) caso a arvore nao possua tal 'info'.
    Node* search(int info) {
        // TODO: Complexidade O(n)
        //DEL!
        if(!this->empty()) {
            return _search(this->root, info);
        }

        return nullptr;
        //ACT!
        // (void) info;
        // return nullptr;
    }

    //DEL!
    Node* _search(Node *current, int info) {
        if (current == nullptr) {
            return nullptr;
        }

        if (current->info == info) {
            return current;
        }

        Node* foundInLeft = _search(current->left, info);
        if (foundInLeft != nullptr) {
            return foundInLeft;
        }

        // Se não foi encontrado na esquerda, chama para a subárvore direita
        return _search(current->right, info);
        }
    //ADD!

    // Cria um novo No com a informacao 'info' e o adiciona
    // a esquerda do No 'current'.
    // Pode assumir que o No esquerdo de 'current' esta vazio.
    void insert_left(Node *current, int info) {
        // TODO: Complexidade O(1)
        //DEL!
        Node* newNode = new Node(info);
        current->left = newNode;
        //ACT!
        // (void) info;
        // (void) current;
    }
    /*
        Exemplo:

           T =   12
                /  \
               50  34
                 \   \
                  3   10
                T.insert_left(No[50], 6)

           T =   12
                /  \
               50  34
              /  \   \
             6    3  10
    */

    
    // Cria um novo No com a informacao 'info' e o adiciona
    // a direita do No 'current'.
    // Pode assumir que o No direito de 'current' esta vazio.
    void insert_right(Node *current, int info) {
        // TODO: Complexidade O(1)
        //DEL!
        Node* newNode = new Node(info);
        current->right = newNode;
        //ACT!
        // (void) info;
        // (void) current;
    }
    /*
        Exemplo:

           T =   12
                /  \
               50  34
                 \   
                  3   
    
        T.insert_right(No[34], 10)

           T =   12
                /  \
               50  34
                 \   \
                  3  10
    */


    // Retorna a quantidade de elementos da arvore.
    int size() {
        // TODO: Complexidade O(n)
        //DEL!
        if(this->empty()) return 0;

        return _size(this->root);
        //ACT!
        // return 0;
    }

    int _size(Node *current) {
        if(current == nullptr) return 0;
        return _size(current->left) + _size(current->right) + 1;
    }


    // Retorna o menor elemento da arvore, ou -1 caso nao exista
    int min() {
        // TODO: Complexidade O(n)
        //DEL!
        if(this->empty()) return -1;

        return _min(this->root);
        //ACT!
        // return -1;
    }

    //DEL!
    int _min(Node *current) {
        if (current == nullptr) {
            return INT_MAX;
        }
        
        // Encontre o mínimo nas subárvores esquerda e direita
        int leftMin = _min(current->left);
        int rightMin = _min(current->right);
        
        // Retorne o menor valor entre o nó atual, o menor da esquerda e o menor da direita
        return std::min(current->info, std::min(leftMin, rightMin));
    }
    //ADD!

    // Retorna o maior elemento da arvore, ou -1 caso nao exista
    int max() {
        // TODO: Complexidade O(n)
        //DEL!
        if(this->empty()) return -1;

        return _max(this->root);
        //ACT!
        // return -1;
    }

    //DEL!
    int _max(Node *current) {
        if (current == nullptr) {
            return -1;
        }
        
        // Encontre o mínimo nas subárvores esquerda e direita
        int leftMax = _max(current->left);
        int rightMax = _max(current->right);
        
        // Retorne o maior valor entre o nó atual, o maior da esquerda e o maior da direita
        return std::max(current->info, std::max(leftMax, rightMax));
    }
    //ADD!

    // Deixa a lista vazia, com zero elementos
    void clear() {
        _clear(root);
        root = NULL;
    }

    void _clear(Node* current) {
        if(current == NULL) return;
        _clear(current->left);
        _clear(current->right);
        delete current;
    }

    // Devolve true se vazia e false caso contrario
    bool empty() {
        return root == NULL;
    }

    // Printa as informacoes da lista
    void print() {
        std::cout << "BinaryTree: ";
        _print(root);
        std::cout << std::endl;
    }

    void _print(Node *current) {
        if(current != NULL){
            std::cout << "Node-" << current->info << "{(";
            _print(current->left);
            std::cout << ", ";
            _print(current->right);
            std::cout << ")}";
        }
    }
};

