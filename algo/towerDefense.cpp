#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void recur(vector<vector<int>>& able, int n, vector <int> &shotted, vector<int> &h, int& best) {
    if (n == able.size()) {
        int result = 0;
        for (int i = 0; i < shotted.size(); i++) {
            result += max(h[i] - shotted[i], 0);
            shotted[i] = 0;
        }
        best = min (best, result);
        return;
    }
    if (able[n].size() == 0) {
        recur (able, n+1, shotted, h, best);
    }
    for (int &j : able[n]) {
        shotted[j] += 1;
        recur (able, n+1, shotted, h, best);
    }
}

int main() {
    int n, m, k, w;
    int best = 1e9;
    cin >> n >> m >> k >> w;
    vector <int> p(m, 0);
    vector <int> t(k, 0);
    vector <int> h(m, 0);
    vector <vector<int>> able(k);
    vector <int> shotted(m, 0);
    for (int i = 0; i < m; i++) {
        int inp;
        cin >> inp;
        p[i] = inp;
    }
    for (int i = 0; i < m; i++) {
        int inp;
        cin >> inp;
        h[i] = inp;
    }
    for (int i = 0; i < k; i++) {
        int inp;
        cin >> inp;
        t[i] = inp;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(p[j] - t[i]) <= w) {
                able[i].push_back(j);
            }
        }
    }
    recur(able, 0, shotted, h, best);
    cout << best;
}