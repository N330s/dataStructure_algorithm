#include <iostream>
#include <set>
#include <vector>
#include <climits>

#define mp make_pair
using namespace std;

void change (set<pair<int, pair<int, int>>> &s, vector<vector<int>> &city,
vector<vector<int>>& dist, int i, int j, int t) {
    if (dist[i][j] > t + city[i][j]) {
        auto it = s.find(mp(dist[i][j], mp(i, j)));
        if (it != s.end()) s.erase(it);
        dist[i][j] = t + city[i][j];
        s.insert(mp(dist[i][j], mp(i, j)));
    }
}

int main () {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> city(r, vector<int> (c));
    set<pair<int, pair<int, int>>> s;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> city[i][j];
        }
    }
    vector<vector<int>> dist (r, vector<int> (c, INT_MAX));
    s.insert(mp(0, mp(0,0)));
    dist[0][0] = 0;
    while (!s.empty()) {
        auto min = s.begin();
        int T = min->first;
        int i = min->second.first;
        int j = min->second.second;
        s.erase(min);
        if ((j + 1) < c) change(s, city, dist, i, j+1, T);
        if ((j - 1) >= 0) change (s, city, dist, i, j-1, T);
        if ((i + 1) < r) change(s, city, dist, i+1, j, T);
        if ((i - 1) >= 0) change(s, city, dist, i-1, j, T);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}