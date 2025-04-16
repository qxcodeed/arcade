#include <iostream>
// Preencha os metodos faltantes.
// Os passos estao marcados com "TODO".

struct SequentialCircularList {
    int size;       // Numero de elementos na lista
    int maxSize;    // Capacidade maxima da lista
    int* arrayList; // Ponteiro para a lista de elementos na memoria 

    // Construtor
    SequentialCircularList(int maxSize){
        this->size = 0;
        this->maxSize = maxSize;
        this->arrayList = new int[maxSize];
    }

    // Destrutor
    ~SequentialCircularList(){
        delete arrayList;
        std::cout << "SequentialCircularList deleted" << std::endl;
    }

    // Retorna o valor do elemento na posicao 'index'
    // Como a lista e circular, nao ha limite para o tamanho
    // de 'index'.
    int get(int index){
        // TODO
        (void) index;
        return -1;
    }
    // Exemplos para a 'arrayList' = [1,2,3]
    // get(0) == 1
    // get(1) == 2
    // get(2) == 3
    // get(3) == 1
    // get(4) == 2
    // get(5) == 3
    // get(60) == 1
    // get(271) == 2
    // get(67583465) == 3
    
    void insert(int item){
        if(size == maxSize)
            return;
        arrayList[size] = item;
        size++;
    }

    // Remove elementos da lista
    void clear(){
        size = 0;
    }
};
