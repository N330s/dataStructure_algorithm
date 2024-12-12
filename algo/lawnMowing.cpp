#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v (n+1, 0);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1] + k;
    }
    while (m--) {
        ll a, b;
        cin >> a >> b;
        auto it = upper_bound(v.begin(), v.end(), b+v[a]);
        if (it == v.begin() + 1) {
            cout << 0 << "\n";
            continue;
        }
        it--;
        cout << *it - v[a] - ((it - v.begin() - a) * k) << '\n';
    }
}