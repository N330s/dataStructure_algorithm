#include <iostream>
#include <vector>
#include <climits>

using namespace std;
#define ll long long

int main () {
    int n;
    cin >> n;
    vector<vector<ll>> dist (n, vector<ll> (n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> dist[r][c];
            if (dist[r][c] == -1) dist[r][c] = INT_MAX;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll result = -1;
    for (int i = 1; i < n; i++) {
        if (dist[0][i] == INT_MAX) {
            cout << -1;
            return;
        }
        result = max(dist[0][i], result);
    }
    cout << result;
}