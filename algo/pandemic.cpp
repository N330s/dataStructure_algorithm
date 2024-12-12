#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int r, c, t;
    cin >> r >> c >> t;
    vector<vector<int>> table;
    queue<pair<int, int>> q;
    table = vector<vector<int>> (r, vector<int>(c));
    int count = 0;
    int curr = 0, next = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> table[i][j];
            if (table[i][j] == 1) {
                q.push(make_pair(i, j));
                curr++;
                count ++;
            }
        }
    }
    int d = 0;
    while (!q.empty()) {
        if (curr == 0) {
            curr = next;
            next = 0;
            d++;
        }
        if (d == t) break;
        auto f = q.front();
        curr--;
        int i = f.first;
        int j = f.second;
        q.pop();
        if (i - 1 >= 0) {
            if (table[i-1][j] != 2) {
                if (table[i-1][j] == 0) {
                    count ++;
                    q.push(make_pair(i-1, j));
                    next++;
                }
                table[i-1][j] = 1;
            }
        }
        if (i + 1 < r) {
            if (table[i+1][j] != 2) {
                if (table[i+1][j] == 0) {
                    count++;
                    q.push(make_pair(i+1, j));
                    next++;
                }
                table[i+1][j] = 1;
            }
        }
        if (j + 1 < c) {
            if (table[i][j+1] != 2) {
                if (table[i][j+1] == 0) {
                    count++;
                    q.push(make_pair(i, j+1));
                    next++;
                }
                table[i][j+1] = 1;
            }
        }
        if (j - 1 >= 0) {
            if (table[i][j-1] != 2) {
                if (table[i][j-1] == 0) {
                    q.push(make_pair(i, j-1));
                    count++;
                    next++;
                }
                table[i][j-1] = 1;
            }
        }
    }
    cout << count;
}