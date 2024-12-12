#include <iostream>
#include <vector>

#define modby 100000007
#define ll long long

using namespace std;
vector<vector<int>> map;
vector<vector<vector<ll>>> dp;
int R, C;

int recur (pair<int, int> p, char last) {
    int r = p.first;
    int c = p.second;
    if (r >= R || r < 0) return 0;
    if (map[r][c] == 1) return 0;
    if (c == C-1) return 1;
    if (last == 'T') {
        return (((recur(make_pair(r-1, c+1), 'X') % modby) + (recur(make_pair(r, c+1), 'Y') % modby) + (recur(make_pair(r+1, c+1), 'Z') % modby)) % modby);
    }
    if (dp[r][c][0] == -1) { // x
        dp[r][c][0] = ((recur(make_pair(r, c+1), 'Y') % modby) + (recur(make_pair(r+1, c+1), 'Z') % modby) % modby);
    }
    if (dp[r][c][2] == -1) { // z
        dp[r][c][2] = ((recur(make_pair(r-1, c+1), 'X') % modby) + (recur(make_pair(r, c+1), 'Y') % modby)) % modby;
    }
    if (dp[r][c][1] == -1) { // y
        dp[r][c][1] = ((recur(make_pair(r-1, c+1), 'X') % modby) + (recur(make_pair(r+1, c+1), 'Z') % modby)) % modby;
    }
    if (last == 'X') return dp[r][c][0] % modby;
    if (last == 'Y') return dp[r][c][1] % modby;
    if (last == 'Z') return dp[r][c][2] % modby;
}

int main() {
    cin >> R >> C;
    dp = vector<vector<vector<ll>>> (R, vector<vector<ll>>(C, vector<ll> (3, -1)));
    map = vector<vector<int>> (R, vector<int> (C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    ll result = 0;
    for (int i = 0; i < R; i++) {
        result += (recur(make_pair(i, 0), 'T') % modby);
        result %= modby;
    }

    cout << result % modby;
}