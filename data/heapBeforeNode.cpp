#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> set;

void recur(int a, int n){
    if (a >= n) return;
    set.insert(a);
    recur(2*a + 1, n);
    recur(2*a + 2, n);
}

int main() {
    int n, m;
    cin >> n >> m;
    recur(m, n);
    cout << n - set.size() << endl;
    for (int i = 0; i < n; i++) {
        if (set.find(i) == set.end()) {
            cout << i << " ";
        }
    }
}