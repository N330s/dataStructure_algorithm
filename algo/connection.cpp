#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

//d = degree
int kCount(int v, int d, int k) {
    if (d > k) return 0;
    int count = 0;
    for (int j : adj[v]) {
        count += kCount(j, d+1, k);
    }
    if (visited[v]) return count;
    visited[v] = true;
    return count + 1;
}

int main() {
    int n, e, k;
    cin >> n >> e >> k;
    adj = vector<vector<int>> (n, vector<int> (0));
    visited = vector<bool> (n, 0);
    int res = 0;
    for (int i = 0; i < e; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }
    for (int v = 0; v < n; v++) {
        res = max(res, kCount(v, 0, k));
        visited = vector<bool> (n, 0);
    }
    cout << res;
}