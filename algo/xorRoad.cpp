#include <iostream>
#include <vector>
#include <set>

#define ll long long
using namespace std;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int> &b) const {
        return a > b;
    }
};

int main() {
    int n; 
    cin >> n;
    vector<unsigned ll> code(n);
    vector<unsigned ll> val(n, 0);
    vector<bool> used(n, false);
    set<pair<unsigned ll, int>, comp> s;
    for (int i = 0; i < n; i++) { 
        cin >> code[i];
    }
    s.insert(make_pair(0, 0));
    unsigned ll count = 0;
    while (!s.empty()) { 
        auto fr = s.begin();
        int u = fr->second; //node
        int k = fr->first; //beauty number
        count += k; 
        s.erase(fr);
        used[u] = true;
        for (int i = 0; i < n; i++) {
            if (((code[u] ^ code[i]) > val[i]) && !used[i]) {
                auto it = s.find(make_pair(val[i], i));
                if (it != s.end()) s.erase(it);
                val[i] = (code[u] ^ code[i]);
                s.insert(make_pair(val[i], i));
            }
        }
    }
    cout << count;
}