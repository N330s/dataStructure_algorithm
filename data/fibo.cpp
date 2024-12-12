#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int table[1000] = {0};
    table[0] = 1;
    table[1] = 1;
    for (int i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    cout << table[n-1];
}