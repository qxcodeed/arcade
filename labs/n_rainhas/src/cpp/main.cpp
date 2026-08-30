// @DROP
#include <iostream>
#include <vector>

using namespace std;

int totalSolutions = 0;

void solve(int n, int row, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
        totalSolutions++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (!col[c] && !diag1[row - c + n - 1] && !diag2[row + c]) {
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
            solve(n, row + 1, col, diag1, diag2);
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }
}

int countNQueensSolutions(int n) {
    totalSolutions = 0;
    vector<bool> col(n, false);
    vector<bool> diag1(2 * n - 1, false);  // '\' diagonals
    vector<bool> diag2(2 * n - 1, false);  // '/' diagonals

    solve(n, 0, col, diag1, diag2);
    return totalSolutions;
}



int main() {
    int n;
    cin >> n;

    int solutions = countNQueensSolutions(n);
    cout << solutions << endl;

    return 0;
}
