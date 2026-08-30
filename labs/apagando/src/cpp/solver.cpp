#include <bits/stdc++.h>

using namespace std;

int main(){
	
	vector<int> pessoas;
	int tam, saiP, igual, aux;
	
	cin>>tam;
	
	for( int i = 0; i < tam ;i++){
	    cin >> aux;
	    pessoas.push_back(aux);
	}	    
	
	cin >> saiP;
	
	for( int i = 0; i < saiP ;i++){
		
		cin >> igual;
		
		for( int k = 0; k < ((int)pessoas.size()) ;k++){
			if( igual == pessoas[k]){
			   pessoas.erase(pessoas.begin()+k);
				break;
			} 
		}
	}
	
	for( int i = 0; i < ((int)pessoas.size()) ;i++)
	    cout << pessoas[i] << " " ;
	cout << endl;
	return 0;
}