#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector <pair<int, int>> data (n);
    vector<int> times(n);
    for (int i = 0 ; i < n; i++) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        data[i] = make_pair(inp1, inp2);
    }
    sort(data.begin(), data.end());
    times[0] = data[0].second;
    for (int i = 1 ; i < n; i++) {
        times[i] = times[i-1] + data[i].second;
    }
    while (q--) {
        int inp;
        cin >> inp;
        auto it = lower_bound(times.begin(), times.end(), inp);
        int idx = it - times.begin();
        cout << data[idx].first << endl;
    }
}