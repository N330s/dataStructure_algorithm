#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
    vector<vector<pair<int, int>>> adj;
    int n;
    cin >> n;
    vector<int> cost (n, INT_MAX);
    vector<bool> used (n, false);
    set<pair<int, int>> s;
    adj = vector<vector<pair<int, int>>> (n);
    for(int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int inp;
            cin >> inp;
            adj[i].push_back(make_pair(inp, j));
            adj[j].push_back(make_pair(inp, i));
        }
    }
    used[0] = true;
    s.insert(make_pair(0, 0));
    int count = 0;
    while (!s.empty()) {
        auto min = s.begin();
        int c = min->first;
        int u = min->second;
        count += c;
        used[u] = true;
        s.erase(s.begin());
        for (auto& a : adj[u]) {
            if (cost[a.second] > a.first && !used[a.second]) {
                auto it = s.find((make_pair(cost[a.second], a.second)));
                if (it != s.end()) s.erase(it);
                cost[a.second] = a.first;
                s.insert(a);
            }
        }
    }
    cout << count;
}