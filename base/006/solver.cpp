#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


typedef struct F2P{
    stack<int> armazem;
    stack<int> colheita;
}Fila;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_op, action, value;
    Fila fila;
    cin >> num_op;
    for(int i=0;i<num_op;i++){
        cin >> action;
        if(action == 1){
            cin >> value;
            fila.armazem.push(value);
            continue;
        }
        if(fila.colheita.empty()){
            while(!(fila.armazem.empty())){
                fila.colheita.push(fila.armazem.top());
                fila.armazem.pop();
            }
        }
        if(!fila.colheita.empty()){
            if(action==2)
                fila.colheita.pop();
            if(action==3)
                cout<< fila.colheita.top() << endl;
        }
    }
    return 0;
}
