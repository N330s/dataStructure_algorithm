#include <iostream>
#include <vector>
#define modby 32717

using namespace std;

vector<int> c;
vector<int> a;
vector<int> r;
vector<bool> check;

int linear(int n, int k) {
    if (n < k) return a[n] % modby;
    if (check[n]) return r[n]; 
    int cal = 0;
    for (int i = 1; i <= k; i++) {
        cal += (c[i] * linear(n-i, k)) % modby;
    }
    r[n] = cal % modby;
    check[n] = true;
    return r[n];
}

int main() {
    int k, n;
    cin >> k >> n;
    r = vector<int> (n+1, 0);
    check = vector<bool> (n+1, 0);
    c = vector<int>(k+1);
    a = vector<int> (k);
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    cout << linear(n, k) ;
}