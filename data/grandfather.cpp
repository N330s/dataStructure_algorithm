#include <iostream>
#include <unordered_map>

#define ll long long

using namespace std;

int main() {

    unordered_map<ll, ll> father;
    int n, m;
    cin >> n >> m;
    while (n--) {
        ll f, s;
        cin >> f >> s;
        father[s] = f;
    }
    while (m--) {
        ll a, b;
        cin >> a >> b;
        if ((father[father[a]] == father[father[b]]) && a != b && father[father[a]] != 0 && father[father[b]] != 0) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}