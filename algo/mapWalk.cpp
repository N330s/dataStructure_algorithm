#include <iostream>
#include <vector>

using namespace std;
vector<vector<bool>> table;
vector<vector<bool>> visited;
int R, C;

void walk(const string& s, int r, int c) {
    if (r == R-1 && c == C-1) {
        cout << s << "\n";
    }
    if (c+1 < C && !table[r][c+1] && !visited[r][c+1]) {
        visited[r][c+1] = true;
        walk(s + "A", r, c+1);
        visited[r][c+1] = false;
    }
    if (r+1 < R && !table[r+1][c] && !visited[r+1][c]) {
        visited[r+1][c] = true;
        walk(s + "B", r+1, c);
        visited[r+1][c] = false;
    }
    if (r-1 >= 0 && !table[r-1][c] && !visited[r-1][c]) {
        visited[r-1][c] = true;
        walk(s + "C", r-1, c);
        visited[r-1][c] = false;
    }
}

int main() {
    cin >> R >> C;
    table = vector<vector<bool>> (R, vector<bool> (C));
    visited = vector<vector<bool>> (R, vector<bool> (C, false));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            bool inp;
            cin >> inp;
            table[i][j] = inp;
        }
    }
    visited[0][0] = true;
    walk("", 0, 0);
    cout << "DONE";

}