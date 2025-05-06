#include "lib.h"

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
