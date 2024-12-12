#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> table(n+1, (vector<int>(n+1, 0)));
    table[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                table[i][j] = 1;
                continue;
            }
            table[i][j] = table[i-1][j] + table[i-1][j-1];
        }
    }
    cout << table[n][k];
}