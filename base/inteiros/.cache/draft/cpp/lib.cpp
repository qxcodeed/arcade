#include <iostream>
// Preencha os metodos faltantes.
// Os passos estao marcados com "TODO".

struct SequentialListInt {
    int size;       // Numero de elementos na lista
    int maxSize;    // Capacidade maxima da lista
    int* arrayList; // Ponteiro para a lista de elementos na memoria 

    // Construtor
    SequentialListInt(int maxSize){
        this->size = 0; 
        this->maxSize = maxSize;
        this->arrayList = new int [maxSize];
    }
    
    // Destrutor
    ~SequentialListInt(){
        delete arrayList;
        std::cout << "SequentialListInt deleted" << std::endl;
    }

    // Retorna o valor do elemento na posicao 'index'
    int get(int index){//O(1)
        // TODO: Retornar elemento na posicao 'index'
        //DEL!
        return arrayList[index];

        //ACT!
        //(void) index;
        //return -1;
    }

    // Retorna a posicao do primeiro elemento com valor igual a 'item'.
    // Caso o elemento nao exista na lista, retorna -1.
    int getIndex(int item){ // O(n) ou O(size)
        // TODO: Percorrer cada elemento do vetor e retornar caso encontre
        //       um elemento igual a 'item'.
        
        // TODO: Retornar -1 caso nao encontre o elemento.
        //DEL!
        for(int i = 0; i < size; i++){
            if(arrayList[i] == item){
                return i;
            }
        }
        return -1;

        //ACT!
        //(void) item;
        //return -1;
    }

    // Se houver espaco na lista, insere o
    // elemento 'item' no final da lista.
    void insertBack(int item){ // O(1)
        //DEL!
        if(size == maxSize)
            return;

        arrayList[size] = item;
        size++;

        //ACT!
        //(void) item;
    }

    // Se houver espaco na lista, insere o
    // elemento 'item' na posicao 'index' da lista
    void insert(int item, int index){ // O(n)
        // TODO: Verificar se a fila esta cheia.
        //       Se estiver, retorne!

        // TODO: Mova todos os elementos apos o
        //       'index' uma posicao para direita.
        
        // TODO: Atribua o valor de 'item' ao elemento
        //       na posicao 'index'.
        
        // TODO: Atualize o 'size'
        //DEL!
        if(size == maxSize){
            return;
        }
        for(int i = size; i > index; i--){
            arrayList[i] = arrayList[i - 1];
        }
        
        arrayList[index] = item;
        size++;

        //ACT!
        //(void) item;
        //(void) index;
    }

    // Se a lista nao estiver vazia,
    // remove o ultimo elemento.
    void removeBack(){ // O(1)
        //DEL!
        if(size == 0) return;
        size--;
    }

    // Se a lista nao estiver vazia,
    // remove elemento na posicao 'index'.
    void remove(int index){
        // TODO: Verificar se a fila esta vazia.
        //       Se estiver, retorne!
        
        // TODO: Mova todos os elementos apos o
        //       'index' uma posicao para esquerda.
        
        // TODO: Atualize o 'size'.
        //DEL!
        if(size == 0){
            return;
        }
        for(int i = index; i < size; i++){
            arrayList[i] = arrayList[i + 1];
        }
        size--;

        //ACT!
        //(void) index;
    }

    // Remove elementos da lista
    void clear(){
        // TODO: Atualize o 'size'.
        //DEL!
        size = 0;
    }

    // Retorna o tamanho da lista
    int lenght(){
        //DEL!
        return size;

        //ACT!
        //return -1;
    }

    bool isEmpty(){
        // TODO: Retorne true quando a lista nao possui elementos.
        //DEL!
        if(size == 0){
            return true;
        }
        return false;

        //ACT!
        //return false;
    }

    bool isFull(){
        // TODO: Retorne true quando a quantidade de elementos esta no maximo.
        //DEL!
        if(size == maxSize){
            return true;
        }
        
        return false;

        //ACT!
        //return false;
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
