#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main () {
    int n, e;
    cin >> n >> e;
    visited = vector<bool> (n+1, 0);
    adj = vector<vector<int>> (n+1);
    for (int i = 0; i < e; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    cout << count;
}