#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int main () {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> list(k);
    vector<int> c(n);
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);
    vector<int> cost(n, INT_MAX / 4);
    set<pair<int, int>> s;    
    for (int i = 0; i < k; i++) {
        cin >> list[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }
    for (int &i : list) {
        cost[i] = c[i];
        visited[i] = true;
        s.insert(make_pair(c[i], i));
    }
    while (!s.empty()) {
        auto p = s.begin();
        int a = p->first;
        int v = p->second;
        s.erase(p);
        for (auto& u : adj[v]) {
            if (cost[u] > a + c[u] && !visited[u]) {
                auto it = s.find(make_pair(cost[u], u));
                if (it != s.end()) s.erase(it);
                cost[u] = a + c[u];
                s.insert(make_pair(cost[u], u));
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, cost[i]);
    }
    cout << res;
}