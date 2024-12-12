#include <iostream>
#include <vector>
#include <climits>
#include <array>

using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int** cost = new int*[700];
    for (int i = 0; i < n; i++) {
        cost[i] = new int[700];
        for (int j = 0; j < n; j++) {
            cost[i][j] = INT_MAX / 4;
        }
    }
    for (int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }
    cin >> cost[0][1];
    cost[1][0] = cost[0][1];
    for (int c = 2; c < n; c++) {
        int d;
        cin >> d;
        while (d--) {
            int inp1, inp2;
            cin >> inp1 >> inp2;
            cost[c][inp1-1] = inp2;
            cost[inp1-1][c] = inp2;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = min(cost[i][j],
                cost[i][k] + cost[k][j]);
                cost[j][i] = cost[i][j];
            }
        }
        if (k >= 2) cout << cost[0][1] << " ";
    }
}