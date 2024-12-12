#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<string, int> vote;
    vector<int> list;
    while (n--) {
        string inp;
        cin >> inp;
        vote[inp] += 1;
    }
    for (auto &e : vote) {
        list.push_back(vote[e.first]);
    }
    sort(list.begin(), list.end(), greater<int>());
    if (k >= list.size()) {
        cout << list.back();
    }
    else {
        cout << list[k-1];
    }
}
