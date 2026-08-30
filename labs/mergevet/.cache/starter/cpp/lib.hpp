#include <iostream>

class Vetor {
    int *u {nullptr};  // ponteiro para dados
    int size {0}; // tamanho do vetor
public:
    // construtor base
    Vetor(int n) {
        u = new int[n];
        size = 0;
    }

    // deletar o vetor u
   ~Vetor() {
        delete [] u; 
    }

    // retornar o elemento k do vetor
    int& operator[] (int k) {
        return u[k];
    } 

    int len() { return size; }

    // ####################################
    // Métodos para você fazer
    // ####################################

    // permite inicializar assim Vetor V = {1,2,3};
    // uma lista de inicialização é um conjunto de elementos entre chaves
    // ele tem um método size() que retorna o tamanho da lista
    // e também pode ser percorrido com um for(int elem : v)
    //
    // inicie o vetor com o tamanho da lista
    // e copie os elementos da lista para o vetor
    // inicialize size adequadamente
    Vetor(std::initializer_list<int> v) {
        (void) v;
    }

    // se não tiver o construtor de cópia para estruturas dinâmicas
    // quando fazemos uma atribuição, o ponteiro é copiado e não o conteúdo
    // e você terá um erro de double free
    //
    // inicie u com o tamanho de V
    // inicie size com o tamanho de V
    // copie os elementos de V para u
    Vetor(const Vetor& V) {
        (void) V;
    }

    bool empty() {
        // retorne se o vetor está vazio
        return false;
    } 

    // retorne o valor do último elemento valido
    int back() {
        return 0;
    }
    
    // diminua o tamanho do vetor
    void pop_back() {
    }

    // adicione x no final do vetor
    // aumente o tamanho do vetor
    void push_back(int x) {
        (void) x;
    }

    // vai lhe ajudar se você quiser fazer debug e imprimir o vetor
    std::string str() {
        return "";
    }

    // verificar se dois vetores são iguais
    bool operator==(Vetor& V) {
        (void) V;
        return false;
    }
};


//####################################
// METODOS DO ALUNO
//####################################

// Esta função funde os n vetores na entrada U 
// num vetor de saída . Note que se os vetores 
// em U são ordenados então o vetor de saída 
// também o será. Porém mantenha em mente 
// que as entradas em U NÃO são necessariamente 
// ordenadas nos casos de testes.     

// U = { [6,8,5], [3,2,1], [4,0,9] }

// { [6,8,5], [2,1], [4,0,9] } => {3}
// { [6,8,5], [1], [4,0,9] } => {3,2}
// { [6,8,5], [], [4,0,9] } => {3,2,1}
// { [6,8,5], [], [0,9] } => {3,2,1,4}
// { [6,8,5], [], [9] } => {3,2,1,4,0}
// { [8,5], [], [9] } => {3,2,1,4,0,6}
// { [5], [], [9] } => {3,2,1,4,0,6,8}
// { [], [], [9] } => {3,2,1,4,0,6,8,5}
// { [], [], [] } => {3,2,1,4,0,6,8,5,9}

// Exemplo 2

// U = { [1,3,5], [2,4,6], [7,8,9] }

// { [3,5], [2,4,6], [7,8,9] } => {1}
// { [3,5], [4,6], [7,8,9] } => {1,2}
// { [5], [4,6], [7,8,9] } => {1,2,3}
// { [5], [6], [7,8,9] } => {1,2,3,4}
// { [], [6], [7,8,9] } => {1,2,3,4,5}
// { [], [], [7,8,9] } => {1,2,3,4,5,6}
// { [], [], [8,9] } => {1,2,3,4,5,6,7}
// { [], [], [9] } => {1,2,3,4,5,6,7,8}
// { [], [], [] } => {1,2,3,4,5,6,7,8,9}


// qual dos vetores tem o menor elemento na posicao ind
// se ind == tamanho do vetor, então o vetor está vazio
inline int ind_menor_primeiro(Vetor U[], int n, Vetor ind) {
    (void) U;
    (void) n;
    (void) ind;
    return -1;
}

// calcule o tamanho do vetor final e inicie ele
// inicie um vetor de indices com o para guardar o indice de cada vetor
// enquanto houver elementos
//     ache o menor elemento entre os vetores
//     adicione o menor elemento no vetor final
//     incremente o indice do vetor que tinha o menor elemento
inline Vetor mergeAll(Vetor U[], int n) {
    (void) U;
    (void) n;
    return Vetor(0);
}
