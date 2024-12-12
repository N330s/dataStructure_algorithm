#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void recur(vector<vector<int>>& v, int r, int c, int m, int b) {
    if (m == 0) {
        v[r][c] = b;
        return;
    } 
    recur (v, r, c, m/2, b);
    recur (v, r + (m / 2), c, m/2, b+1);
    recur (v, r, c + (m/2), m/2, b-1);
    recur (v, r + (m/2), c + (m/2), m/2, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    int size = pow(2, a);
    vector<vector<int>> v (size, vector<int> (size, 0));
    recur (v, 0, 0, size, b);
    for (auto& i : v) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}