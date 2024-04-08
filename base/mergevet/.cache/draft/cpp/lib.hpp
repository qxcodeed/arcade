#include <iostream>

class Vetor {
    int *u;  // ponteiro para dados
    int size; // tamanho do vetor
public:
    // construtor base
    Vetor(int n) {
        (void) n;
        // inicie u com n posições usando new
        // size deve ser 0
    }
   ~Vetor() { 
        // deletar o vetor u

    }
    int& operator[] (int k) {
        (void) k;
        return (int){0};
        // retornar o elemento k do vetor
    } 

    int len() { return size; }

    // ####################################
    // metodos para você fazer
    // ####################################

    // permite inicializar assim Vetor V = {1,2,3};
    // Uma lista de inicialização é um conjunto de elementos entre chaves
    // ele tem um método size() que retorna o tamanho da lista
    // e também pode ser percorrido com um for(int elem : v)
    Vetor(std::initializer_list<int> v) {
        (void) v;
        // inicie o vetor com o tamanho da lista
        // e copie os elementos da lista para o vetor
        // inicialize size adequadamente
    }

    // se não tiver o construtor de cópia para estruturas dinâmicas
    // quando fazemos uma atribuição, o ponteiro é copiado e não o conteúdo
    // e você terá um erro de double free
    Vetor(const Vetor& V) {
        (void) V;
        // inicie u com o tamanho de V
        // inicie size com o tamanho de V
        // copie os elementos de V para u
    }

    bool empty() {
        return 0;
        // retorne se o vetor está vazio
    } 
    int back() {
        return 0;
        // retorne o valor do último elemento valido
    }
    void pop_back() {
        // diminua o tamanho do vetor
    }
    void push_back(int x) {
        (void) x;
        // adicione x no final do vetor
        // aumente o tamanho do vetor
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
// retorna o índice do vetor que tem o menor último elemento
inline int ind_menor_ultimo(Vetor U[], int n) {
    (void) U;
    (void) n;
    return -1;
}

// Função merge
// Junta todos os vetores em um só utilizando a seguinte lógica
// enquanto houver elementos em algum vetor
//     pegue o índice do vetor com o menor último elemento
//     adicione o último elemento desse vetor no resultado

// Exemplo

// U = { [6,8,5], [3,2,1], [4,0,9] }

// { [6,8,5], [3,2], [4,0,9] } => {1}
// { [6,8,5], [3], [4,0,9] } => {1,2}
// { [6,8,5], [], [4,0,9] } => {1,2,3}
// { [6,8], [], [4,0,9] } => {1,2,3,5}
// { [6], [], [4,0,9] } => {1,2,3,5,8}
// { [], [], [4,0,9] } => {1,2,3,5,8,6}
// { [], [], [] } => {1,2,3,5,8,6,9,0,4}

inline Vetor mergeAll(Vetor U[], int n) {

    (void) U;
    (void) n;
    return Vetor(0);
}


