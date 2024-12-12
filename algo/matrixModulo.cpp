#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define ll long long

unordered_map<int, vector<int>> dp;
ll k;

vector<int> mat (ll n) {
    if (dp[n].size() == 4) return dp[n];
    ll i = n / 2;
    ll j = n - i;
    vector<int> a = mat(i);
    vector<int> b = mat(j);
    dp[n].push_back((a[0] * b[0] + a[1] * b[2]) % k);
    dp[n].push_back((a[0] * b[1] + a[1] * b[3]) % k);
    dp[n].push_back((a[2] * b[0] + a[3] * b[2]) % k);
    dp[n].push_back((a[2] * b[1] + a[3] * b[3]) % k);
    return dp[n];
}

int main() {
    ll n;
    cin >> n >> k;
    dp[1] = vector<int> (4);
    cin >> dp[1][0] >> dp[1][1] >> dp[1][2] >> dp[1][3]; 
    vector<int> result = mat(n);
    for (int i = 0; i < 4; i++) {
        cout << result[i] << " ";
    }
}