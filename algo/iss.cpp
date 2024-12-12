#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<vector<int>>dp (n + 1, vector(n + 1, 0));
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i][n] = 1;
        dp[i][1] = 1;
        dp[i][i-1] = 1;
        for (int j = 2; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }

    }
}