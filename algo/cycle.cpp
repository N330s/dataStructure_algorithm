#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool check (int v, int parent) {
    visited[v] = true;
    bool ch = false;
    for (int i : adj[v]) {
        if (!visited[i]) {
            ch = ch || check(i, v);
        }
        else if (i != parent)return true;
    }
    return ch;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
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
        bool ch = false;
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                ch = ch || (check (v, v));
            } 
        }
        if (ch) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}