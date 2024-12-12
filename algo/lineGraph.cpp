#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool linear(int v, int parent) {
    visited[v] = true;
    bool ch = true;
    if (adj[v].size() > 2) return false;
    for (int i : adj[v]) {
        if (!visited[i]) {
            ch = ch &&  linear(i, v);
        }
        else if (parent != i) ch = false;
    }
    return ch;
}

int main () {
    int n, e;
    cin >> n >> e;
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n, 0);
    for (int i = 0; i < e; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1); 
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (linear(i, i)) count++;
        }
    }
    cout << count;
}