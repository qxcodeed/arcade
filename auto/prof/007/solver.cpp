#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef pair<size_t, size_t> Pos;

vector<Pos> get_neib(Pos p){
	vector<Pos> neib(4, p);
	neib[0].first--;
	neib[1].first++;
	neib[2].second--;
	neib[3].second++;
	return neib;
}

bool inside(vector<string> &mat, Pos p){
	if(p.first < 0 || p.first >= mat.size())
		return false;
	if(p.second < 0 || p.second >= mat[0].size())
		return false;
	return true;
}

void queimar(vector<string> &mat, size_t l, size_t c){
	list<Pos> pilha;
	if(mat[l][c] != '#')
		return;
	mat[l][c] = 'o';
	pilha.push_back(make_pair(l, c));
	while(!pilha.empty()){
		auto top = pilha.back();
		vector<Pos> toburn;
		for(auto neib : get_neib(top)){
			if(inside(mat, neib) && (mat[neib.first][neib.second] == '#')){
				toburn.push_back(neib);
				break;
			}
		}
		if(!toburn.empty()){
			auto neib = toburn.front();
			mat[neib.first][neib.second] = 'o';
			pilha.push_back(neib);
		}else{
			pilha.pop_back();
		}
	}
}


int main()
{
    int nl, nc, l, c;
    cin >> nl >> nc >> l >> c;

    vector<string> mat(nl, string(nc, ' '));
    for(int i = 0; i < nl; i++)
        cin >> mat[i];

    queimar(mat, l, c);
	for(string line : mat)
		cout << line << "\n";
    return 0;
}

