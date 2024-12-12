#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    vector<ll> money(1e5);
    while (n--) {
        int a, s;
        cin >> a >> s;
        money[a] = s;
    }
    int currMoney = start;
    for (int i = 0; i < 1e5; i++) {
        if (money[i] != 0) {
            currMoney = money[i];
        }
        if (i == 0) {
            money[i] = currMoney;
            continue;
        }
        money[i] = money[i-1] + currMoney;
    }
    while (m--) {
        int p, x;
        cin >> p >> x;
        auto a = lower_bound(money.begin(), money.end(), p);
        if (a - money.begin() <= x) {
            cout << a-money.begin() << " ";
        }
        else {
            auto b = lower_bound(money.begin(), money.end(), p+money[x]);
            cout << b-money.begin() << " ";
        }
    }
}