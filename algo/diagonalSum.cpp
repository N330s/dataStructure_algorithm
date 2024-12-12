#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> table(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }
    int mss = table[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            table[i][j] = max(table[i][j], table[i][j] + table[i-1][j-1]);
            mss = max(mss, table[i][j]);
        }
    }
    cout << mss;
}