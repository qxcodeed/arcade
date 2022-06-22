#include <set> //tree
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    set<int> data;
    bool sorted = false;
    int sucessos = 0;
    char op;
    while(cin >> op){
        int value;
        cin >> value;
        if(op == 'i'){
            if(data.find(value) != data.end()){
                sucessos++;
            }
        }
        if(op == 's'){
            if(!sorted){
                std::sort(data.begin(), data.end());
                sorted = true;
            }
            if(std::binary_search(data.begin(), data.end(), value))
                sucessos++;
        }
        if(op == 'r'){
            auto it = std::find(data.begin(), data.end(), value);
            if(it != data.end()){
                data.erase(it);
                sucessos++;
            }
        }
    }
    cout << sucessos << endl;
}