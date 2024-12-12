#include <iostream>
#include <vector>

using namespace std;
int R, C;
vector<vector<int>> map;
vector<vector<int>> visited;
vector<vector<int>> len;

int cycle (pair<int, int> v, pair<int, int> parent, int l, int p) {
    int r = v.first;
    int c = v.second;
    int res = 0;
    if (visited[r][c] == p) return l - len[r][c];
    if (visited[r][c] != 0) return 0;
    visited[r][c] = p;
    len[r][c] = l;
    if (r - 1 >= 0) {
        int nr = r-1;
        int nc = c;
        if (nr != parent.first || nc != parent.second)
        if ((map[r][c] == 2 || map[r][c] == 3 || map[r][c] == 6) && (map[nr][nc] == 2 || map[nr][nc] == 4 || map[nr][nc] == 5)) {
            res = max(res, cycle(make_pair(nr, nc), v, l+1, p));
        }
    }
    if (c - 1 >= 0) {
        int nr = r;
        int nc = c-1;
        if (nr != parent.first || nc != parent.second)
        if ((map[r][c] == 1 || map[r][c] == 5 || map[r][c] == 6) && (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 4)) {
            res = max(res, cycle(make_pair(nr, nc), v, l+1, p));
        }
    }
    if (c + 1 < C) {
        int nr = r;
        int nc = c+1;
        if (nr != parent.first || nc != parent.second)
        if ((map[r][c] == 1 || map[r][c] == 3 || map[r][c] == 4) && (map[nr][nc] == 1 || map[nr][nc] == 5 || map[nr][nc] == 6)) {
            res = max(res, cycle(make_pair(nr, nc), v, l+1, p));
        }
    }
    if (r + 1 < R) {
        int nr = r + 1;
        int nc = c;
        if (nr != parent.first || nc != parent.second)
        if ((map[r][c] == 2 || map[r][c] == 4 || map[r][c] == 5) && (map[nr][nc] == 2 || map[nr][nc] == 3 || map[nr][nc] == 6)) {
            res = max(res, cycle(make_pair(nr, nc), v, l+1, p));
        }
    }
    return res;

}

int main() {
    cin >> R >> C;
    map = vector<vector<int>> (R, vector<int>(C));
    visited = vector<vector<int>> (R, vector<int> (C, 0));
    len = vector<vector<int>> (R, vector<int> (C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    int m = 0;
    int count = 0;
    int p = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (visited[i][j] == 0) {
                int temp = cycle(make_pair(i, j), make_pair(i, j), 0, p);
                if (temp != 0) count ++;
                m = max(m, temp);
                p++;
            }
        }
    }
    cout << count << " " << m;

}