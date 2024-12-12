#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> color;
vector<vector<int>> adj;
vector<bool> visited;
int maxx = 0;
int n, e;

void Color(int v) {
    visited[v] = true;
    vector<bool> c (n, false);
    for (int& u : adj[v]) {
        if (color[u] == -1) continue;
        c[color[u]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!c[i]) {
            color[v] = i;
            maxx = max(maxx, i);
            break;
        }
    }
}

int main() {
    cin >> n >> e;
    queue<int> q;
    adj = vector<vector<int>>(n);
    color = vector<int>(n, -1);
    visited = vector<bool> (n, false);
    for (int i = 0; i < e; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }
    q.push(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int& u : adj[v]) {
            if (!visited[u]) {
                Color(u);
                q.push(u);
            }
        } 
    }
    cout << maxx + 1;
}