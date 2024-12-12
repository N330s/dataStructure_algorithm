#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> degree;

int cycle(int v, int parent, int k) {
    if (visited[v]) return k - degree[v];
    int count = 0;
    visited[v] = true;
    degree[v] = k;
    for (int i : adj[v]) {
        if (i != parent) {
            count = max(count, cycle(i, v, k+1));
            if (count != 0) return count;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    adj = vector<vector<int>> (n);    
    visited = vector<bool> (n, false);
    degree = vector<int> (n, 0);
    for (int i = 0; i < n; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }
    cout << cycle(0, 0, 0);
}