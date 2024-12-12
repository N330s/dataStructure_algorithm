#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    vector <int> list;
    cin >> n >> m >> k; 
    while (n--) {
        int inp;
        cin >> inp;
        list.push_back(inp);
    }
    sort(list.begin(), list.end());
    while (m--) {
        int inp;
        cin >> inp;
        auto least = lower_bound(list.begin(), list.end(), inp-k);
        auto max = upper_bound(list.begin(), list.end(), inp+k);
        cout << distance(least, max) << " ";
    }
    return 0;
}