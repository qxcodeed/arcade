#include <iostream>
// Preencha os metodos faltantes.
// Os passos estao marcados com "TODO".

struct SequentialSortedListInt {
    int size;       // Numero de elementos na lista
    int maxSize;    // Capacidade maxima da lista
    int* arrayList; // Ponteiro para a lista de elementos na memoria 

    // Construtor
    SequentialSortedListInt(int maxSize){
        this->size = 0;
        this->maxSize = maxSize;
        this->arrayList = new int[maxSize];
    }

    // Destrutor
    ~SequentialSortedListInt(){
        delete arrayList;
        std::cout << "SequentialSortedListInt deleted" << std::endl;
    }

    // Retorna o valor do elemento na posicao 'index'
    int get(int index){
        return arrayList[index];
    }

    // Se houver espaco na lista, insere o
    // elemento 'item' na posicao correta, ou seja,
    // o 'arrayList' deve permanecer ordenado (crescente)
    // apos a insercao. 
    void insert(int item){
        // TODO
        //DEL!
        if(size == maxSize){
            return;   
        }
        
        if(size == 0){
            arrayList[0] = item;
            size++;
            return;
        }
        
        int i = size-1;
        while(i >= 0 && arrayList[i] > item){
            arrayList[i+1] = arrayList[i];
            i--;
        }
        arrayList[i+1] = item;
        size++;

        //ACT!
        //(void) item;
    }

    // Retorna a quantidade de elementos unicos na lista.
    // Exemplo: A lista [1,2,2,3,3,3] possui 3 unicos. 
    int countUnique(){
        //TODO
        //DEL!
        int uniqueElement = 0;
        for(int i = 0; i < size; i++){
            if(arrayList[i] != arrayList[i+1]){
                uniqueElement++;
            }
        }
        return uniqueElement;

        //ACT!
        //return -1;
    }

    // Remove elementos da lista
    void clear(){
        size = 0;
    }

    // Printa elementos da lista
    void print(){
        std::cout << "[";
        for(int i = 0; i < size; i++){
            std::cout << arrayList[i];
            if(i != size-1)
                std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
};
