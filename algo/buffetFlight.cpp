#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int>ci(n);
    vector<int>co(n);
    set<pair<int, int>> s;
    vector<vector<int>> adj(n);
    vector<bool> visited (n, false);
    vector<int> cost(n, INT_MAX/4);
    cost[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> ci[i];
    } 
    for (int i = 0; i < n; i++) {
        cin >> co[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    s.insert(make_pair(0, 0));
    while (!s.empty()) {
        auto p = s.begin();
        int v = p->second;
        int w = p->first;
        s.erase(p);
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u] && cost[u] > cost[v] + ci[u] + co[v]) {
                auto it = s.find(make_pair(cost[u], u));
                if (it != s.end()) s.erase(it);
                cost[u] = cost[v] + ci[u] + co[v];
                s.insert(make_pair(cost[u], u));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (cost[i] == INT_MAX /4) cost[i] = -1;
        cout << cost[i] << " ";
    }

}