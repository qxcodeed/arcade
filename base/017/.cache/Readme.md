## @017 L2 - vector poo

![](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/017/cover.jpg)

Implemente as seguintes funções do vetor dinâmico.
- Ele deve ser iniciado utilizando alocação dinâmica e conter além do vetor de dados, `size` e `capacity` que definem o tamanho atual e a capacidade do vetor.
- Utilize o valgrind ao final para verificar se você desalocou corretamente todos os blocos de memória.

```bash
#__case create
$init 3
$status
size:0 capacity:3
$end
```

```bash
#__case add
$init 5
$show
[ ]
$add 3 4 5 1
$show
[ 3 4 5 1 ]
#__case tentar estourar

$add 7 3 2 1
$show
[ 3 4 5 1 7 ]
$end
```


## Código Base

```c++
#include <iostream>
#include <sstream>
using namespace std;

//double free corruption

struct Vector{
    int capacity {0}; //esse {} é o modo de inicializar default do c++ a partir do c++11
    int size {0};
    int * data {nullptr}; //inicializar pra não conter lixo

    Vector(int capacity){
        //inicialize this->capacity com capacity
        //inicialize this->size com size
        //crie memória dinamicamente para this->data com tamanho capacity
    }

    //como seu vector tem atritutos do tipo ponteiros, você precisa criar um
    //construtor de cópia e um operador de atribuição ou terá erros do tipo double-free

    //O operador de atribuição será invocado quando você fizer um Vector receber outro
    //Ex:
    //Vector vec(4);
    //vec = Vector(6);
    //nesse ponto, os atributos de this já foram inicializados, 
    //mas você precisa alterá-los para copiar os valores de other
    void operator = (const Vector& other){
        //inicialize this->capacity com other.capacity
        //inicialize this->size com other.size
        //se this->data não for nulo, devolva a memória com delete
        //crie nova memória para this->data do tamanho de other.capacity
        //copie os dados de other.data para this->data
    }

    //aqui você ensina seu vector a ser criado a partir de outro vector
    //Ex: 
    //Vector v(4);
    //Vector v2(v);
    Vector(Vector& other){
        //aqui você não precisa fazer nada, basta utilizar o operador de atribuição
        //que você já implementou
        *this = other;
    }
    ~Vector(){
        //devolta this->data
    }
    void add(int value){
        //se ainda couber, copia value para o novo valor
    }

    //esse é o toString do c++
    //tudo que enviar para os, é como se estivesse enviando para saída padrão
    //basta entender o funcionamento
    friend ostream& operator<<(ostream &os, Vector vector){
        os << "[ ";
        for(int i = 0; i < vector.size; i++)
            os << vector.data[i] << " ";
        os << "]";
        return os;
    }
};


/* NAO MEXA DAQUI PRA BAIXO */
int main(){
    string line, cmd;
    int value;
    Vector v(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            v = Vector(value);
        } else if(cmd == "status"){
            cout << "size:" << v.size << " capacity:" << v.capacity << "\n";
        } else if(cmd == "add"){
            while(ss >> value)
                v.add(value);
        } else if(cmd == "show"){
            cout << v << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}
```