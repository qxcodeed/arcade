#include <iostream>

    // ++
class Vetor {
    int *u {nullptr};  // ponteiro para dados
    int size {0}; // tamanho do vetor
public:
    // construtor base
    Vetor(int n) {
        u = new int[n];
        size = 0;
        // $$
        // (void) n;
        // ==
        // inicie u com n posições usando new
        // size deve ser 0
    }
   ~Vetor() { 
        delete [] u; 
        // ==
        // deletar o vetor u

    }
    int& operator[] (int k) {
        return u[k];
        // $$
        // (void) k;
        // static int dummy = 0;
        // return dummy;
        // ==
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
        u = new int[v.size()];
        size = 0;
        for (int x : v) {
            this->push_back(x);
        }
        // $$
        // (void) v;
        // ==
        // inicie o vetor com o tamanho da lista
        // e copie os elementos da lista para o vetor
        // inicialize size adequadamente
    }

    // se não tiver o construtor de cópia para estruturas dinâmicas
    // quando fazemos uma atribuição, o ponteiro é copiado e não o conteúdo
    // e você terá um erro de double free
    Vetor(const Vetor& V) {
        u = new int[V.size];
        size = V.size;
        for (int i = 0; i < size; i++) {
            u[i] = V.u[i];
        }
        // $$
        // (void) V;
        // ==
        // inicie u com o tamanho de V
        // inicie size com o tamanho de V
        // copie os elementos de V para u
    }

    bool empty() {
        return size == 0;
        // $$
        // return 0;
        // ==
        // retorne se o vetor está vazio
    } 
    int back() {
        return u[size - 1];
        // $$
        // return 0;
        // ==
        // retorne o valor do último elemento valido
    }
    void pop_back() {
        size--;
        // ==
        // diminua o tamanho do vetor
    }
    void push_back(int x) {
        u[size] = x;
        size++;
        // $$
        // (void) x;
        // ==
        // adicione x no final do vetor
        // aumente o tamanho do vetor
    }

    // vai lhe ajudar se você quiser fazer debug e imprimir o vetor
    std::string str() {
        std::string s = "[";
        for (int i = 0; i < size; i++) {
            s += i == 0 ? "" : ",";
            s += std::to_string(u[i]);
        }
        s += "]";
        return s;
        // $$
        // return "";
    }

    // verificar se dois vetores são iguais
    bool operator==(Vetor& V) {
        if (size != V.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (u[i] != V.u[i]) {
                return false;
            }
        }
        return true;
        // $$
        // (void) V;
        // return false;
    }
};


//####################################
// METODOS DO ALUNO
//####################################
// ++

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
    int menor = -1;
    for (int i = 0; i < n; i++) {
        if (ind[i] < U[i].len()) {
            if (menor == -1 || U[i][ind[i]] < U[menor][ind[menor]]) {
                menor = i;
            }
        }
    }
    return menor;
    // $$
    // (void) U;
    // (void) n;
    // (void) ind;
    // return -1;
}

inline Vetor mergeAll(Vetor U[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += U[i].len();
    }
    Vetor result(total);
    // inicializando vetor de indices
    Vetor ind(n);
    for (int i = 0; i < n; i++) {
        ind.push_back(0);
    }
    // enquanto houver elementos
    while (true) {
        int index = ind_menor_primeiro(U, n, ind);
        if (index == -1) {
            break;
        }
        result.push_back(U[index][ind[index]]);
        ind[index]++;
    }
    return result; 
    // $$
    // (void) U;
    // (void) n;
    // return Vetor(0);
    // ==
    // calcule o tamanho do vetor final e inicie ele
    // inicie um vetor de indices com o para guardar o indice de cada vetor
    // enquanto houver elementos
    //     ache o menor elemento entre os vetores
    //     adicione o menor elemento no vetor final
    //     incremente o indice do vetor que tinha o menor elemento
}


