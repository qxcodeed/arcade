#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> aparecem(queries.size(), 0);
    for(int i = 0; i < (int) queries.size(); i++)
        for(int j = 0; j < (int) strings.size(); j++)
            if(strings[j] == queries[i])
                aparecem[i]++;
    return aparecem;
}

int main(){
    int size;
    
    cin >> size;
    vector<string> base(size, "");
    for(int i = 0; i < size; i++)
        cin >> base[i];

    cin >> size;
    vector<string> consulta(size, "");
    for(int i = 0; i < size; i++)
        cin >> consulta[i];
    
    vector<int> res = matchingStrings(base, consulta);
    for(int i = 0; i < (int) res.size(); i++){
        if(i != 0)
            cout << " ";
        cout << res[i];
    }
    cout << "\n";
    return 0;
}