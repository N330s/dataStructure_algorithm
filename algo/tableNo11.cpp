#include <iostream>
#include <vector>

#define ll long long
#define modwith 100000007

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> table (3, 1);
    for (int i = 2; i <= n; i++) {
        ll temp0 = table[0];
        ll temp1 = table[1];
        table[0] = (table[0] + table[1] + table[2]) % modwith;
        table[1] = (temp0 + table[2]) % modwith;
        table[2] = (temp0 + temp1) % modwith;
    }
    cout << (table[0] + table[1] + table[2]) % modwith;
}