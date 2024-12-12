#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int count = 0;
        for (int j : data) {
            if (j == k) break;
            if (j > k) count++;
        }
        cout << count << endl;
    }
}