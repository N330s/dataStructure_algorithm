#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long r, c, k;
    vector<pair<long long, long long>> fav;
    cin >> r >> c >> k;
    while (k--) {
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        fav.push_back(make_pair(temp1, temp2));
    }
    sort(fav.begin(), fav.end());
    long long q;
    cin >> q;
    while (q--) {
        long long inp1, inp2;
        cin >> inp1 >> inp2;
        auto it = lower_bound(fav.begin(), fav.end(), make_pair(inp1, inp2));
        if (!(it->first < inp1 || (it->second < inp2 && it->first == inp1))) {
            long long count = 0;
            count += (c - inp2);
            count += (c* (it->first - inp1 - 1));
            count += it->second;
            cout << count << endl;
        }
        else {
            long long count = 0;
            count += (c - inp2);
            count += (c* (r - inp1));
            count += (c* (fav.begin()->first - 1));
            count += fav.begin()->second;
            cout << count << endl;
        }
    }
}