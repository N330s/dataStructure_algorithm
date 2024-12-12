#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define modby 1000003

vector<ll> set;
vector<ll> table;
int n, k;

ll way(ll left) {
    if (left == 1) return 1;
    if (left == 0) return 1;
    if (table[left] != 0) return table[left];
    ll count = 0;
    for (int i = 0; i < k; i++) {
        if (left - set[i] >= 0) {
            count = (count + way(left-set[i]) % modby) % modby;
        }
    }
    table[left] = count;
    return table[left];
}

int main() {
    cin >> n >> k;
    table = vector<ll>(n+1, 0);
    set.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> set[i];
    }
    cout << way(n);
}