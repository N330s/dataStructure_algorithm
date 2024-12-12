#include <iostream>
#include <vector>
#include <climits>

#define ll long long
using namespace std;

int main() {
    int n, e, s;
    cin >> n >> e >> s;
    vector<vector<pair<int, int>>> adj(n);
    vector<ll> dist(n, INT_MAX);
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }
    dist[s] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int v = 0; v < n; v++) {
            for (auto e : adj[v]) {
                if (dist[e.first] > dist[v] + e.second) {
                    dist[e.first] = dist[v] + e.second;
                }
            }
        }
    }
    for (int v = 0; v < n; v++) {
        for (auto e : adj[v]) {
            if (dist[e.first] > dist[v] + e.second) {
                cout << -1;
                return 0;
            }
        }
    }
    for (int v = 0; v < n; v++) {
        cout << dist[v] << " ";
    }

}