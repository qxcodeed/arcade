#include <iostream>

    // ++
class Vetor {
    int *u;  // ponteiro para dados
    int size; // tamanho do vetor
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
    int operator[] (int k) {
        return u[k];
        // $$
        // (void) k;
        // return 0;
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
// retorna o índice do vetor que tem o menor último elemento
int ind_menor_ultimo(Vetor U[], int n) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (U[i].empty()) {
            continue;
        }
        if (index == -1 || (U[i].back() < U[index].back())) {
            index = i;
        }
    }
    return index;
    // $$
    // (void) U;
    // (void) n;
    // return -1;
}

// junta todos os vetores em um só utilizando a seguinte lógica
// enquanto houver elementos em algum vetor
//     pegue o índice do vetor com o menor último elemento
//     adicione o último elemento desse vetor no resultado

Vetor mergeAll(Vetor U[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += U[i].len();
    }
    Vetor result(total);
    
    while (true) {
        int index = ind_menor_ultimo(U, n);
        if (index == -1) {
            break;
        }
        result.push_back(U[index].back());
        U[index].pop_back();
    }

    return result; 
    // $$
    // (void) U;
    // (void) n;
    // return Vetor(0);
}

/*
Exemplo

U = { [6,8,5], [3,2,1], [4,0,9] }

{ [6,8,5], [3,2], [4,0,9] } => {1}
{ [6,8,5], [3], [4,0,9] } => {1,2}
{ [6,8,5], [], [4,0,9] } => {1,2,3}
{ [6,8], [], [4,0,9] } => {1,2,3,5}
{ [6], [], [4,0,9] } => {1,2,3,5,8}
{ [], [], [4,0,9] } => {1,2,3,5,8,6}
{ [], [], [] } => {1,2,3,5,8,6,9,0,4}

*/

// #############################################
// MAIN COM O TESTE
// #############################################
// ==
int main() {
    Vetor U1 = {6,8,5}; // utilizando o construtor da lista de inicialização
    Vetor U2 = {3,2,1};
    Vetor U3 = {4,0,9};
    Vetor U[3] = {U1, U2, U3};

    // na hora que o mergeAll devolve o vetor, ele chama o construtor de cópia
    Vetor received = mergeAll(U, 3); 
    Vetor expected = {1,2,3,5,8,6,9,0,4};

    // para comparar, estamos utilizando o operador de igualdade
    if (received == expected) {
        std::cout << "Teste passou" << std::endl;
    } else {
        std::cout << "Teste falhou" << std::endl;
        // se falhou, vamos imprimir o que era esperado e o que foi recebido
        std::cout << "Esperado: " << expected.str() << std::endl;
        std::cout << "Recebido: " << received.str() << std::endl;
    }
    return 0;
}