#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m;
    vector<pair<int, int>> set;
    cin >> n >> m;
    while (n--) {
        int a, b;
        cin >> a >> b;
        set.push_back(make_pair(a, b));
    }
    sort(set.begin(), set.end());
    while (m--) {
        int a, b;
        cin >> a >> b;
        pair<int, int> key = make_pair(a, b);
        if (*lower_bound(set.begin(), set.end(), key) == key) {
            cout << "0 0 ";
        }
        else {
            auto i = upper_bound(set.begin(), set.end(), key);
            if (i == set.begin()) 
                cout << "-1 -1 ";
            else {
                i--;
                cout << (i)->first << " " << (i)->second << " ";
            }
        }
    }
}