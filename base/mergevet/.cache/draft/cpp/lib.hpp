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
        //DEL!
        u = new int[v.size()];
        size = 0;
        for (int x : v) {
            this->push_back(x);
        }
        //ACT!
        // (void) v;
    }

    // se não tiver o construtor de cópia para estruturas dinâmicas
    // quando fazemos uma atribuição, o ponteiro é copiado e não o conteúdo
    // e você terá um erro de double free
    //
    // inicie u com o tamanho de V
    // inicie size com o tamanho de V
    // copie os elementos de V para u
    Vetor(const Vetor& V) {
        //DEL!
        u = new int[V.size];
        size = V.size;
        for (int i = 0; i < size; i++) {
            u[i] = V.u[i];
        }
        //ACT!
        // (void) V;
    }

    bool empty() {
        //DEL!
        return size == 0;
        //ACT!
        // retorne se o vetor está vazio //ADD!
        // return false;
    } 

    // retorne o valor do último elemento valido
    int back() {
        //DEL!
        return u[size - 1];
        //ACT!
        // return 0;
    }
    
    // diminua o tamanho do vetor
    void pop_back() {
        //DEL!
        size--;
    }

    // adicione x no final do vetor
    // aumente o tamanho do vetor
    void push_back(int x) {
        //DEL!
        u[size] = x;
        size++;
        //ACT!
        // (void) x;
    }

    // vai lhe ajudar se você quiser fazer debug e imprimir o vetor
    std::string str() {
        //DEL!
        std::string s = "[";
        for (int i = 0; i < size; i++) {
            s += i == 0 ? "" : ",";
            s += std::to_string(u[i]);
        }
        s += "]";
        return s;
        //ACT!
        // return "";
    }

    // verificar se dois vetores são iguais
    bool operator==(Vetor& V) {
        //DEL!
        if (size != V.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (u[i] != V.u[i]) {
                return false;
            }
        }
        return true;
        //ACT!
        // (void) V;
        // return false;
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
    //DEL!
    int menor = -1;
    for (int i = 0; i < n; i++) {
        if (ind[i] < U[i].len()) {
            if (menor == -1 || U[i][ind[i]] < U[menor][ind[menor]]) {
                menor = i;
            }
        }
    }
    return menor;
    //ACT!
    // (void) U;
    // (void) n;
    // (void) ind;
    // return -1;
}

// calcule o tamanho do vetor final e inicie ele
// inicie um vetor de indices com o para guardar o indice de cada vetor
// enquanto houver elementos
//     ache o menor elemento entre os vetores
//     adicione o menor elemento no vetor final
//     incremente o indice do vetor que tinha o menor elemento
inline Vetor mergeAll(Vetor U[], int n) {
    //DEL!
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
    //ACT!
    // (void) U;
    // (void) n;
    // return Vetor(0);
}
