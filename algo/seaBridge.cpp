#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int R, C;
    cin >> R >> C;
    queue<pair<int, int>> q;
    vector<vector<int>> map(R, vector<int> (C));
    int curr = 0, next = 0, d = 2;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push(make_pair(i, j));
                curr++;
            }
        }
    }
    while (!q.empty()) {
        if (curr == 0) {
            curr = next;
            next = 0;
            d++;
        }
        auto b = q.front();
        int i = b.first;
        int j = b.second;
        q.pop();
        curr--;
        if (i - 1 >= 0) {
            int t = map[i-1][j];
            if (t == 2) break;
            if (t == 0) {
                map[i-1][j] = 4;
                q.push(make_pair(i-1, j));
                next++;
            }
        }
        if (i + 1 < R) {
            int t = map[i+1][j];
            if (t == 2) break;
            if (t == 0) {
                map[i+1][j] = 4;
                q.push(make_pair(i+1, j));
                next++;
            }
        }
        if (j - 1 >= 0) {
            int t = map[i][j-1];
            if (t == 2) break;
            if (t == 0) {
                q.push(make_pair(i, j-1));
                map[i][j-1] = 4;
                next++;
            }
        }
        if (j + 1 < C) {
            int t = map[i][j+1];
            if (t == 2) break;
            if (t == 0) {
                map[i][j+1] = 4;
                q.push(make_pair(i, j+1));
                next++;
            }
        }
    }
    cout << d;
}