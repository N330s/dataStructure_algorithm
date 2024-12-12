#include <iostream>
#include <set>

using namespace std;
    
set<int> result;

void bfs(int n, int a) {
    if ((2*a + 1) >= n) {
        return;
    }
    result.insert(2*a + 1);
    if ((2*a + 2) >= n) {
        return;
    }
    result.insert(2*a + 2);
    bfs(n, 2*a + 1);
    bfs(n, 2*a + 2);
}

int main() {
    int n, a;
    cin >> n >> a;
    bfs(n, a);
    cout << result.size() + 1 << endl << a << " ";
    for (auto i = result.begin(); i != result.end(); i++) {
        cout << *i << " ";
    }
}