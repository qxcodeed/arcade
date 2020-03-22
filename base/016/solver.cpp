#include <iostream>
#include <sstream>
using namespace std;

#define PROF

struct Vector{
    int capacity;
    int size;
    int * data;
};

Vector * vector_create(int capacity){
    Vector * v = new Vector();
    v->capacity = capacity;
    v->size = 0;
    v->data = new int[capacity];
    return v;
}
void vector_destroy(Vector * vector){
    delete [] vector->data;
    delete vector;
}

void vector_add(Vector * vector, int value){
    if(vector->size < vector->capacity){
        vector->data[vector->size] = value;
        vector->size++;
    }
}

//retorne a string no formato 
// [ a b c ]
string vector_show(Vector * vector){
    stringstream ss;
    ss << "[ ";
    for(int i = 0; i < vector->size; i++)
        ss << vector->data[i] << " ";
    ss << "]";
    return ss.str();
}


/* NAO MEXA DAQUI PRA BAIXO */
int main(){
    string line, cmd;
    Vector * v = vector_create(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end")
            break;
        else if(cmd == "init"){
            int value;
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        }
        else if(cmd == "status"){
            cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        }
        else if(cmd == "add"){
            int value;
            while(ss >> value){
                vector_add(v, value);
            }
        }
        else if(cmd == "show"){
            cout << vector_show(v) << endl;
        }
    }
    vector_destroy(v);
}