#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int>& vec, int &q, int start, int stop) {
    if (start == stop) return (vec[start] <= q) ? vec[start] : -1;
    int m = (start + stop) >> 1;
    if (vec[m+1] > q) return bs(vec, q, start, m);
    return bs(vec, q, m+1, stop);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    while(m--) {
        int q;
        cin >> q;
        cout << bs(vec, q, 0, vec.size()-1) << endl;
    }
}
