#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


typedef struct F2P{
    stack<int> stack1;
    stack<int> stack2;
}Fila;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, p, x;
    Fila fila;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>p;
        if(p==1){
            cin>>x;
            fila.stack1.push(x);
        }else if(fila.stack2.empty()){
            while(!(fila.stack1.empty())){
                fila.stack2.push(fila.stack1.top());
                fila.stack1.pop();
            }
        }if(!fila.stack2.empty()){
            if(p==2) fila.stack2.pop();
            if(p==3){
                cout<<fila.stack2.top();
                cout << endl;
            }
        }
    }
    return 0;
}
